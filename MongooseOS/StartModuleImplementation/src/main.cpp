#include "fw/src/mgos_app.h"
#include "fw/src/mgos_gpio.h"       
#include "fw/src/mgos_sys_config.h" //Needed for LOG
#include "fw/src/mgos_timers.h"
#include "fw/src/mgos_hal.h"

//#include "rc5.h"

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "manchester.cpp"

using namespace std;

/*
 * Sample application for implementing a StartModule using ESP32 and Mongoose OS.
 * See http://www.startmodule.com for StartModule info.
 * See http://clearwater.com.au/code/rc5 for RC5 protocol article
 * I'm using a custom PCB that has a TSOP753 38kHz receiver connected to ESP32 pin 22.
 * Frode Lillerud, NorBot, june 2017
 */

#define GPIO_PIN_IR 22

#define MGOS_TIMER_FOREVER 1
#define MGOS_TIMER_ONCE 0

#define RC5_BIT_COUNT 14

//int count = 0;
//mgos_timer_id timer_id;

//Callback for the timer
// static void grab_RC5_data(void *args) {
//   if (count++ < 14) {
//     //Grab value from the IR data stream every 2 milliseonds
//     bool value = mgos_gpio_read(GPIO_PIN_IR);
//     LOG(LL_INFO, ("IR: %d", value));
//   }
//   else {
//     mgos_clear_timer(timer_id);
//     timer_id = 0;
//     count = 0;
//     LOG(LL_INFO, ("Timer Cleared: %d", timer_id));
//   }
// }

//Interrupt Service Routine called when incoming IR signal detected
static void ir_signal_callback(int pin, void *arg) {
  LOG(LL_INFO, ("Interrupted on pin %d\n", pin));
  mgos_gpio_disable_int(pin);

  char data[RC5_BIT_COUNT];

  for (int i = 0; i < RC5_BIT_COUNT; i++) {
    bool level = mgos_gpio_read(pin);
    data[i] = static_cast<char>(level ? '1' : '0');
    mgos_usleep(1700);
  }

  string s;
  
  for (int i = 0; i < RC5_BIT_COUNT; i++) {
    s.append(1u, data[i]);
  }

   LOG(LL_INFO, ("Bitstream: %s", s.c_str()));
   std::vector<unsigned> decoded = Manchester::decode(s.c_str(), 8);
   LOG(LL_INFO, ("Decoded."));

  mgos_msleep(2000); // Wait a second
  mgos_gpio_enable_int(pin);
}

//Main application starts here
enum mgos_app_init_result mgos_app_init(void) {

  //Hook up interrupt
  mgos_gpio_set_mode(GPIO_PIN_IR, MGOS_GPIO_MODE_INPUT);
  mgos_gpio_set_int_handler(GPIO_PIN_IR, MGOS_GPIO_INT_EDGE_POS, ir_signal_callback, NULL);
  mgos_gpio_enable_int(GPIO_PIN_IR);

  return MGOS_APP_INIT_SUCCESS;
}