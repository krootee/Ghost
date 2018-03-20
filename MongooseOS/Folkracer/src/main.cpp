/*
 *
 */

#include "mgos.h"
#include "motor.hpp"
#include "gp2y0e02b.hpp"
#include "startmodule.hpp"

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

enum mgos_app_init_result mgos_app_init(void) {

  mgos_gpio_set_mode(GPIO_PIN_LED, MGOS_GPIO_MODE_OUTPUT);
  //std::thread led_thread(turn_on_led);
  //led_thread.join();

  //mgos_gpio_set_int_handler(4, MGOS_GPIO_INT_EDGE_ANY, toggle_led_cb, null);
  //mgos_gpio_enable_int(4);

  //Listen for Startmodule interrupt
  //LOG(LL_INFO, ("Attaching interrupt handler for startmodule"));
  //mgos_gpio_set_mode(GPIO_PIN_STARTMODULE_SIGNAL, MGOS_GPIO_MODE_INPUT);
  //mgos_gpio_set_int_handler(GPIO_PIN_STARTMODULE_SIGNAL, MGOS_GPIO_INT_EDGE_ANY, toggle_led_cb, NULL);
  //bool interrupt = mgos_gpio_enable_int(GPIO_PIN_STARTMODULE_SIGNAL);
  //if (interrupt)
//    LOG(LL_INFO, ("Interrupt attached to pin %d", GPIO_PIN_STARTMODULE_SIGNAL));
//  else
    //LOG(LL_INFO, ("Interrupt NOT attached!"));

  Sensor::StartModule start_module(GPIO_PIN_STARTMODULE_SIGNAL);
  start_module.initialize();
  //start_module.disable();
  //start_module.powercycle();
  //start_module.get_current_state();

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
