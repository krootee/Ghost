/*
 * IRSensor.h
 *
 *  Created on: Apr 30, 2017
 *      Author: frode
 */

#ifndef MAIN_SENSORS_IRSENSOR_H_
#define MAIN_SENSORS_IRSENSOR_H_

#include "IRSensorConfig.h"

namespace Sensors {

	class IRSensor {
	public:
		IRSensor(IRSensorConfig);

		int getDistance();
	private:
		IRSensorConfig config;

	};

}

#endif /* MAIN_SENSORS_IRSENSOR_H_ */
