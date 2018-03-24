/*
 *
 */

#include "mgos.h"
#include "motor.hpp"
#include "gp2y0e02b.hpp"
#include "startmodule.hpp"
#include "carstate.hpp"

#include <iostream>
#include <chrono>
#include <thread>

#define GPIO_PIN_26  26
#define GPIO_PIN_STARTMODULE_SIGNAL  27
#define GPIO_PIN_LED 23

void toggle_led_cb(int pin, void *arg) {
  //mgos_gpio_write(23, true);
  LOG(LL_INFO, ("Interrupt triggered on pin %d", pin));
  mgos_gpio_toggle(GPIO_PIN_LED);
  (void) arg;
}

void timer_cb(void * arg) {

  Sensor::StartModule * startmodule = reinterpret_cast<Sensor::StartModule*>(arg);

  LOG(LL_INFO, ("[TICK] Count: %d", startmodule->get_count()));
}

void carstate_cb(void * arg) {
  CarState * carstate = reinterpret_cast<CarState*>(arg);
  LOG(LL_INFO, ("Carstate.count=%d", carstate->count));
}

enum mgos_app_init_result mgos_app_init(void) {

  mgos_gpio_set_mode(GPIO_PIN_LED, MGOS_GPIO_MODE_OUTPUT);
  //std::thread led_thread(turn_on_led);
  //led_thread.join();

  //Listen for Startmodule interrupt
  Sensor::StartModule * _startmodule;
  _startmodule = new Sensor::StartModule(GPIO_PIN_STARTMODULE_SIGNAL);
  _startmodule->initialize();
  //start_module.disable();
  //start_module.powercycle();
  //start_module.get_current_state();

  mgos_set_timer(5*1000, 1, timer_cb, _startmodule);
  mgos_set_timer(5*1000, 1, carstate_cb, g_carstate);

  //Playing around with JSON
  //https://github.com/cesanta/frozen
  int a = 0;
  const char * json = "{\"a\":123, \"b\":\"hallo\"}";
  int r = json_scanf(json, strlen(json), "{a:%d}", &a);
  LOG(LL_INFO, ("a is %d", a));
  (void)r;

  struct car {
    int wheels = 4;
    int gears = 7;
  };

  printf("testign printf");

  //car c;
  //c.wheels = 5;
  //c.gears = 8;
  char str_out[256];
  struct json_out out = JSON_OUT_BUF(str_out, sizeof(str_out));
  //json_printf(&out, "{wheels: %M}", c);
  json_printf(&out, "{count: %d}", g_carstate->count);
  LOG(LL_INFO, ("str_out=%s", str_out));

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
  //Actuators::Motor steering(GPIO_PIN_26);

  // while (true) {
  //   steering.setDesiredSpeed(0.075);
  //   std::this_thread::sleep_for(std::chrono::milliseconds(2000));

  //   steering.setDesiredSpeed(0.05);
  //   std::this_thread::sleep_for(std::chrono::milliseconds(2000));

  //   steering.setDesiredSpeed(0.10);
  //   std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  // }

  // Sensor::GP2Y0E02B irsensor;
  // int distance = irsensor.getDistance();
  // LOG(LL_INFO, ("Distance: %d", distance));

  return MGOS_APP_INIT_SUCCESS;
}
