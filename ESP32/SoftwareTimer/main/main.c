#include "freertos/FreeRTOS.h"
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "freertos/timers.h"

#define LED_PIN GPIO_NUM_23

const static char* tag = "SoftwareTimerExample";

static int level = 0;

esp_err_t event_handler(void *ctx, system_event_t *event)
{
    return ESP_OK;
}

void ToggleLEDTimer(TimerHandle_t timer)
{
  ESP_LOGI(tag, "Timer TICK!");

  //Toggle LED
  level = !level;
  gpio_set_level(LED_PIN, level);
}

void task_starttimer(void* p)
{
  TimerHandle_t t = xTimerCreate("Toggle LED timer", pdMS_TO_TICKS(500), pdTRUE, NULL, ToggleLEDTimer);
  if (t == NULL)
  {
    ESP_LOGE(tag, "Unable to create timer");
  }
  else
  {
    ESP_LOGI(tag, "Timer created");
    xTimerStart(t, 1);
  }

  while (1)
  {
    vTaskDelay(pdMS_TO_TICKS(20000));
  }
}

void app_main(void)
{
  gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

  xTaskCreate(&task_starttimer, "Start timer", 4096, NULL, 2, NULL);

    // gpio_set_direction(GPIO_NUM_4, GPIO_MODE_OUTPUT);
    // int level = 0;
    // while (true) {
    //     gpio_set_level(GPIO_NUM_4, level);
    //     level = !level;
    //     vTaskDelay(300 / portTICK_PERIOD_MS);
    // }
}
