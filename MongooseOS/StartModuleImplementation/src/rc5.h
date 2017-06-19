/*
 * Class responsible for capturing IR data.
 * Uses Mongoose OS specific code.
 * Frode Lillerud, june 2017
 */

#include "fw/src/mgos_gpio.h"
#include "fw/src/mgos_sys_config.h" //Needed for LOG
//#include "rc5statemachine.h"

#define SHORT_PULSE_MIN 444     //us
#define SHORT_PULSE_MAX 1333    //us
#define LONG_PULSE_MIN 1334     //us
#define LONG_PULSE_MAX 2222     //us

class RC5 {
public:
    //Configure RC5 to listen for interrupts on the given pin
    RC5(int pin);
    void set_bit(bool bit);
    bool command_available();
    bool command_reset();
    uint8_t get_RC5_start_bits();
    uint8_t get_RC5_toggle_bit();
    uint8_t get_RC5_address_bits();
    uint8_t get_RC5_command_bits();

    //uint8_t * get_RC5_command();
private:
    int get_difference_us(double, double);
    double time_previous_signal = 0.0;
    //RC5StateMachine state_machine;
};