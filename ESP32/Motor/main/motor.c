/*
 * Driver for the HobbyKing Brushless Car ESC 10A w/Reverse
 * https://hobbyking.com/en_us/hobbykingr-tm-brushless-car-esc-10a-w-reverse.html
 * Frode Lillerud, april 2017
 */

//#include <freertos/task.h>
#include <esp_log.h>
#include "freertos/FreeRTOS.h"
//#include "esp_wifi.h"
//#include "esp_system.h"
//#include "esp_event.h"
//#include "esp_event_loop.h"
//#include "nvs_flash.h"
//#include "driver/gpio.h"
#include <freertos/task.h>
#include "pwm.h"


//Perform initial calibration of the ESC
void motor_calibrate()
{
  //Maximum throttle
  pwm_set_microseconds(3600);
  vTaskDelay(3000 / portTICK_PERIOD_MS); //Delay for 2.5 seconds

  //Minimum throttle
  pwm_set_microseconds(1800);
  vTaskDelay(3000 / portTICK_PERIOD_MS); //Delay for 2.5 seconds

  //Center
  pwm_set_microseconds(2460);
  vTaskDelay(3000 / portTICK_PERIOD_MS); //Delay for 2.5 seconds
}

//Set speed. -100 is full reverse, 0 is no movement, 100 is full forward.
void motor_set_speed(int speed)
{
  ESP_LOGI("motor", "Speed: %d", speed);
  pwm_set_microseconds(speed);
}
