/*
 * PWM helper for Mongoose OS.
 * Frode Lillerud
 */

class PWM {
  private:
    int _pwm_pin;
    int _frequency;
    float _duty_cycle;

  public:
    PWM(int pin) {
      _pwm_pin = pin;
    }

    void initialize_servo() {
      this->_frequency = 50; //50Hz = 20ms
    }

    bool set_pulse_width(float pulse_width) {
      return false;
    }
};