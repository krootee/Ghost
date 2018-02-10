/*
 *
 */

#include "mgos.h"
#include "motor.hpp"
#include "gp2y0e02b.hpp"

#include <thread>

#define GPIO_PIN_26  26

void turn_on_led() {
  mgos_gpio_set_mode(23, MGOS_GPIO_MODE_OUTPUT);
  mgos_gpio_write(23, true);
}

enum mgos_app_init_result mgos_app_init(void) {

  std::thread led_thread(turn_on_led);
  led_thread.join();

  Actuators::Motor motor(GPIO_PIN_26);
  motor.setDesiredSpeed(50);

  Sensor::GP2Y0E02B irsensor;
  int distance = irsensor.getDistance();
  LOG(LL_INFO, ("Distance: %d", distance));

  return MGOS_APP_INIT_SUCCESS;
}
