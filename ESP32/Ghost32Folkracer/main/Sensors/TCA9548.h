/*
 * TCA9548.h
 *
 *  Created on: Apr 30, 2017
 *      Author: frode
 */

#ifndef MAIN_SENSORS_TCA9548_H_
#define MAIN_SENSORS_TCA9548_H_

#include <driver/i2c.h>
#include <esp_log.h>
//#include <freertos/FreeRTOS.h>
//#include <freertos/task.h>
//#include <stdio.h>
//#include "sdkconfig.h"
//#include <math.h>

namespace Sensors {

class TCA9548 {
public:
	TCA9548();
	esp_err_t setChannel(int);
	uint8_t getChannel();
};

} /* namespace Sensors */

#endif /* MAIN_SENSORS_TCA9548_H_ */
