/*
 *
 */

#include "mgos.h"
#include "startmodule.hpp"

namespace Sensor {

    StartModule::StartModule(int pin) {
        this->_pin_signal = pin;
        //mgos_gpio_set_int_handler(pin, MGOS_GPIO_INT_EDGE_ANY, )
        //mgos_gpio_enable_int(pin);

        this->_current_state = startmodule_states::ready;
    }

    StartModule::StartModule(int signal, int vcc) {
        this->_pin_signal = signal;
        this->_pin_vcc = vcc;

        this->_current_state = startmodule_states::ready;
    }
    
    //Powercycle the StartModule by turning off power to it, waiting a second, and turning power back on.
    //Note, requires that the VCC pin on the StartModule is connected to a GPIO pin, not directly too a +3/+5V pin.
    void StartModule::powercycle() {
        mgos_gpio_write(this->_pin_vcc, false);
        //wait
        mgos_gpio_write(this->_pin_vcc, true);
        this->_current_state = startmodule_states::ready;
    }
}