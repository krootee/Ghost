/*
 *
 */

namespace Sensor {
    
    enum startmodule_state {
        ready = 1,
        started = 2,
        stopped = 3
    };

    class StartModule {
        private:
        int _pin_vcc;
        int _pin_signal;
        startmodule_state _current_state;

        //Private Methods
        static void goto_next_state(int pin, void * arg);

        public:
        //Constructors
        StartModule(int signal_pin);
        StartModule(int signal_pin, int vcc_pin);
        
        //Methods
        void initialize();
        void powercycle();
        startmodule_state get_current_state();
    };
}