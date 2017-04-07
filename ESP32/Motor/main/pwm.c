/*
* PWM for ESP32
*/

#include "freertos/FreeRTOS.h"
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
#include "driver/ledc.h"

void pwm_configure(int pin)
{
  //Configure timer for PWM
  ledc_timer_config_t timer_conf;
  timer_conf.bit_num = LEDC_TIMER_15_BIT;
  timer_conf.freq_hz = 50; //50 = 20ms
  timer_conf.speed_mode = LEDC_HIGH_SPEED_MODE;
  timer_conf.timer_num = LEDC_TIMER_0;
  ledc_timer_config(&timer_conf);

  //Set a LEDC channel for PWM
  ledc_channel_config_t ledc_conf;
  ledc_conf.channel = LEDC_CHANNEL_0;
  ledc_conf.duty = 3276;
  ledc_conf.gpio_num = pin;
  ledc_conf.intr_type = LEDC_INTR_DISABLE;
  ledc_conf.speed_mode = LEDC_HIGH_SPEED_MODE;
  ledc_conf.timer_sel = LEDC_TIMER_0;
  ledc_channel_config(&ledc_conf);
}
