/*
 *
 */

namespace Sensor {
    
    enum startmodule_states {
        ready = 1,
        started = 2,
        stopped = 3
    };

    class StartModule {
        private:
        int _pin_vcc;
        int _pin_signal;
        startmodule_states _current_state;

        public:
        //Constructors
        StartModule(int signal_pin);
        StartModule(int signal_pin, int vcc_pin);
        
        //Methods
        void powercycle();
    };
}