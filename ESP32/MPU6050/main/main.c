#include "freertos/FreeRTOS.h"
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "nvs_flash.h"
#include "driver/gpio.h"

/*
Example program for MPU-6050 accelerometer.
mpu6050.c is from https://github.com/nkolban/esp32-snippets/tree/master/hardware/accelerometers
*/


#include "mpu6050.c"

esp_err_t event_handler(void *ctx, system_event_t *event)
{
    return ESP_OK;
}

void app_main(void)
{
    xTaskCreate(&task_mpu6050, "task_mpu6050", 4096, NULL, 5, NULL);

    while (true) {
        vTaskDelay(300 / portTICK_PERIOD_MS);
    }
}
