#include "rc5statemachine.h"

RC5StateMachine::RC5StateMachine() {
    
}

RC5State RC5StateMachine::reset() {

    memset(this->command, 0, sizeof(this->command)); //Clear the array
    this->bit_index = RC5_BIT_COUNT;  //Reset index

    return STATE_RC5_BEGIN;
}

void RC5StateMachine::emit(int bit) {
    this->command[this->bit_index] = bit;
    this->bit_index--; //Works its way backward from RC5_BIT_COUNT to 0
}

RC5State RC5StateMachine::advance(RC5State current_state, RC5Event event) {
    RC5State new_state;

    if (event == RC5EVENT_ERROR) {
        new_state = this->reset();
    }
    else {
        //new_state = this->transitions[current_state] >> event & 0x3;
        new_state = STATE_RC5_END;
        if (new_state == current_state) {
            //No transition is an indication of an error
            new_state = this->reset();
        } else {
            if (new_state == STATE_RC5_MID0) {
                //Always emit 0 when entering MID0 state
                this->emit(0);
            } else if (new_state == STATE_RC5_MID1) {
                //Always emit 1 when entering MID1 state
                this->emit(1);
            }
        }
    }

    return new_state;
}

int * RC5StateMachine::get_rc5_command() {
    return this->command;
}