/*
 *
 */

#include "mgos.h"
#include "motor.hpp"
#include "gp2y0e02b.hpp"

enum mgos_app_init_result mgos_app_init(void) {

  Actuators::Motor motor;
  motor.setDesiredSpeed(50);

  Sensor::GP2Y0E02B irsensor;
  int distance = irsensor.getDistance();

  return MGOS_APP_INIT_SUCCESS;
}
