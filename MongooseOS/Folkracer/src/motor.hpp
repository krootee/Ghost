/*
 *
 */

#include "mgos_pwm.h"

namespace Actuators {
  class Motor {
    private:
      int _pin = 0;
    public:
      Motor(int pin); 
      //Fra HPP filen
      void setDesiredSpeed(float duty_cycle);
      void disable();
  };
}