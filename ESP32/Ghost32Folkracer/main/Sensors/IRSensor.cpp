/*
 * IRSensor.cpp
 *
 *  Created on: Apr 30, 2017
 *      Author: frode
 */

#include "IRSensor.h"

namespace Sensors {

IRSensor::IRSensor(IRSensorConfig conf) {
	this->config = conf;
}

int IRSensor::getDistance() {
	//Read SHIFT register to get value used later when calculating distance
	uint8_t shift = 0;

	//Point to SHIFT register
	i2c_cmd_handle_t cmd = i2c_cmd_link_create();
	i2c_master_start(cmd);
	i2c_master_write_byte(cmd, (IRSENSOR_ADDR << 1) | I2C_MASTER_WRITE, 1);
	i2c_master_write_byte(cmd, SHIFT_REG, 1);
	i2c_master_stop(cmd);
	i2c_master_cmd_begin(I2C_NUM_0, cmd, 10000 / portTICK_PERIOD_MS);
	i2c_cmd_link_delete(cmd);

	//Read one byte from SHIFT register
	cmd = i2c_cmd_link_create();
	i2c_master_start(cmd);
	i2c_master_write_byte(cmd, (IRSENSOR_ADDR << 1) | I2C_MASTER_READ, 1);
	i2c_master_read_byte(cmd, &shift, 1);
	i2c_master_stop(cmd);
	i2c_master_cmd_begin(I2C_NUM_0, cmd, 10000 / portTICK_PERIOD_MS);
	i2c_cmd_link_delete(cmd);

	//Point to DISTANCE register
	cmd = i2c_cmd_link_create();
	i2c_master_start(cmd);
	i2c_master_write_byte(cmd, (IRSENSOR_ADDR << 1) | I2C_MASTER_WRITE, 1);
	i2c_master_write_byte(cmd, DISTANCE_REG, 1);
	i2c_master_stop(cmd);
	i2c_master_cmd_begin(I2C_NUM_0, cmd, 10000 / portTICK_PERIOD_MS);
	i2c_cmd_link_delete(cmd);

	uint8_t data[2];

	//Read two bytes from DISTANCE register
	cmd = i2c_cmd_link_create();
	i2c_master_start(cmd);
	i2c_master_write_byte(cmd, (IRSENSOR_ADDR << 1) | I2C_MASTER_READ, 1);
	i2c_master_read_byte(cmd, data, 0);
	i2c_master_read_byte(cmd, data + 1, 1);
	i2c_master_stop(cmd);
	i2c_master_cmd_begin(I2C_NUM_0, cmd, 10000 / portTICK_PERIOD_MS);
	i2c_cmd_link_delete(cmd);

	short high = data[0], low = data[1];

	int distance_in_cm = (high * 16 + low) / 16 / (int) pow(2, shift);

	return distance_in_cm;
}

esp_err_t detectDevice() {
	//Write to the I2C device. If it responds with an ACK then it exists.
	i2c_cmd_handle_t cmd = i2c_cmd_link_create();
	i2c_master_start(cmd);
	i2c_master_write_byte(cmd, (IRSENSOR_ADDR << 1) | I2C_MASTER_WRITE, 1);
	i2c_master_stop(cmd);

	//Send the I2C command
	portBASE_TYPE timeout = 10000 / portTICK_PERIOD_MS;
	esp_err_t result = i2c_master_cmd_begin(I2C_NUM_0, cmd, timeout);
	i2c_cmd_link_delete(cmd);

	return result;
}

}
