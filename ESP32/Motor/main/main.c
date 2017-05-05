#include "freertos/FreeRTOS.h"
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
#include <freertos/task.h>

#include "pwm.h"
#include "motor.c"

#define GPIO_MOTOR GPIO_NUM_26

#define SLEEP(ms) vTaskDelay(ms / portTICK_PERIOD_MS)

/*
 * Program for testing and controlling the HobbyKing XC-10A ESC
 * Frode Lillerud, april 2017
 */

void app_main(void)
{
  pwm_configure(GPIO_MOTOR);

  //TODO, initialize the motor controller
  motor_calibrate();

  //TODO, set speed
  while (true)
  {


    for (int s = 1800; s < 3600; s += 20)
    {
      motor_set_speed(s);
      SLEEP(100);
    }
    for (int s = 3600; s > 1800; s -= 20)
    {
      motor_set_speed(s);
      SLEEP(100);
    }
  }


  // motor_set_speed(2000);
  //
  // vTaskDelay(3000 / portTICK_PERIOD_MS); //Delay for 2.5 seconds
  //
  // motor_set_speed(3000);
  //
  // vTaskDelay(3000 / portTICK_PERIOD_MS); //Delay for 2.5 seconds
  //
  // motor_set_speed(4000);
}
