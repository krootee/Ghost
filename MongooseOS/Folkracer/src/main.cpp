/*
 *
 */

#include "mgos.h"
#include "motor.hpp"
#include "gp2y0e02b.hpp"

#include <iostream>
#include <chrono>
#include <thread>

#define GPIO_PIN_26  26

void turn_on_led() {
  mgos_gpio_set_mode(23, MGOS_GPIO_MODE_OUTPUT);
  mgos_gpio_write(23, true);
}

enum mgos_app_init_result mgos_app_init(void) {

  std::thread led_thread(turn_on_led);
  led_thread.join();

  Actuators::Motor steering(GPIO_PIN_26);

  while (true) {
    steering.setDesiredSpeed(0.075);
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    steering.setDesiredSpeed(0.05);
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    steering.setDesiredSpeed(0.10);
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  }

  Sensor::GP2Y0E02B irsensor;
  int distance = irsensor.getDistance();
  LOG(LL_INFO, ("Distance: %d", distance));

  return MGOS_APP_INIT_SUCCESS;
}
