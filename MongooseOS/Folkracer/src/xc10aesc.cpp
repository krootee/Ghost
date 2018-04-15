/*
 * Driver for the HobbyKing XC-10A ESC (Electronic Speed Control)
 * Frode Lillerud, 15.april 2018
 */

#include "mgos.h"
#include "mgos_pwm.h"
#include "pwm.cpp"

namespace Actuators {
  class xc10aesc : public PWM {
    public:

      xc10aesc(int pin) : PWM(pin) {
        _pin = pin;
      }
      

      void calibrate() {
        
        LOG(LL_INFO, ("Calibrating HobbyKing XC-10A ESC"));

        short wait_time_us = 2.5 * 1000 * 1000 * 1000; //microseconds

        const int frequency = 50; //50Hz = 20ms period

        //Go to MAX 
        float pulse_width_ms = 2.0; //ms 
        const float duty_cycle = (1/frequency*1000)*pulse_width_ms;
        mgos_pwm_set(_pin, frequency, duty_cycle);
        LOG(LL_INFO, ("MAX - Waiting"));
        mgos_usleep(wait_time_us);

        //Go to MIN
        pulse_width_ms = 1.0; //ms
        set_pulse_width(pulse_width_ms);
        LOG(LL_INFO, ("MIN - Waiting"));
        mgos_usleep(wait_time_us);

        //Go to CENTER
        pulse_width_ms = 1.5; //ms
        set_pulse_width(pulse_width_ms);
        LOG(LL_INFO, ("CENTER - Waiting"));        
        mgos_usleep(wait_time_us);
      }

    private:
      int _pin;
  };
}