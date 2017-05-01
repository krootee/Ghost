/*
 * IRSensor.h
 *
 *  Created on: Apr 30, 2017
 *      Author: frode
 */

#ifndef MAIN_SENSORS_IRSENSOR_H_
#define MAIN_SENSORS_IRSENSOR_H_

#include <driver/i2c.h>
#include <esp_log.h>
//#include <freertos/FreeRTOS.h>
//#include <freertos/task.h>
//#include <stdio.h>
//#include "sdkconfig.h"
#include <math.h>

#include "IRSensorConfig.h"

#define IRSENSOR_ADDR 0x40
#define SHIFT_REG 0x35
#define DISTANCE_REG 0x5E

#define ACK 0x1
#define NACK 0x0

namespace Sensors {

	class IRSensor {
	public:
		IRSensor(IRSensorConfig);

		int getDistance();

		esp_err_t detectDevice();
	private:
		IRSensorConfig config;

	};

}

#endif /* MAIN_SENSORS_IRSENSOR_H_ */
