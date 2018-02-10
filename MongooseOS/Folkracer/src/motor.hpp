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
        void setDesiredSpeed(int speed);
        void disable();
    };
}