/*
 *
 */

#include "mgos.h"
#include "motor.hpp"

namespace Actuators {

    Motor::Motor(int pin) {
        this->_pin = pin;
    }

    //Fra CPP filen
    void Motor::setDesiredSpeed(float duty_cycle) {

        const int frequency = 50; //50Hz = 20ms

        //duty between 0 and 1.
        //float duty_cycle = 0.075f;
    
        //Servos typically need a PWM signal that is high somewhere between 1ms and 2ms. 
        //With a period of 20 ms, that means we get the following duty cycles:
        //1.0 ms = 0.05 duty cycle
        //1.5 ms = 0.075 duty cycle
        //2.0 ms = 0.1 duty cycle
        if (!mgos_pwm_set(_pin, frequency, duty_cycle))
        {
            LOG(LL_ERROR, ("Unable to set PWM for pin %d", _pin));
        }

        return;
    }

    void Motor::disable() {
        mgos_pwm_set(_pin, 0, 0);
    }
}