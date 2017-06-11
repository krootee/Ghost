#include "fw/src/mgos_app.h"
#include "fw/src/mgos_gpio.h"

enum mgos_app_init_result mgos_app_init(void) {

//https://forum.mongoose-os.com/discussion/758/pwm-how-to-with-esp8266-need-some-tips-please#latest

  int period = 1500;
  int duty = 50;
  mgos_pwm_set(GPIO_PIN_STEERING, period, duty);

  return MGOS_APP_INIT_SUCCESS;
}
