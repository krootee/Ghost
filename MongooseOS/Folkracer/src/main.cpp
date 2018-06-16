/*
 *
 */

#include "mgos.h"
#include "mgos_system.h"
#include "mgos_rpc.h"

#include "motor.hpp"
#include "gp2y0e02b.hpp"
#include "startmodule.hpp"
#include "carstate.hpp"
#include "tca9548.hpp"
#include "tmp102.hpp"
#include "xc10aesc.cpp"
#include "point.cpp"
#include "mpu9250.hpp"

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

#define GPIO_PIN_STEERING 26
#define GPIO_PIN_STARTMODULE_SIGNAL 25
#define GPIO_PIN_STARTMODULE_VCC 13
#define GPIO_PIN_LED 23
#define GPIO_PIN_BUTTON 18
#define GPIO_PIN_MOTOR 27
#define I2C_ADDRESS_TCA9548 0x70
#define I2C_ADDRESS_TMP102 0x48
#define I2C_ADDRESS_MPU9250 0x69

/*
void toggle_led_cb(int pin, void *arg) {
  LOG(LL_INFO, ("Interrupt triggered on pin %d", pin));
  mgos_gpio_toggle(GPIO_PIN_LED);
  (void) arg;
}
*/

void led_blink_cb(void * arg) {
  mgos_gpio_toggle(GPIO_PIN_LED);
  (void) arg;
}

void read_temperature_cb(void * arg) {
  
  //TMP102 temperature sensor
  Sensor::TMP102 * tmp102;
  //tmp102 = new Sensor::TMP102(I2C_ADDRESS_TMP102);
  tmp102 = new Sensor::TMP102();
  if (tmp102->detect_device())
  {
    float temperature = tmp102->read_temperature();
    g_carstate->temperature = temperature;
  } else {
    LOG(LL_ERROR, ("Unable to detect TMP102 device."));
  }
  
  (void) arg;
}

void print_carstate_cb(void * arg) {
  //Print out carstate as JSON
  char json[256];
  struct json_out out = JSON_OUT_BUF(json, sizeof(json));
  json_printf(&out, "{temperature: %.2f, startmodule: %d}", g_carstate->temperature, g_carstate->startmodule);
  LOG(LL_INFO, ("state = %s", json));
}

void button_pressed_cb(int pin, void * arg) {
  LOG(LL_INFO, ("Button click!"));
  (void) arg;
}

void read_irsensors(void * arg) {

  double start = mg_time();

  //I2C multiplexer
  Sensor::TCA9548 * tca9548;
  tca9548 = new Sensor::TCA9548(I2C_ADDRESS_TCA9548);
  if (tca9548->detect_device()) {
    //LOG(LL_INFO, ("Success, found TCA9548"));

    //Loop over the channels in the multiplexer
    for (int i = 0; i < 8; i++) {
      //LOG(LL_INFO, ("Setting channel to %d", i));
      //Set the channel
      if (!tca9548->set_channel(1 << i))
        LOG(LL_WARN, ("Unable to set channel to %d", i));
      int activechannel = tca9548->get_channel();

      //Get sensor data
      Sensor::GP2Y0E02B * irsensor = new Sensor::GP2Y0E02B();
      if (irsensor->detect_device()) {
        int distance = irsensor->get_distance();
        //LOG(LL_INFO, ("Active channel is %d, distance: %d", activechannel, distance));
        g_carstate->sensor_available[i] = true;
        g_carstate->sensor_reading[i] = distance;
      } else {
        g_carstate->sensor_available[i] = false;
      }

      delete irsensor;
    }
  } else {
    LOG(LL_ERROR, ("Unable to detect TCA9548"));
  }

  delete tca9548;

  //double delta = (mg_time() - start) * 1000.0;
  //LOG(LL_INFO, ("IRSensors read in %.2f milliseconds", delta));

  //mgos_wdt_feed(); //Feed the watchdog timer to avoid crashes.

  (void) arg;
}

//This method is the one responsible to assessing the read sensors,
//figure out where to go, and write the desired direction to the car_state
void driver_cb(void * arg) {

  //TODO!

  //Look at the aquired sensor readings
  int sensor7_distance = g_carstate->sensor_reading[7];
  int sensor3_distance = g_carstate->sensor_reading[3];

  PointFloat sensor7Offset(-4.0, 2.0);
  PointFloat sensor3Offset(2.0, -2.0);

  PointFloat sensor7(sensor7_distance*1.0, 0.0);
  sensor7.rotate(45); //Ca value!

  PointFloat sensor3(sensor3_distance*1.0, 0.0);
  sensor3.rotate(60); //Ca value!

  PointFloat wall7 = sensor7 + sensor7Offset;
  PointFloat wall3 = sensor3 + sensor3Offset;
  //LOG(LL_INFO, ("Wall7: [%.2f, %.2f]", wall7.x, wall7.y));
  //LOG(LL_INFO, ("Wall3: [%.2f, %.2f]", wall3.x, wall3.y));

  PointFloat wall = wall3.subtract(wall7);
  LOG(LL_INFO, ("Angle to wall: %.2f", wall.angle()));


  //Do math

  //Control the actuators
}

//void carstate_cb(void * arg) {
//  CarState * carstate = reinterpret_cast<CarState*>(arg);
//  LOG(LL_INFO, ("Carstate.count=%d", carstate->count));
//}

/*
void startmoduleChangedEvent(void * arg) {
  LOG(LL_INFO, ("Startmodule event raised"));
}
*/

//Handler for RPC calls to "Car.Drive"
//Expects JSON like {angle: 13, speed: 30 }
//https://forum.mongoose-os.com/discussion/2408/creating-a-rest-server
//https://mongoose-os.com/docs/quickstart/prog2.md
static void rpc_call_car_drive(struct mg_rpc_request_info *ri, void *cb_arg, struct mg_rpc_frame_info *fi, struct mg_str args) {
  int angle = -1;
  int speed = -1;

  json_scanf(args.p, args.len, ri->args_fmt, &angle, &speed); //Get the values from the incoming JSON structure.
  if (angle < 0 || speed < 0) {
    //Either angle or speed was not given. Return an error.
    mg_rpc_send_errorf(ri, 400, "Invalid or missing parameters");
    return;
  }

  //TODO - do something
  LOG(LL_INFO, ("Got angle = %d, and speed = %d", angle, speed));

  //Send response
  int value = 42;
  mg_rpc_send_responsef(ri, "{value: %d}", value);

  (void)cb_arg;
  (void)fi;
}

static void rpc_car_get_state(struct mg_rpc_request_info *ri, void *cb_arg, struct mg_rpc_frame_info *fi, struct mg_str args) {

  //Get the Carstate
  char json[256];
  struct json_out out = JSON_OUT_BUF(json, sizeof(json));
  json_printf(&out, "{temperature: %.2f, startmodule: %d}", g_carstate->temperature, g_carstate->startmodule);
  LOG(LL_INFO, ("state = %s", json));

  //Return it as JSON
  mg_rpc_send_responsef(ri, "%s", json);

  (void) cb_arg;
  (void) fi;
}

enum mgos_app_init_result mgos_app_init(void) {

  mgos_gpio_set_mode(GPIO_PIN_LED, MGOS_GPIO_MODE_OUTPUT);
  //std::thread led_thread(turn_on_led);
  //led_thread.join();

  //Initialize the Electronic Speed Control
//  Actuators::xc10aesc * _esc;
//  _esc = new Actuators::xc10aesc(GPIO_PIN_MOTOR);
//  _esc->calibrate();

  //Turn ON the Accelerometer/Gyro/Compass
  Sensor::MPU9250 * mpu9250;
  mpu9250 = new Sensor::MPU9250(I2C_ADDRESS_MPU9250);
  mpu9250->enable();
  //xyz data = mpu9250->read_compass();

  //Set up RPC/JSON/REST server
  struct mg_rpc *rpc = mgos_rpc_get_global();
  mg_rpc_add_handler(rpc, "Car.Drive", "{angle: %d, speed: %d}", rpc_call_car_drive, NULL);
  mg_rpc_add_handler(rpc, "Car.GetState", "", rpc_car_get_state, NULL);

  //Listen for Startmodule interrupt
  //int pin = mgos_sys_config_get_ghost32_startmodule_signal_gpio();
  Sensor::StartModule * _startmodule;
  _startmodule = new Sensor::StartModule(GPIO_PIN_STARTMODULE_SIGNAL, GPIO_PIN_STARTMODULE_VCC);
  _startmodule->initialize();
  //start_module.disable();
  //start_module.powercycle();
  //start_module.get_current_state();

  //std::vector<Sensor::GP2Y0E02B> irsensors;
  //irsensors.reserve(3);
  //irsensors.push_back()

//  int sensor_count = 8;
//  Sensor::GP2Y0E02B **sensors = new Sensor::GP2Y0E02B*[sensor_count];
//  for (int i=0; i < sensor_count; i++) {
//    sensors[i] = new Sensor::GP2Y0E02B();
//  }



  //Hook up timers to regularly call methods.
  //mgos_set_timer(1*1000, 1, print_carstate_cb, NULL);
  mgos_set_timer(.5*1000, 1, read_temperature_cb, NULL);
  mgos_set_timer(0.2*1000, 1, read_irsensors, NULL);
  mgos_set_timer(0.2*1000, 1, led_blink_cb, NULL);
  mgos_set_timer(0.5*1000, 1, driver_cb, NULL);
//  mgos_set_timer(5*1000, 1, carstate_cb, g_carstate);

  //Hook up button on the Ghost32 Shield.
  mgos_gpio_set_button_handler(GPIO_PIN_BUTTON, MGOS_GPIO_PULL_UP, MGOS_GPIO_INT_EDGE_NEG, 50, button_pressed_cb, NULL);

  //Playing around with JSON  
  //https://github.com/cesanta/frozen
  /*int a = 0;
  const char * json = "{\"a\":123, \"b\":\"hallo\"}";
  int r = json_scanf(json, strlen(json), "{a:%d}", &a);
  LOG(LL_INFO, ("a is %d", a));
  (void)r;
  */ 

/*
  while (_startmodule->get_current_state() == Sensor::startmodule_state::ready)
  {
    int c = _startmodule->get_count();
    LOG(LL_INFO, ("Ready %d...", c));
  }

  while (_startmodule->get_current_state() == Sensor::startmodule_state::started)
  {
    int c = _startmodule->get_count();
    LOG(LL_INFO, ("Started...%d", c));
  }

  while (_startmodule->get_current_state() == Sensor::startmodule_state::stopped)
  {
    LOG(LL_INFO, ("Stopped"));
  }
*/
  Actuators::Motor * steering;
  steering = new Actuators::Motor(GPIO_PIN_STEERING);

/*  while (true) {
    steering->setDesiredSpeed(0.075);
    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    steering->setDesiredSpeed(0.05);
    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    steering->setDesiredSpeed(0.075);
    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    steering->setDesiredSpeed(0.10);
    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    mgos_wdt_feed(); //Feed the watchdog so that it doesn't crash after 30 seconds.
  }
*/

  return MGOS_APP_INIT_SUCCESS;
}
