#include "rc5.h"

//Interrupt Service Routine called when incoming IR signal detected
static void ir_signal_callback(int pin, void *arg) {
  LOG(LL_INFO, ("Interrupted on pin %d\n", pin));
  mgos_gpio_disable_int(pin);
  //if (timer_id == 0) {
  //  timer_id = mgos_set_timer(1, MGOS_TIMER_FOREVER, grab_RC5_data, NULL);
//    LOG(LL_INFO, ("Timer ID: %d", timer_id));
//  }

  char data[RC5_BIT_COUNT];

  for (int i = 0; i < RC5_BIT_COUNT; i++) {
    bool level = mgos_gpio_read(pin);
    //LOG(LL_INFO, ("Data: %d", level));
    data[i] = static_cast<char>(level ? '1' : '0');
    mgos_usleep(1700);
  }

  string s;
  
  for (int i = 0; i < RC5_BIT_COUNT; i++) {
    s.append(1u, data[i]);
  //   LOG(LL_INF)
   }

   LOG(LL_INFO, ("Bitstream: %s", s.c_str()));

  mgos_msleep(2000); // Wait a second
  mgos_gpio_enable_int(pin);
}

void RC5::start() {
    mgos_gpio_set_mode(GPIO_PIN_IR, MGOS_GPIO_MODE_INPUT);
    mgos_gpio_set_int_handler(GPIO_PIN_IR, MGOS_GPIO_INT_EDGE_POS, ir_signal_callback, NULL);
    mgos_gpio_enable_int(GPIO_PIN_IR);
}

string RC5::get_ir_data() {
  string s;
  
  for (int i = 0; i < RC5_BIT_COUNT; i++) {
    s.append(1u, this->data[i]);
  }

  return s;
}