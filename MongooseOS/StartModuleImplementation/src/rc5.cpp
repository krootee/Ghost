#include "rc5.h"

static void receive_rc5_callback(int pin, void * args) {
    LOG(LL_INFO, ("PIN triggered from RC5 class\n"));
    //Grab current time
    //Read event
    //Check if time is a long or short pulse
    //reset if illegal pulse length

    //
}

RC5::RC5(int pin) {
    //Set up interrupt (NB, Mongoose OS specific code)
    mgos_gpio_set_mode(pin, MGOS_GPIO_MODE_INPUT);
    mgos_gpio_set_int_handler(pin, MGOS_GPIO_INT_EDGE_POS, receive_rc5_callback, NULL);
    mgos_gpio_enable_int(pin);

    //Set initial state
    //this->state = STATE_RC5_BEGIN;
}

// void RC5::reset() {
//     this->state = STATE_RC5_BEGIN;
// }



void RC5::set_bit(bool bit) {

    double now = mg_time(); //Grab the current time

    int us_since_previous = this->get_difference_us(this->time_previous_signal, now);
    
    if (us_since_previous > SHORT_PULSE_MIN && us_since_previous < SHORT_PULSE_MAX)
    {
        //Short pulse detected
    }
    else if (us_since_previous > LONG_PULSE_MIN && us_since_previous < LONG_PULSE_MAX)
    {
        //Long pulse detected
    }
    else
    {
        //error 
        //this->reset();
    }

    //Save the time for the next time we're called
    this->time_previous_signal = now;

    //this->state_machine.advance(this->current_state, this->current_event);
}

// int * RC5::get_RC5_command() {
//     return NULL; //TODO
// }

//Accepts two timestamps, and returns the difference in microseconds
int RC5::get_difference_us(double time_first, double time_last) {
  return (time_last * 1000 * 1000) - (time_first * 1000 * 1000);
}

bool RC5::command_available() {
    return false; //TODO
}