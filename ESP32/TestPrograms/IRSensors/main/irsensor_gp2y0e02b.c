// #include <driver/i2c.h>
// #include <esp_log.h>
// #include <freertos/FreeRTOS.h>
// #include <freertos/task.h>
// #include <stdio.h>
// #include "sdkconfig.h"
// #include <math.h>
//
// /*
//  * Driver for the GP2Y0E02B IR sensor
//  * Frode Lillerud, march 2017
//  */
//
//  //See http://www.robot-electronics.co.uk/files/arduino_gp2y0e02b.ino
//
// #define IRSENSOR_ADDR 0x80 // >> 1 //TODO, run i2cscanner to find address
// #define SHIFT_REG 0x35
// #define DISTANCE_REG 0x5E
//
// #define ACK 0x1
// #define NACK 0x0
//
// esp_err_t irsensor_detect_device()
// {
//   //Write to the I2C device. If it responds with an ACK then it exists.
//   i2c_cmd_handle_t cmd = i2c_cmd_link_create();
//   i2c_master_start(cmd);
//   i2c_master_write_byte(cmd, (IRSENSOR_ADDR << 1) | I2C_MASTER_WRITE, 1);
//   i2c_master_stop(cmd);
//
//   //Send the I2C command
//   portBASE_TYPE timeout = 10 / portTICK_PERIOD_MS;
//   esp_err_t result = i2c_master_cmd_begin(I2C_NUM_0, cmd, timeout);
//   i2c_cmd_link_delete(cmd);
//
//   return result;
// }
//
// int irsensor_get_distance()
// {
//   //Read SHIFT register to get value used later when calculating distance
//   int shift = 0;
//
//   //Point to SHIFT register
//   i2c_cmd_handle_t cmd = i2c_cmd_link_create();
// 	i2c_master_start(cmd);
// 	i2c_master_write_byte(cmd, (IRSENSOR_ADDR << 1) | I2C_MASTER_WRITE, 1);
// 	i2c_master_write_byte(cmd, SHIFT_REG, 1);
// 	i2c_master_stop(cmd);
// 	i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000/portTICK_PERIOD_MS);
// 	i2c_cmd_link_delete(cmd);
//
//   //Read one byte from SHIFT register
//   cmd = i2c_cmd_link_create();
//   i2c_master_start(cmd);
//   i2c_master_write_byte(cmd, (IRSENSOR_ADDR << 1) | I2C_MASTER_READ, 1);
//   i2c_master_read_byte(cmd, shift, 1);
//   i2c_master_stop(cmd);
//   i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000/portTICK_PERIOD_MS);
//   i2c_cmd_link_delete(cmd);
//
//   //Point to DISTANCE register
//   cmd = i2c_cmd_link_create();
// 	i2c_master_start(cmd);
// 	i2c_master_write_byte(cmd, (IRSENSOR_ADDR << 1) | I2C_MASTER_WRITE, 1);
// 	i2c_master_write_byte(cmd, DISTANCE_REG, 1);
// 	i2c_master_stop(cmd);
// 	i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000/portTICK_PERIOD_MS);
// 	i2c_cmd_link_delete(cmd);
//
//   uint8_t data[2];
//
//   //Read two bytes from DISTANCE register
//   cmd = i2c_cmd_link_create();
//   i2c_master_start(cmd);
//   i2c_master_write_byte(cmd, (IRSENSOR_ADDR << 1) | I2C_MASTER_READ, 1);
//   i2c_master_read_byte(cmd, data, 0);
//   i2c_master_read_byte(cmd, data+1, 1);
//   i2c_master_stop(cmd);
//   i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000/portTICK_PERIOD_MS);
//   i2c_cmd_link_delete(cmd);
//
//   short high = data[0], low = data[1];
//
//   int distance_in_cm = (high * 16 + low)/16/(int)pow(2,shift);
//
//   return distance_in_cm;
// }
