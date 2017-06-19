#include "fw/src/mgos_app.h"
#include "fw/src/mgos_gpio.h"       
#include "fw/src/mgos_sys_config.h" //Needed for LOG
#include "fw/src/mgos_timers.h"
#include "fw/src/mgos_hal.h"

#include "rc5.h"

//#include <iostream>
//#include <stdlib.h>
//#include <string.h>

using namespace std;

/*
 * Sample application for implementing a StartModule using ESP32 and Mongoose OS.
 * See http://www.startmodule.com for StartModule info.
 * See http://clearwater.com.au/code/rc5 for RC5 protocol article
 * I'm using a custom PCB that has a TSOP753 38kHz receiver connected to ESP32 pin 22.
 * Frode Lillerud, NorBot, june 2017
 */

#define GPIO_PIN_IR 22

//#define MGOS_TIMER_FOREVER 1
//#define MGOS_TIMER_ONCE 0

//RC5 rc5;

// //Accepts two timestamps, and returns the difference in microseconds
// int get_difference_us(double time_first, double time_last) {
//   return (time_last * 1000 * 1000) - (time_first * 1000 * 1000);
// }

// //Interrupt Service Routine called when incoming IR signal detected
// static void ir_signal_callback(int pin, void *arg) {
//   mgos_gpio_disable_int(pin);

//   char data[RC5_BIT_COUNT];

//   for (int i = 0; i < RC5_BIT_COUNT; i++) {
//     bool level = mgos_gpio_read(pin);
//     data[i] = static_cast<char>(level ? '1' : '0');
//     mgos_usleep(1700);
//   }

//   string s;
  
//   for (int i = 0; i < RC5_BIT_COUNT; i++) {
//     s.append(1u, data[i]);
//   }

//   LOG(LL_INFO, ("Uptime: %f", mgos_uptime()));
//   LOG(LL_INFO, ("Time: %f", mg_time()));
//   LOG(LL_INFO, ("Bitstream: %s", s.c_str()));

//   //mgos_msleep(2000); // Wait a second
//   mgos_gpio_enable_int(pin);
// }

// static void  ir_rc5_callback(int pin, void *args) {
//   bool bit = mgos_gpio_read(pin);
//   rc5.set_bit(bit);
// }

//Main application starts here
enum mgos_app_init_result mgos_app_init(void) {

  //RC5 rc5 = new RC5(GPIO_PIN_IR);
  RC5 rc5(GPIO_PIN_IR);

  if (rc5.command_available())
  {
    LOG(LL_INFO, ("RC5 Command available!"));
    //RC5Command command = rc5.get
  }
  //Hook up interrupt
  //mgos_gpio_set_mode(GPIO_PIN_IR, MGOS_GPIO_MODE_INPUT);
  //mgos_gpio_set_int_handler(GPIO_PIN_IR, MGOS_GPIO_INT_EDGE_POS, ir_rc5_callback, NULL);
  //mgos_gpio_enable_int(GPIO_PIN_IR);

  //double before = mg_time();
  //mgos_usleep(500);
  //double after = mg_time();
  
  //LOG(LL_INFO, ("Before: %f", before));
  //LOG(LL_INFO, ("After: %f", after));
  //int diff_us = get_difference_us(before, after);
  //LOG(LL_INFO, ("Diff us: %d", diff_us));

  return MGOS_APP_INIT_SUCCESS;
}