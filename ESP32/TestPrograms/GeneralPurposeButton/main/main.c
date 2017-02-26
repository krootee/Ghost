#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include <esp_log.h>

#define LED_GPIO GPIO_NUM_5
#define BUTTON_GPIO GPIO_SEL_0

//static xQueueHandle queue_handle = NULL;

void button_pressed_handler(void *args)
{
  printf("Button pressed");
  int btn_state = gpio_get_level(BUTTON_GPIO);
  gpio_set_level(LED_GPIO,btn_state);
  //uint32_t gpio_num = (uint32_t)args;
  //xQueueSendFromISR(queue_handle, &gpio_num, NULL);
}

void  setup_button_to_led(void *pvParameter)
{
//  printf("LED configured\n");
//  gpio_set_level(LED_GPIO, 1);

  //Configure interrupt and add handler (ISR = Interrupt Service Routine)
  gpio_install_isr_service(0);
  gpio_isr_handler_add(BUTTON_GPIO, button_pressed_handler, (void*)BUTTON_GPIO);
  printf("Interrupt configured\n");

  //Wait for button press
  //uint32_t io_num;
  while (1)
  {
    //if (xQueueReceive(queue_handle, &io_num, portMAX_DELAY)){
//      printf("TICK!");
    //}
    ESP_LOGD("test", "Waiting for button press....");
  }
}

void app_main()
{
	printf("Developing via Eclipse\n");
  //gpio_pad_select_gpio(BUTTON_GPIO);

  //Configure button
  gpio_config_t btn_config;
  btn_config.intr_type = GPIO_INTR_ANYEDGE; //Enable interrupt on positive/negative flank
  btn_config.mode = GPIO_MODE_INPUT;        //Input
  btn_config.pin_bit_mask = BUTTON_GPIO;    //Set pin where button is connected
  btn_config.pull_up_en = GPIO_PULLUP_ENABLE; //Disable pullup
  btn_config.pull_down_en = GPIO_PULLDOWN_DISABLE; //Enable pulldown
  gpio_config(&btn_config);

  printf("Button configured\n");

  //Configure LED
  gpio_config_t led_config;
  led_config.intr_type = GPIO_INTR_DISABLE;
  led_config.pin_bit_mask = LED_GPIO;
  led_config.mode = GPIO_MODE_OUTPUT;
  led_config.pull_up_en = 0;
  led_config.pull_down_en = 1;
  gpio_config(&led_config);
  printf("LED configured\n");

  gpio_pad_select_gpio(LED_GPIO);

  //queue_handle = xQueueCreate(10, sizeof(uint32_t)); //Create a queue that can store ten uint's

  xTaskCreate(&setup_button_to_led, "buttonToLED", 4096, NULL, 5, NULL);

  while (1)
  {
    vTaskDelay(1000 / portTICK_RATE_MS);
    //gpio_set_level(BUTTON_GPIO, 1);
  }
}
