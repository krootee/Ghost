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

 //https://github.com/espressif/esp-idf/blob/master/examples/peripherals/i2c/main/i2c_test.c
 //https://github.com/nkolban/esp32-snippets/blob/master/hardware/compass/hmc5883l.c

//#define SDA_PIN 14
//#define SCL_PIN 13
#define TMP102_ADDR 0x48

#define ACK_CHECK_ON 0x1
#define ACK_CHECK_OFF 0x0
#define ACK 0x1
#define NACK 0x0

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))

uint8_t twos_complement(uint8_t val)
{
    return -(unsigned int)val;
}

//Writes the TMP102 address to the I2C bus, and waits for an ACK.
esp_err_t tmp102_detect_device()
{
  //Write to the I2C device. If it responds with an ACK then it exists.
  i2c_cmd_handle_t cmd = i2c_cmd_link_create();
  i2c_master_start(cmd);
  i2c_master_write_byte(cmd, (TMP102_ADDR << 1) | I2C_MASTER_WRITE, 1);
  i2c_master_stop(cmd);

  //Send the I2C command
  portBASE_TYPE timeout = 10 / portTICK_PERIOD_MS;
  esp_err_t result = i2c_master_cmd_begin(I2C_NUM_0, cmd, timeout);
  i2c_cmd_link_delete(cmd);

  return result;
}

float tmp102_get_temperature()
{
  i2c_cmd_handle_t cmd = i2c_cmd_link_create();

  uint8_t data[2];

  ESP_ERROR_CHECK(i2c_master_start(cmd));
  ESP_ERROR_CHECK(i2c_master_write_byte(cmd, (TMP102_ADDR << 1 | I2C_MASTER_READ), ACK_CHECK_ON));
  ESP_ERROR_CHECK(i2c_master_read_byte(cmd, data, ACK));
  ESP_ERROR_CHECK(i2c_master_read_byte(cmd, data+1, NACK));
  ESP_ERROR_CHECK(i2c_master_stop(cmd));

  ESP_ERROR_CHECK(i2c_master_cmd_begin(I2C_NUM_0, cmd, 100 / portTICK_PERIOD_MS));
  i2c_cmd_link_delete(cmd);

  //http://forums.netduino.com/index.php?/topic/4138-tmp102-temperature-sensor/?hl=tmp102
  return ((short)((data[0] << 8) | data[1]))/256.0;
/*
  short value = (data[0] << 4) | (data[1] >> 4);
  if (value & (1 << 11)) //Is the most significant bit set?
  {
    //printf("Negative\n");
    //Negative temperature. Value is two's complement.
    return ((twos_complement(value)+1) * 0.0625) * -1;
  }
  else {
    //Positive temperature
    //float celsius = value * 0.0625;

    float celsius = data[0] + ((data[1] >> 4) * 0.0625);

    return celsius;
  }
  */
}

void task_tmp102(void *ignore)
{
  ESP_LOGD("TMP102", "Starting TMP102 task");

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
    portBASE_TYPE timeout = 100 / portTICK_PERIOD_MS;
    error = i2c_master_cmd_begin(I2C_NUM_0, cmd, timeout);
    i2c_cmd_link_delete(cmd);

    if (error == ESP_OK) //Device responded
    {
      //printf("TMP102 device responded.\n");

      vTaskDelay(30 / portTICK_RATE_MS);

      uint8_t data[2];

      cmd = i2c_cmd_link_create();
      ESP_ERROR_CHECK(i2c_master_start(cmd));
      ESP_ERROR_CHECK(i2c_master_write_byte(cmd, (TMP102_ADDR << 1 | I2C_MASTER_READ), ACK_CHECK_ON));
      ESP_ERROR_CHECK(i2c_master_read_byte(cmd, data, ACK));
      ESP_ERROR_CHECK(i2c_master_read_byte(cmd, data+1, NACK));
      ESP_ERROR_CHECK(i2c_master_stop(cmd));

      ESP_ERROR_CHECK(i2c_master_cmd_begin(I2C_NUM_0, cmd, 100 / portTICK_PERIOD_MS));
      i2c_cmd_link_delete(cmd);
      //if (ret == ESP_FAIL)
      //  printf("ESP_FAIL");

      //printf("High: %d\n", data[0]);
      //printf("Low: %d\n", data[1]);

      float temp = ((data[0] << 4) | (data[1] >> 4)) * 0.0625;

      printf("Temperature: %g\n", temp);
    }
    else
    {
      ESP_ERROR_CHECK(error);
      printf("I2C ERROR: %d\n", error);
    }

    //i2c_cmd_link_delete(cmd); //why?

    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
