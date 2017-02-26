#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
//#include "freertos/queue.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include <esp_log.h>

#define LED_GPIO GPIO_SEL_5
#define BUTTON_GPIO GPIO_SEL_0

void button_pressed_handler(void *args)
{
  printf("Event handler says: Button pressed\n");
  int btn_state = gpio_get_level(BUTTON_GPIO);
  gpio_set_level(LED_GPIO,btn_state);
}

void setup_button_to_led(void *pvParameter)
{
	//Configure button
	gpio_config_t btn_config;
	btn_config.intr_type = GPIO_INTR_ANYEDGE; //Enable interrupt on positive/negative flank
	btn_config.mode = GPIO_MODE_INPUT;        //Input
	btn_config.pin_bit_mask = (1 << BUTTON_GPIO);    //Set pin where button is connected
	btn_config.pull_up_en = GPIO_PULLUP_DISABLE; //Disable pullup
	btn_config.pull_down_en = GPIO_PULLDOWN_ENABLE; //Enable pulldown
	gpio_config(&btn_config);
	printf("Button configured\n");

	//Configure LED
	/*gpio_config_t led_config;
	led_config.intr_type = GPIO_INTR_DISABLE;
	led_config.pin_bit_mask = (1 << LED_GPIO);
	led_config.mode = GPIO_MODE_OUTPUT;
	led_config.pull_up_en = 0;
	led_config.pull_down_en = 1;
	gpio_config(&led_config);
	printf("LED configured\n");
*/
	gpio_pad_select_gpio(LED_GPIO);
	gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);


  //Configure interrupt and add handler (ISR = Interrupt Service Routine)
  gpio_install_isr_service(0);
  gpio_isr_handler_add(BUTTON_GPIO, button_pressed_handler, NULL);
  printf("Interrupt configured\n");

  //Wait for button press
  //uint32_t io_num;
  while (1)
  {
    //if (xQueueReceive(queue_handle, &io_num, portMAX_DELAY)){
//      printf("TICK!");
    //}
    ESP_LOGD("test", "Waiting for button press....");
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}

void app_main()
{
	/* Alternative 1 */
//	//Configure button
//	gpio_pad_select_gpio(GPIO_NUM_0);
//	gpio_set_direction(GPIO_NUM_0, GPIO_MODE_INPUT);
//
//	//Configure LED
//	gpio_pad_select_gpio(GPIO_NUM_5);
//	gpio_set_direction(GPIO_NUM_5, GPIO_MODE_OUTPUT);
//
//	while(1)
//	{
//		//Set LED to same value as button
//		int level = gpio_get_level(GPIO_NUM_0);
//		gpio_set_level(GPIO_NUM_5, level);
//		vTaskDelay(10/portTICK_RATE_MS);
//	}

	/* Alternative 2 */

  xTaskCreate(&setup_button_to_led, "buttonToLED", 4096, NULL, 5, NULL);

//  while (1)
//  {
//    vTaskDelay(1000 / portTICK_RATE_MS);
//    //gpio_set_level(BUTTON_GPIO, 1);
//  }
}
