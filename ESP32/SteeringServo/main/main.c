#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
//#include "esp_wifi.h"
#include "esp_system.h"
//#include "esp_event.h"
//#include "esp_event_loop.h"
//#include "nvs_flash.h"
//#include "driver/gpio.h"
#include "driver/ledc.h"

/*
 * Testprogram for ServoSteering
 * Configure GPIO port X as a PWM output
 * Move steering wheels back and forth

 https://www.youtube.com/watch?v=rarE-WI_Y0A
 */

#define GPIO_STEERING_IO  10
#define GPIO_OUTPUT_PIN_SEL (GPIO_STEERING_IO)

#define SLEEP(ms) vTaskDelay(ms / portTICK_PERIOD_MS)

void app_main(void)
{
  /*
  gpio_config_t io_conf;
  io_conf.intr_type = GPIO_PIN_INTR_DISABLE; //Disable interrupt
  io_conf.mode = GPIO_MODE_OUTPUT; //Set Output mode
  io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL; //Mask bit we want to set
  io_conf.pull_down_en = 0; //Disable pull-down mode
  io_conf.pull_up_en = 0; //Didable pull-up mode
  gpio_config(&io_conf);
  */

  //Set a LEDC timer for PWM
  ledc_timer_config_t timer_conf;
  timer_conf.bit_num = LEDC_TIMER_15_BIT;
  timer_conf.freq_hz = 50; //50 = 20ms
  timer_conf.speed_mode = LEDC_HIGH_SPEED_MODE;
  timer_conf.timer_num = LEDC_TIMER_0;
  ledc_timer_config(&timer_conf);

  //Set a LEDC channel
  ledc_channel_config_t ledc_conf;
  ledc_conf.channel = LEDC_CHANNEL_0;
  ledc_conf.duty = 3276;
  ledc_conf.gpio_num = 4;
  ledc_conf.intr_type = LEDC_INTR_DISABLE;
  ledc_conf.speed_mode = LEDC_HIGH_SPEED_MODE;
  ledc_conf.timer_sel = LEDC_TIMER_0;
  ledc_channel_config(&ledc_conf);

  while(1)
  {

	  for (int duty_cycle = 1638; duty_cycle < 3276; duty_cycle += 20)
	  {
		ledc_set_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0, duty_cycle);
		ledc_update_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0);
		SLEEP(10);
	  }

	  for (int duty_cycle = 3276; duty_cycle > 1638; duty_cycle -= 20)
	  {
			ledc_set_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0, duty_cycle);
			ledc_update_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0);
			SLEEP(10);
	  }
  }
}
