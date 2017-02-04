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
  timer_conf.bit_num = LEDC_TIMER_12_BIT;
  timer_conf.freq_hz = 1000;
  timer_conf.speed_mode = LEDC_HIGH_SPEED_MODE;
  timer_conf.timer_num = LEDC_TIMER_0;
  ledc_timer_config(&timer_conf);

  //Set a LEDC channel
  ledc_channel_config_t ledc_conf;
  ledc_conf.channel = LEDC_CHANNEL_0;
  ledc_conf.duty = 220;
  ledc_conf.gpio_num = 4;
  ledc_conf.intr_type = LEDC_INTR_DISABLE;
  ledc_conf.speed_mode = LEDC_HIGH_SPEED_MODE;
  ledc_conf.timer_sel = LEDC_TIMER_0;
  ledc_channel_config(&ledc_conf);

  for (int i = 220; i < 400; i++)
  {
    ledc_conf.duty = i;
    ledc_channel_config(&ledc_conf);
    vTaskDelay(30 / portTICK_PERIOD_MS);
  }
  /*
    nvs_flash_init();
    tcpip_adapter_init();
    ESP_ERROR_CHECK( esp_event_loop_init(event_handler, NULL) );
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK( esp_wifi_init(&cfg) );
    ESP_ERROR_CHECK( esp_wifi_set_storage(WIFI_STORAGE_RAM) );
    ESP_ERROR_CHECK( esp_wifi_set_mode(WIFI_MODE_STA) );
    wifi_config_t sta_config = {
        .sta = {
            .ssid = "Skynet",
            .password = "W4r3zl4ck",
            .bssid_set = false
        }
    };
    ESP_ERROR_CHECK( esp_wifi_set_config(WIFI_IF_STA, &sta_config) );
    ESP_ERROR_CHECK( esp_wifi_start() );
    ESP_ERROR_CHECK( esp_wifi_connect() );

    gpio_set_direction(GPIO_NUM_4, GPIO_MODE_OUTPUT);
    int level = 0;
    while (true) {
        gpio_set_level(GPIO_NUM_4, level);
        level = !level;
        vTaskDelay(300 / portTICK_PERIOD_MS);
    }
    */
}
