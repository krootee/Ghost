/*
 * MovementDetector.h
 *
 *  Created on: May 6, 2017
 *      Author: frode
 */

#ifndef MAIN_MOVEMENTDETECTOR_H_
#define MAIN_MOVEMENTDETECTOR_H_

#include <vector>

namespace Sensors {

class MovementDetector {
public:
	MovementDetector();
	bool IsStandingStill();
	void SaveIRSensorReadings(std::vector<int>);
private:
	std::vector<int> currentData;
	std::vector<int> previousData;

	//std::array<std::vector<int>, 10> v; // default construction
	//std::array<int> test;
	//std::fill(v.begin(), v.end(), std::vector<int>(5));
};

} /* namespace Sensors */

#endif /* MAIN_MOVEMENTDETECTOR_H_ */
