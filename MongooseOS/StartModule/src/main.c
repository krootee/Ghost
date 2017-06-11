#include "fw/src/mgos_app.h"
//#include "fw/src/mgos_wifi.h"
#include "fw/src/mgos_gpio.h"
#include "fw/src/mgos_timers.h"
//#include "common/platform.h"
//#include "fw/src/mgos_mongoose.h"
#include "fw/src/mgos_sys_config.h"
//#include "sum.hpp"

#define GPIO_PIN_LED 23
#define GPIO_PIN_STARTMODULE_SIGNAL 25
#define GPIO_PIN_STARTMODULE_VCC 17
#define GPIO_PIN_BUTTON 18

static void blink_timer_callback(void *arg)
{
  bool current_level = mgos_gpio_toggle(GPIO_PIN_LED);
  (void)arg;
}

static void startmodule_interrupt(int pin, void *arg)
{
  LOG(LL_INFO, ("INTERRUPTED ON PIN: %d\n", pin));
  bool current_level = mgos_gpio_toggle(GPIO_PIN_LED);
  (void)pin;
  (void)arg;
}

static void button_press_handler(int pin, void *arg) 
{
  LOG(LL_INFO, ("Button clicked - restarting startmodule"));
  mgos_gpio_toggle(GPIO_PIN_STARTMODULE_VCC);
}

enum mgos_app_init_result mgos_app_init(void)
{
  LOG(LL_INFO, ("Starting application"));
  //mgos_wifi_add_on_change_cb(on_wifi_event, 0);
  //Testing C++
  // Summer *s = new Summer();
  // int total = s->sum(3,6);
  // LOG(LL_INFO, ("C++ says 3+6 = %d\n", total));

  //Configure LED
  LOG(LL_INFO, ("Configuring LED pin"));
  mgos_gpio_set_mode(GPIO_PIN_LED, MGOS_GPIO_MODE_OUTPUT);
  //mgos_set_timer(500, true, blink_timer_callback, NULL);

  //Enable button
  mgos_gpio_set_button_handler(GPIO_PIN_BUTTON, MGOS_GPIO_PULL_UP, MGOS_GPIO_INT_EDGE_ANY, 50, button_press_handler, NULL);
  //mgos_gpio_set_pull(GPIO_PIN_BUTTON, MGOS_GPIO_PULL_UP);

  //Power up startmodule
  LOG(LL_INFO, ("Powering up startmodule"));
  mgos_gpio_set_mode(GPIO_PIN_STARTMODULE_VCC, MGOS_GPIO_MODE_OUTPUT);
  //mgos_gpio_set_pull(GPIO_PIN_STARTMODULE_VCC, MGOS_GPIO_PULL_UP);
  mgos_gpio_write(GPIO_PIN_STARTMODULE_VCC, true);

  //Listen for Startmodule interrupt
  mgos_gpio_set_mode(GPIO_PIN_STARTMODULE_SIGNAL, MGOS_GPIO_MODE_INPUT);
  mgos_gpio_set_pull(GPIO_PIN_STARTMODULE_SIGNAL, MGOS_GPIO_PULL_UP);
  mgos_gpio_set_int_handler(GPIO_PIN_STARTMODULE_SIGNAL, MGOS_GPIO_INT_EDGE_ANY, startmodule_interrupt, NULL);
  LOG(LL_INFO, ("Attaching interrupt handler for startmodule"));
  bool interrupt = mgos_gpio_enable_int(GPIO_PIN_STARTMODULE_SIGNAL);
  if (interrupt)
    LOG(LL_INFO, ("Interrupt attached"));
  else
    LOG(LL_INFO, ("Interrupt NOT attached!"));

  LOG(LL_INFO, ("Done"));
  return MGOS_APP_INIT_SUCCESS;
}