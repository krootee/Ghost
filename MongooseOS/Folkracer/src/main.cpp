/*
 *
 */

#include "mgos.h"
#include "motor.hpp"

enum mgos_app_init_result mgos_app_init(void) {

  Actuators::Motor motor;
  motor.setDesiredSpeed(50);

  return MGOS_APP_INIT_SUCCESS;
}
