
//#include <iostream>
//#include <stdlib.h>
#include <stdint.h>
#include <string.h>

//#include "fw/src/mgos_app.h"
//#include "fw/src/mgos_gpio.h"       
//#include "fw/src/mgos_sys_config.h" //Needed for LOG
//#include "fw/src/mgos_timers.h"
//#include "fw/src/mgos_hal.h"

/*
 * A generic RC5 C++ class for working with RC5 infrared remote protocol.
 * Mostly inspired by article at http://clearwater.com.au/code/rc5
 * and the code at https://github.com/pinkeen/avr-rc5
 * Note, this class does NOT contain methods to capture time, work with interrupts etc. 
 * It is dedicated to just the RC5 statemachine.
 * Frode Lillerud, june 2017
 */

//using namespace std;



#define RC5_BIT_COUNT 14

typedef enum {
    STATE_RC5_START1,
    STATE_RC5_MID1,
    STATE_RC5_MID0,
    STATE_RC5_START0,
    STATE_RC5_ERROR,
    STATE_RC5_BEGIN,
    STATE_RC5_END
} RC5State;

typedef enum {
    RC5EVENT_SHORT_LOW = 0,
    RC5EVENT_SHORT_HIGH = 2,
    RC5EVENT_LONG_LOW = 4,
    RC5EVENT_LONG_HIGH = 6,
    RC5EVENT_ERROR = 8    
} RC5Event;

class RC5StateMachine {
public:
    RC5StateMachine();
    RC5State reset();
    RC5State advance(RC5State current_state, RC5Event event);
    int* get_rc5_command();
private:
    void emit(int bit);
    int bit_index = RC5_BIT_COUNT;  //Index of how far we've come in building up the command
    int command[RC5_BIT_COUNT]; //The RC5 command
    const uint8_t transitions[4] = {0x01, 0x91, 0x9b, 0xfb};    //Transition table for states
};