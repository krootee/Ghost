/*
 * IRSensorConfig.h
 *
 *  Created on: Apr 30, 2017
 *      Author: frode
 */

#ifndef MAIN_SENSORS_IRSENSORCONFIG_H_
#define MAIN_SENSORS_IRSENSORCONFIG_H_

namespace Sensors {

class IRSensorConfig {
public:
	IRSensorConfig();

	double mounting_angle;
	double offset_x_mm;
	double offset_y_mm;
};

} /* namespace Sensors */

#endif /* MAIN_SENSORS_IRSENSORCONFIG_H_ */
