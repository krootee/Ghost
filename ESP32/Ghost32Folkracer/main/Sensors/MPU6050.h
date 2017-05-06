/*
 * MPU6050.h
 *
 *  Created on: May 6, 2017
 *      Author: frode
 */

#ifndef MAIN_SENSORS_MPU6050_H_
#define MAIN_SENSORS_MPU6050_H_

#include <driver/i2c.h>
#include <esp_log.h>

#define PIN_SDA 33
#define PIN_CLK 32
#define I2C_ADDRESS 0x68 // I2C address of MPU6050

#define MPU6050_ACCEL_XOUT_H 0x3B
#define MPU6050_PWR_MGMT_1   0x6B

namespace Sensors {

struct accelerometer_data {
	int x;
	int y;
	int z;
};

class MPU6050 {
public:
	MPU6050();
	accelerometer_data Read();
};

} /* namespace Sensors */

#endif /* MAIN_SENSORS_MPU6050_H_ */
