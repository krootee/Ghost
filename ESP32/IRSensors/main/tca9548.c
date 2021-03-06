#include <driver/i2c.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>
#include <math.h>
#include "sdkconfig.h"

#define TCA_ADDRESS 0x70

#define ACK_CHECK_ON 0x1
#define ACK 0x1

const char* tag = "tca9548";

esp_err_t tca9548_set_channel(int channel)
{
  //Contact the TCA9548. Does it respond with an ACK?
  i2c_cmd_handle_t cmd = i2c_cmd_link_create();
  ESP_ERROR_CHECK(i2c_master_start(cmd));
  ESP_ERROR_CHECK(i2c_master_write_byte(cmd, (TCA_ADDRESS << 1)| I2C_MASTER_WRITE, ACK_CHECK_ON));
  //i2c_master_write_byte(cmd, (1 << channel) | I2C_MASTER_WRITE, 1 /* expect ack */);
  ESP_ERROR_CHECK(i2c_master_stop(cmd));

  //Send the I2C command
  esp_err_t result = i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000 / portTICK_PERIOD_MS);
  i2c_cmd_link_delete(cmd);

  if (result == ESP_OK)
  {
    //printf("[OK] Found TCA9548!\n");
    //The TCA9548 responded

    //Write to the register to set the active channel.
    cmd = i2c_cmd_link_create();
    ESP_ERROR_CHECK(i2c_master_start(cmd));
    ESP_ERROR_CHECK(i2c_master_write_byte(cmd, (TCA_ADDRESS << 1) | I2C_MASTER_WRITE, ACK_CHECK_ON));
    ESP_ERROR_CHECK(i2c_master_write_byte(cmd, (1 << channel), ACK));
    ESP_ERROR_CHECK(i2c_master_stop(cmd));
    result = i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000 / portTICK_PERIOD_MS);
    i2c_cmd_link_delete(cmd);

    return result;
  }
  else
  {
    //ESP_ERROR_CHECK(result);
    //printf("[ERROR] [TCA9548] I2C ERROR: %d\n", result);
    ESP_LOGE(tag, "I2C error: %d\n", result);
    return -1;
  }
}

uint8_t tca9548_get_channel()
{
  //Contact the TCA9548. Does it respond with an ACK?
  i2c_cmd_handle_t cmd = i2c_cmd_link_create();
  ESP_ERROR_CHECK(i2c_master_start(cmd));
  ESP_ERROR_CHECK(i2c_master_write_byte(cmd, (TCA_ADDRESS << 1)| I2C_MASTER_WRITE, ACK_CHECK_ON));
  //i2c_master_write_byte(cmd, (1 << channel) | I2C_MASTER_WRITE, 1 /* expect ack */);
  ESP_ERROR_CHECK(i2c_master_stop(cmd));

  //Send the I2C command
  esp_err_t result = i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000 / portTICK_PERIOD_MS);
  i2c_cmd_link_delete(cmd);

  if (result == ESP_OK)
  {
    uint8_t data;

    //Read the active channel from the IC
    cmd = i2c_cmd_link_create();
    ESP_ERROR_CHECK(i2c_master_start(cmd));
    ESP_ERROR_CHECK(i2c_master_write_byte(cmd, (TCA_ADDRESS << 1) | I2C_MASTER_READ, ACK_CHECK_ON));
    ESP_ERROR_CHECK(i2c_master_read_byte(cmd, &data, ACK));
    ESP_ERROR_CHECK(i2c_master_stop(cmd));
    ESP_ERROR_CHECK(i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000 / portTICK_PERIOD_MS));
    i2c_cmd_link_delete(cmd);
    return data;
  }
  else
  {
    //ESP_ERROR_CHECK(result);
    //printf("[ERROR] [TCA9548] I2C ERROR: %d\n", result);
    ESP_LOGE(tag, "I2C error: %d\n", result);
    return -1;
  }
}
