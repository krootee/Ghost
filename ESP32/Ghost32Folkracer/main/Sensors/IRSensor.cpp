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

	int IRSensor::getDistance(){
		return 99;
	}

}
