#include <driver/i2c.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>
#include "sdkconfig.h"
#include <math.h>

/*
 * Driver for the GP2Y0E02B IR sensor
 * Frode Lillerud, march 2017
 */

#define IRSENSOR_ADDR 0x80 // >> 1 //TODO, run i2cscanner to find address

esp_err_t irsensor_detect_device()
{
  //Write to the I2C device. If it responds with an ACK then it exists.
  i2c_cmd_handle_t cmd = i2c_cmd_link_create();
  i2c_master_start(cmd);
  i2c_master_write_byte(cmd, (IRSENSOR_ADDR << 1) | I2C_MASTER_WRITE, 1);
  i2c_master_stop(cmd);

  //Send the I2C command
  portBASE_TYPE timeout = 10 / portTICK_PERIOD_MS;
  esp_err_t result = i2c_master_cmd_begin(I2C_NUM_0, cmd, timeout);
  i2c_cmd_link_delete(cmd);

  return result;
}

int irsensor_get_distance()
{
  //TODO: Read SHIFT register to get value used later when calculating distance
  int shift = 0;

  //Read two bytes from DISTANCE register

  short high = 0, low = 0;

  int distance_in_cm = (high * 16 + low)/16/(int)pow(2,shift);

  return distance_in_cm;
}
