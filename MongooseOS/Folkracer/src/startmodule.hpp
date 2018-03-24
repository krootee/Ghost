/*
 *
 */

#pragma once

namespace Sensor {
    
    enum startmodule_state {
        ready = 1,
        started = 2,
        stopped = 3
    };

    class StartModule {
      public:
        //Constructors and Destructor
        StartModule(int signal_pin);
        StartModule(int signal_pin, int vcc_pin);
        ~StartModule();
        
        //Methods
        void initialize();
        void powercycle();
        startmodule_state get_current_state();
        int get_count();

      private:
        int _pin_vcc;
        int _pin_signal;
        int count;
        startmodule_state _current_state;

        //Private Methods
        static void state_change_callback(int, void * arg);
        //static void timer_cb(void *arg);
    };
}