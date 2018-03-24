/*
 * Mongoose OS driver for the Startmodule (startmodule.com
 * Frode Lillerud, 20.mar 2018
 */

#include <mgos.h>
#include "startmodule.hpp"
#include "carstate.hpp"

namespace Sensor {

  StartModule::StartModule(int pin) {
    LOG(LL_INFO, ("StartModule::StartModule(int)"));
    this->_pin_signal = pin;
    count = 1;
    this->_current_state = startmodule_state::ready;
  }

  StartModule::StartModule(int signal, int vcc) {
    LOG(LL_INFO, ("StartModule::StartModule(int, int)"));
    this->_pin_signal = signal;
    this->_pin_vcc = vcc;
    this->count = 0;

    this->_current_state = startmodule_state::ready;
  }

  StartModule::~StartModule()
  {
    //Destructor
  }
  
  //Hook up interrupts
  void StartModule::initialize() {
    LOG(LL_INFO, ("StartModule::initialize()"));
    this->_current_state = startmodule_state::ready;
  
    mgos_gpio_set_mode(_pin_signal, MGOS_GPIO_MODE_INPUT);
    mgos_gpio_set_int_handler(_pin_signal, MGOS_GPIO_INT_EDGE_ANY, StartModule::state_change_callback, this);
    bool interrupt = mgos_gpio_enable_int(_pin_signal); 
    if (interrupt)
        LOG(LL_INFO, ("Interrupt attached to pin %d", _pin_signal));
    else
        LOG(LL_ERROR, ("Interrupt NOT attached for startmodule!"));

    //mgos_set_timer(4*1000, 1, StartModule::timer_cb, this);
  }
/*
  void StartModule::timer_cb(void *arg)
  {
    StartModule* pThis = reinterpret_cast<StartModule*>(arg);
    pThis->count++;

    LOG(LL_INFO, ("Count=%d", pThis->count));
  }
*/
  //Set the internal state engine to the next state.
  void StartModule::state_change_callback(int pin, void * arg) {
    //LOG(LL_INFO, ("StartModule::goto_next_state(void * arg)"));

    g_carstate->count++;
    g_carstate->temperature *= 2;

    StartModule* pThis = reinterpret_cast<StartModule*>(arg);
    pThis->count++;

    //LOG(LL_INFO, ("Interrupt count: %d", pThis->count));

    if (pThis->_current_state == startmodule_state::ready)
    {
        pThis->_current_state = startmodule_state::started;
        g_carstate->startmodule = startmodule_state::started;
    }
    else if (pThis->_current_state == startmodule_state::started)
    {
        pThis->_current_state = startmodule_state::stopped;
        g_carstate->startmodule = startmodule_state::stopped;
    }
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
    //LOG(LL_INFO, ("New state in startmodule: %d", pThis->_current_state));
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

  int StartModule::get_count() {
    return this->count;
  }
}