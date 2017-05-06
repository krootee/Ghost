/*
 * MPU6050.cpp
 *
 *  Created on: May 6, 2017
 *      Author: frode
 */

#include "MPU6050.h"

//#undef ESP_ERROR_CHECK
//#define ESP_ERROR_CHECK(x)   do { esp_err_t rc = (x); if (rc != ESP_OK) { ESP_LOGE("err", "esp_err_t = %d", rc); assert(0 && #x);} } while(0);

namespace Sensors {

MPU6050::MPU6050() {

	//ESP_LOGD(tag, ">> mpu6050");
//	i2c_config_t conf;
//	conf.mode = I2C_MODE_MASTER;
//	conf.sda_io_num = PIN_SDA;
//	conf.scl_io_num = PIN_CLK;
//	conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
//	conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
//	conf.master.clk_speed = 100000;
//	ESP_ERROR_CHECK(i2c_param_config(I2C_NUM_0, &conf));
//	ESP_ERROR_CHECK(i2c_driver_install(I2C_NUM_0, I2C_MODE_MASTER, 0, 0, 0));


}

accelerometer_data MPU6050::Read()
{
	//const char* tag = "mpu6050";
	static char tag[] = "mpu6050";

	i2c_cmd_handle_t cmd;
	vTaskDelay(200/portTICK_PERIOD_MS);

	cmd = i2c_cmd_link_create();
	ESP_ERROR_CHECK(i2c_master_start(cmd));
	ESP_ERROR_CHECK(i2c_master_write_byte(cmd, (I2C_ADDRESS << 1) | I2C_MASTER_WRITE, 1));
	i2c_master_write_byte(cmd, MPU6050_ACCEL_XOUT_H, 1);
	ESP_ERROR_CHECK(i2c_master_stop(cmd));
	i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000/portTICK_PERIOD_MS);
	i2c_cmd_link_delete(cmd);

	cmd = i2c_cmd_link_create();
	ESP_ERROR_CHECK(i2c_master_start(cmd));
	ESP_ERROR_CHECK(i2c_master_write_byte(cmd, (I2C_ADDRESS << 1) | I2C_MASTER_WRITE, 1));
	i2c_master_write_byte(cmd, MPU6050_PWR_MGMT_1, 1);
	i2c_master_write_byte(cmd, 0, 1);
	ESP_ERROR_CHECK(i2c_master_stop(cmd));
	i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000/portTICK_PERIOD_MS);
	i2c_cmd_link_delete(cmd);

	uint8_t data[14];

	short accel_x;
	short accel_y;
	short accel_z;

	cmd = i2c_cmd_link_create();
	ESP_ERROR_CHECK(i2c_master_start(cmd));
	ESP_ERROR_CHECK(i2c_master_write_byte(cmd, (I2C_ADDRESS << 1) | I2C_MASTER_WRITE, 1));
	ESP_ERROR_CHECK(i2c_master_write_byte(cmd, MPU6050_ACCEL_XOUT_H, 1));
	ESP_ERROR_CHECK(i2c_master_stop(cmd));
	i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000/portTICK_PERIOD_MS);
	i2c_cmd_link_delete(cmd);

	cmd = i2c_cmd_link_create();
	ESP_ERROR_CHECK(i2c_master_start(cmd));
	ESP_ERROR_CHECK(i2c_master_write_byte(cmd, (I2C_ADDRESS << 1) | I2C_MASTER_READ, 1));

	ESP_ERROR_CHECK(i2c_master_read_byte(cmd, data,   0));
	ESP_ERROR_CHECK(i2c_master_read_byte(cmd, data+1, 0));
	ESP_ERROR_CHECK(i2c_master_read_byte(cmd, data+2, 0));
	ESP_ERROR_CHECK(i2c_master_read_byte(cmd, data+3, 0));
	ESP_ERROR_CHECK(i2c_master_read_byte(cmd, data+4, 0));
	ESP_ERROR_CHECK(i2c_master_read_byte(cmd, data+5, 1));

	//i2c_master_read(cmd, data, sizeof(data), 1);
	ESP_ERROR_CHECK(i2c_master_stop(cmd));
	i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000/portTICK_PERIOD_MS);
	i2c_cmd_link_delete(cmd);

	accel_x = (data[0] << 8) | data[1];
	accel_y = (data[2] << 8) | data[3];
	accel_z = (data[4] << 8) | data[5];
	//ESP_LOGD(tag, "accel_x: %d, accel_y: %d, accel_z: %d", accel_x, accel_y, accel_z);

	accelerometer_data d;
	d.x = accel_x;
	d.y = accel_y;
	d.z = accel_z;

	return d;
}

} /* namespace Sensors */
