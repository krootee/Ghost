#include <driver/i2c.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>
#include "sdkconfig.h"

/*
 * ESP32 driver for the I2C based TMP102 temperature sensor.
 * Frode Lillerud, febuary 2017
 */

 #define SDA_PIN 14
 #define SCL_PIN 13
 #define TMP102_ADDR 0x21

void task_tmp102(void *ignore)
{
  ESP_LOGD("TMP102", "Starting TMP102 task");

  //Configure ESP32 as I2C master
  i2c_config_t conf;
  conf.mode = I2C_MODE_MASTER;
  conf.sda_io_num = SDA_PIN;
  conf.scl_io_num = SCL_PIN;
  conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
  conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
  conf.master.clk_speed = 100000;
  i2c_param_config(I2C_NUM_0, &conf);

  i2c_driver_install(I2C_NUM_0, I2C_MODE_MASTER, 0, 0, 0);

  //Read temperature, and print it out.
  esp_err_t error;
  while (1)
  {
    //Prepare an I2C command
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (TMP102_ADDR << 1) | I2C_MASTER_WRITE, 1);
    i2c_master_stop(cmd);

    //Send the I2C command
    portBASE_TYPE timeout = 500 / portTICK_PERIOD_MS;
    error = i2c_master_cmd_begin(I2C_NUM_0, cmd, timeout);

    if (error == 0) //no error
    {
      printf("Temperature: ??\n");
    }
    else
    {
      printf("ERROR: %d\n", error);
    }

    i2c_cmd_link_delete(cmd); //why?

    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
