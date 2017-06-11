#include "fw/src/mgos_app.h"
#include "fw/src/mgos_wifi.h"
#include "fw/src/mgos_gpio.h"
#include "fw/src/mgos_timers.h"
//#include "common/platform.h"
//#include "fw/src/mgos_mongoose.h"
#include "fw/src/mgos_sys_config.h"

#define GPIO_PIN_LED 23
#define GPIO_PIN_STARTMODULE_SIGNAL 25
#define GPIO_PIN_STARTMODULE_VCC 17

// static void on_wifi_event(enum mgos_wifi_status event, void *data) {
//   (void) data;
//   switch (event) {
//     case MGOS_WIFI_IP_ACQUIRED:
//       break;
//     case MGOS_WIFI_CONNECTED:
//       break;
//     case MGOS_WIFI_DISCONNECTED:
//       break;
//   }
// }

static void startmodule_interrupt(int pin, void *arg)
{
  LOG(LL_INFO, ("INTERRUPTED ON PIN: %d\n", pin));
  bool current_level = mgos_gpio_toggle(GPIO_PIN_LED);
  (void)arg;
}

enum mgos_app_init_result mgos_app_init(void)
{
  LOG(LL_INFO, ("Starting application"));
  //mgos_wifi_add_on_change_cb(on_wifi_event, 0);

  //Add blinker LED
  LOG(LL_INFO, ("Configuring LED pin"));
  mgos_gpio_set_mode(GPIO_PIN_LED, MGOS_GPIO_MODE_OUTPUT);
  //mgos_set_timer(1000, true, blink_timer_callback, NULL);

  //Power up startmodule
  LOG(LL_INFO, ("Powering up startmodule"));
  mgos_gpio_set_mode(GPIO_PIN_STARTMODULE_VCC, MGOS_GPIO_MODE_OUTPUT);
  mgos_gpio_write(GPIO_PIN_STARTMODULE_VCC, true);

  

  //Listen for Startmodule interrupt
  LOG(LL_INFO, ("Attaching interrupt handler for startmodule"));
  mgos_gpio_set_int_handler(GPIO_PIN_STARTMODULE_SIGNAL, MGOS_GPIO_INT_EDGE_ANY, startmodule_interrupt, NULL);
  bool interrupt = mgos_gpio_enable_int(GPIO_PIN_STARTMODULE_SIGNAL);
  if (interrupt)
    LOG(LL_INFO, ("Interrupt attached"));
  else
    LOG(LL_INFO, ("Interrupt NOT attached!"));

  LOG(LL_INFO, ("Done"));
  return MGOS_APP_INIT_SUCCESS;
}