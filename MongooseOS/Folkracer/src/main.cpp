/*
 *
 */

#include "mgos.h"
#include "motor.hpp"
#include "gp2y0e02b.hpp"
#include "startmodule.hpp"
#include "carstate.hpp"
#include "tca9548.hpp"
#include "tmp102.hpp"

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

#define GPIO_PIN_26  26
#define GPIO_PIN_STARTMODULE_SIGNAL  27
#define GPIO_PIN_LED 23
#define TCA9548_I2C_ADDRESS 0x999
#define TMP102_I2C_ADDRESS 0x48

void toggle_led_cb(int pin, void *arg) {
  //mgos_gpio_write(23, true);
  LOG(LL_INFO, ("Interrupt triggered on pin %d", pin));
  mgos_gpio_toggle(GPIO_PIN_LED);
  (void) arg;
}

void led_blink_cb(void * arg) {
  mgos_gpio_toggle(GPIO_PIN_LED);
  (void) arg;
}

void read_temperature_cb(void * arg) {
  
  //TMP102 temperature sensor
  Sensor::TMP102 * tmp102;
  //tmp102 = new Sensor::TMP102(TMP102_I2C_ADDRESS);
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

//void carstate_cb(void * arg) {
//  CarState * carstate = reinterpret_cast<CarState*>(arg);
//  LOG(LL_INFO, ("Carstate.count=%d", carstate->count));
//}

/*
void startmoduleChangedEvent(void * arg) {
  LOG(LL_INFO, ("Startmodule event raised"));
}
*/

enum mgos_app_init_result mgos_app_init(void) {

  mgos_gpio_set_mode(GPIO_PIN_LED, MGOS_GPIO_MODE_OUTPUT);
  //std::thread led_thread(turn_on_led);
  //led_thread.join();

  //Testing configuration
  //LOG(LL_INFO, ("Hello, %s", mgos_sys_config_get_hello_who()));
  //const char * world = mgos_sys_config_get_hello_who();

  //Listen for Startmodule interrupt
  //int pin = mgos_sys_config_get_ghost32_startmodule_signal_gpio();
  Sensor::StartModule * _startmodule;
  _startmodule = new Sensor::StartModule(GPIO_PIN_STARTMODULE_SIGNAL);
  _startmodule->initialize();
  //start_module.disable();
  //start_module.powercycle();
  //start_module.get_current_state();

  //std::vector<Sensor::GP2Y0E02B> irsensors;
  //irsensors.reserve(3);
  //irsensors.push_back()


  int sensor_count = 8;
  Sensor::GP2Y0E02B **sensors = new Sensor::GP2Y0E02B*[sensor_count];
  for (int i=0; i < sensor_count; i++) {
    sensors[i] = new Sensor::GP2Y0E02B();
  }

  //I2C multiplexer
  Sensor::TCA9548 * tca9548;
  tca9548 = new Sensor::TCA9548(TCA9548_I2C_ADDRESS);
  if (tca9548->detect_device()) {
    LOG(LL_INFO, ("Success, found TCA9548"));
    for (int i = 0; i < 8; i++) {
      LOG(LL_INFO, ("Setting channel to %d", i));
      tca9548->set_channel(i);
      int activechannel = tca9548->get_channel();
      LOG(LL_INFO, ("Active channel is %d", activechannel));
    }
  } else {
    LOG(LL_ERROR, ("Unable to detect TCA9548"));
  }

/*  //TMP102 temperature sensor
  Sensor::TMP102 * tmp102;
  tmp102 = new Sensor::TMP102(TMP102_I2C_ADDRESS);
  float temperature = tmp102->readTemperature();
  g_carstate->temperature = temperature;
*/
  mgos_set_timer(1*1000, 1, print_carstate_cb, NULL);
  mgos_set_timer(.5*1000, 1, read_temperature_cb, NULL);
  mgos_set_timer(1*1000, 1, led_blink_cb, NULL);
//  mgos_set_timer(5*1000, 1, carstate_cb, g_carstate);

  //Hook up timers
  //mgos_set_timer(200, )

  //Playing around with JSON  
  //https://github.com/cesanta/frozen
  /*int a = 0;
  const char * json = "{\"a\":123, \"b\":\"hallo\"}";
  int r = json_scanf(json, strlen(json), "{a:%d}", &a);
  LOG(LL_INFO, ("a is %d", a));
  (void)r;
  */

  // struct driver {
  //   int wheels = 4;
  //   int gears = 7;
  // };

  // printf("TESTING printf");

  

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
  steering = new Actuators::Motor(GPIO_PIN_26);

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

  // Sensor::GP2Y0E02B irsensor;
  // int distance = irsensor.getDistance();
  // LOG(LL_INFO, ("Distance: %d", distance));

  return MGOS_APP_INIT_SUCCESS;
}
