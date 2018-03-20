/*
 * Mongoose OS driver for the Startmodule (startmodule.com
 * Frode Lillerud, 20.mar 2018
 */

#include "mgos.h"
#include "startmodule.hpp"

namespace Sensor {

  StartModule::StartModule(int pin) {
      this->_pin_signal = pin;

      this->_current_state = startmodule_state::ready;
  }

  StartModule::StartModule(int signal, int vcc) {
      this->_pin_signal = signal;
      this->_pin_vcc = vcc;

      this->_current_state = startmodule_state::ready;
  }
  
  //Hook up interrupts
  void StartModule::initialize() {
    this->_current_state = startmodule_state::ready;
  
    mgos_gpio_set_mode(_pin_signal, MGOS_GPIO_MODE_INPUT);
    mgos_gpio_set_int_handler(_pin_signal, MGOS_GPIO_INT_EDGE_ANY, StartModule::goto_next_state, this);
    bool interrupt = mgos_gpio_enable_int(_pin_signal); 
    if (interrupt)
        LOG(LL_INFO, ("Interrupt attached to pin %d", _pin_signal));
    else
        LOG(LL_ERROR, ("Interrupt NOT attached for startmodule!"));
  }

  //Set the internal state engine to the next state.
  void StartModule::goto_next_state(int pin, void * arg) {

    StartModule* pThis = reinterpret_cast<StartModule*>(arg);

    if (pThis->_current_state == startmodule_state::ready)
        pThis->_current_state = startmodule_state::started;
    else if (pThis->_current_state == startmodule_state::started)
        pThis->_current_state = startmodule_state::stopped;
    else {
        //Already in Stopped state. Do nothing.
    }

    int state = static_cast<int>(pThis->_current_state);    
    if (state == 1) {
      LOG(LL_INFO, ("Ready"));
    }
    else if (state == 2) {
      LOG(LL_INFO, ("Started"));
    } else if (state == 3) {
      LOG(LL_INFO, ("Stopped"));
    }
    LOG(LL_INFO, ("New state in startmodule: %d", pThis->_current_state));
  }
  
  //Powercycle the StartModule by turning off power to it, waiting a second, and turning power back on.
  //Note, requires that the VCC pin on the StartModule is connected to a GPIO pin, not directly too a +3/+5V pin.
  void StartModule::powercycle() {
    //Turn it off      
    mgos_gpio_write(this->_pin_vcc, false);
    //Wait one second...
    mgos_usleep(1000);
    //Turn it on again
    mgos_gpio_write(this->_pin_vcc, true);

    //Reset the internal state engine.
    this->_current_state = startmodule_state::ready;
  }

  //Get the current state from the internal state engine
  startmodule_state StartModule::get_current_state() {
      return this->_current_state;
  }
}