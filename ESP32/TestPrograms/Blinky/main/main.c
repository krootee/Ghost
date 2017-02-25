/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

/* Can run 'make menuconfig' to choose the GPIO to blink,
   or you can edit the following line and set a number here.
*/
#define BLINK_GPIO CONFIG_BLINK_GPIO

void blink_task(void *pvParameter)
{
    /* Configure the IOMUX register for pad BLINK_GPIO (some pads are
       muxed to GPIO on reset already, but some default to other
       functions and need to be switched to GPIO. Consult the
       Technical Reference for a list of pads and their default
       functions.)
    */
    gpio_pad_select_gpio(BLINK_GPIO);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
    while(1) {
        /* Blink off (output low) */
        gpio_set_level(BLINK_GPIO, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        /* Blink on (output high) */
        gpio_set_level(BLINK_GPIO, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void helloWorldTask(void *pvParameter)
{
  while (1)
  {
    printf("Hello from ESP32!\n");
    vTaskDelay(800 / portTICK_PERIOD_MS);
  }
}

void app_main()
{
  //Initialize the non-volatile flash, which MAY be used later.
  nvs_flash_init();

  /*Create an RTOS task, and add it to list of tasks ready to run.
  Parameters;
  - pvTaskCode = pointer to the task to run
  - pcName = descriptive name of the task
  - usStackDepth = number of words to allocate for use as the task's stack.
  - pvParameters = value passed to othe created task as the task's parameters
  - uxPriority = Priority.
  - pxCreatedTask = used to pass handle. Can be NULL.
  */
  xTaskCreate(&blink_task, "blink_task", 512, NULL, 5, NULL);
  xTaskCreate(&helloWorldTask, "helloWorld", 4096, NULL, 4, NULL);
}
