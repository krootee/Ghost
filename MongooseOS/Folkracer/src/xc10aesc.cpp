/*
 * Driver for the HobbyKing XC-10A ESC (Electronic Speed Control)
 * Frode Lillerud, 15.april 2018
 */

#include "mgos.h"
#include "mgos_pwm.h"
//#include "mgos_system.h"
#include "pwm.cpp"

namespace Actuators {
  class xc10aesc : public PWM {
    public:

      xc10aesc(int pin) : PWM(pin) {
        _pin = pin;
      }
      

      void calibrate() {
        
        LOG(LL_INFO, ("Calibrating HobbyKing XC-10A ESC"));

        float wait_time_ms = 2.5 * 1000; //milliseconds

        const int frequency = 50; //50Hz = 20ms period

        //Go to MAX 
        float pulse_width_ms = 2.0; //ms 
        float period_length = 1 / frequency * 1000; //normally 20ms
        //const float duty_cycle = pulse_width_ms / period_length;
        float duty_cycle = 0.1;
        LOG(LL_INFO, ("Duty cycle set to %.4f", duty_cycle));
        if (!mgos_pwm_set(_pin, frequency, duty_cycle))
          LOG(LL_ERROR, ("Unable to set PWM for XC-10A"));

        LOG(LL_INFO, ("MAX - Waiting for %.2f milliseconds", wait_time_ms));
        mgos_msleep(wait_time_ms);

        //Go to MIN
        //pulse_width_ms = 1.0; //ms
        duty_cycle = 0.05;
        mgos_pwm_set(_pin, frequency, duty_cycle);
        //set_pulse_width(pulse_width_ms);
        LOG(LL_INFO, ("MIN - Waiting"));
        mgos_msleep(wait_time_ms);

        //Go to CENTER
        //pulse_width_ms = 1.5; //ms
        //set_pulse_width(pulse_width_ms);
        duty_cycle = 0.075;
        mgos_pwm_set(_pin, frequency, duty_cycle);
        LOG(LL_INFO, ("CENTER - Waiting"));
        mgos_msleep(wait_time_ms);
      }

    private:
      int _pin;
  };
}