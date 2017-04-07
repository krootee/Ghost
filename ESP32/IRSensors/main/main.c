#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include <esp_log.h>
#include "sdkconfig.h"
#include "i2cscanner.c"
#include "tmp102.c"
#include "irsensor_gp2y0e02b.c"

/*
 * Testprogram for using a TCA9548 I2C multiplexer, and the IR sensors GP2Y0E02B with ESP32
 * See Kolbans book, p. 202.
 * Frode Lillerud, NorBot, febuary 2017
 */

void setup_i2c()
{
  //Configure as I2C master
  i2c_config_t conf;
  conf.mode = I2C_MODE_MASTER;
  conf.sda_io_num = SDA_PIN;
  conf.scl_io_num = SCL_PIN;
  conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
  conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
  conf.master.clk_speed = 100000;
  ESP_ERROR_CHECK(i2c_param_config(I2C_NUM_0, &conf));

  ESP_ERROR_CHECK(i2c_driver_install(I2C_NUM_0, I2C_MODE_MASTER, 0, 0, 0));
}

void app_main()
{

  //setup_i2c();

  //vTaskDelay(10000 / portTICK_PERIOD_MS);

  xTaskCreate(&task_i2cscanner, "I2Cscanner",4096, NULL, 5, NULL);
  //xTaskCreate(&task_tmp102, "TMP102",4096, NULL, 5, NULL);

  while(1)
  {
    //Read temperature senanglesor
    // esp_err_t result = tmp102_detect_device();
    // if (result == ESP_OK)
    //   printf("Celsius: %g\n", tmp102_get_temperature());
    // else
    //   printf("Unable to detect tmp102 device. Error: %d\n", result);

    //Read distance sensor
    esp_err_t irsensor_exists = irsensor_detect_device();
    if (irsensor_exists == ESP_OK)
      printf("Distance: %d\n", irsensor_get_distance());
    else
      printf("Unable to detect IR-sensor device\n");

    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
