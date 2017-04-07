#include "freertos/FreeRTOS.h"
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
#include "freertos/task.h"
//#include "i2cscanner.c"

esp_err_t event_handler(void *ctx, system_event_t *event)
{
    return ESP_OK;
}

void app_main(void)
{
  //xTaskCreate(&task_i2cscanner, "I2Cscanner",4096, NULL, 5, NULL);

  while (true) {
    vTaskDelay(300 / portTICK_PERIOD_MS);
    printf("Test");
  }
}
