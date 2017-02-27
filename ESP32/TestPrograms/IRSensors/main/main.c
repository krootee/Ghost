#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include <esp_log.h>
#include "sdkconfig.h"

/*
 * Testprogram for using a TCA9548 I2C multiplexer, and the IR sensors (which I forget the name of...) with ESP32
 * See Kolbans book, p. 202.
 * Frode Lillerud, NorBot, febuary 2017
 */

#define SDA_GPIO = 25;
#define SCL_GPIO = 23;

void app_main()
{
  //Configure as I2C master
  i2c_config_t conf;
  conf.mode = I2C_MODE_MASTER;
  conf.sda_io_num = SDA_GPIO;
  conf.scl_io_num = SCL_GPIO;
  conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
  conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
  conf.master.clk_speed = 100000; //100kHz
  i2c_param_config(I2C_NUM_0, &conf);

  i2c_driver_install(I2C_NUM_0, I2C_MODE_MASTER, 0, 0, 0);
}
