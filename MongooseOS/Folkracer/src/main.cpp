/*
 *
 */

#include "mgos.h"
#include "motor.hpp"
#include "gp2y0e02b.hpp"

#define GPIO_PIN_26  26

enum mgos_app_init_result mgos_app_init(void) {

  Actuators::Motor motor(GPIO_PIN_26);
  motor.setDesiredSpeed(50);

  Sensor::GP2Y0E02B irsensor;
  int distance = irsensor.getDistance();
  LOG(LL_INFO, ("Distance: %d", distance));

  return MGOS_APP_INIT_SUCCESS;
}
