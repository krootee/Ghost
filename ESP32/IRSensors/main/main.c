#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include <esp_log.h>
#include "sdkconfig.h"
//#include "i2cscanner.c"
//#include "tmp102.c"
#include "irsensor_gp2y0e02b.c"
#include "tca9548.c"

/*
 * Testprogram for using a TCA9548 I2C multiplexer, and the IR sensors GP2Y0E02B with ESP32
 * See Kolbans book, p. 202.
 * Frode Lillerud, NorBot, febuary 2017
 */

/*
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
*/

#define SDA_PIN GPIO_NUM_13 //33
#define SCL_PIN GPIO_NUM_14 //32

void app_main()
{

  //setup_i2c();

  //vTaskDelay(10000 / portTICK_PERIOD_MS);

  //xTaskCreate(&task_i2cscanner, "I2Cscanner",4096, NULL, 5, NULL);
  //xTaskCreate(&task_tmp102, "TMP102",4096, NULL, 5, NULL);

  i2c_config_t conf;
  conf.mode = I2C_MODE_MASTER;
  conf.sda_io_num = SDA_PIN;
  conf.scl_io_num = SCL_PIN;
  conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
  conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
  conf.master.clk_speed = 1000000;
  i2c_param_config(I2C_NUM_0, &conf);

  i2c_driver_install(I2C_NUM_0, I2C_MODE_MASTER, 0, 0, 0);

  vTaskDelay(200/portTICK_PERIOD_MS);

  tca9548_set_channel(1);

  while(1)
  {
    //Read temperature sensor
    //esp_err_t result = tmp102_detect_device();
    //if (result == ESP_OK)
    // printf("Celsius: %g\n", tmp102_get_temperature());
    //else
    // printf("Unable to detect tmp102 device. Error: %d\n", result);

    for (int i = 0; i <= 8; i++)
    //for (int i = 0; (1 << i) != 128; i++)
    {
    	ESP_LOGI(tag, "Setting channel: %d\n", i);
     tca9548_set_channel(i);
     uint8_t c = tca9548_get_channel();
     ESP_LOGI(tag, "Getting channel: %d\n", c);
    //
    //   printf("Active channel: %d\n", i);
    //
    //   //Read distance sensor
    esp_err_t irsensor_exists = irsensor_detect_device();
    if (irsensor_exists == ESP_OK)
     printf("[OK] Distance: %d\n", irsensor_get_distance());
    else
     printf("[ERROR] Unable to detect IR-sensor device\n");
    }

//printf("Hello\n");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
