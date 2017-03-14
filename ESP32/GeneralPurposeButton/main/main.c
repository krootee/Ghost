#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include <esp_log.h>
#include "sdkconfig.h"

/*
 * Frode Lillerud, march 2017
 */

#define LED_GPIO GPIO_NUM_32
#define BUTTON_GPIO GPIO_NUM_10

void isr_button_pressed(void *args)
{
  printf("Button pressed\n");
  int btn_state = gpio_get_level(BUTTON_GPIO);
  gpio_set_level(LED_GPIO,btn_state);
}

void task_button_to_led(void *pvParameter)
{
  //Configure button
  //gpio_pad_select_gpio(BUTTON_GPIO);
  //gpio_set_direction(BUTTON_GPIO, GPIO_MODE_INPUT);

  gpio_config_t btn_config;
  btn_config.intr_type = GPIO_INTR_ANYEDGE; 	//Enable interrupt on both rising and falling edges
  btn_config.mode = GPIO_MODE_INPUT;        	//Set as Input
  btn_config.pin_bit_mask = (1 << BUTTON_GPIO); //Bitmask
  btn_config.pull_up_en = GPIO_PULLUP_DISABLE; 	//Disable pullup
  btn_config.pull_down_en = GPIO_PULLDOWN_ENABLE; //Enable pulldown
  gpio_config(&btn_config);
  printf("Button configured\n");

  //Configure LED
  gpio_pad_select_gpio(LED_GPIO);					//Set pin as GPIO
  gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);	//Set as Output
  printf("LED configured\n");

  //Configure interrupt and add handler
  gpio_install_isr_service(0);						//Start Interrupt Service Routine service
  gpio_isr_handler_add(BUTTON_GPIO, isr_button_pressed, NULL); //Add handler of interrupt
  printf("Interrupt configured\n");

  //Wait
  while (1)
  {
      ESP_LOGI("test", "Waiting for button press....");
	  vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}

void app_main()
{
  xTaskCreate(&task_button_to_led, "buttonToLED", 2048, NULL, 5, NULL);
}
