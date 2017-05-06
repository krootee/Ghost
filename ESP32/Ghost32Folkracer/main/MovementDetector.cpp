/*
 * MovementDetector.cpp
 *
 *  Created on: May 6, 2017
 *      Author: frode
 */

#include "MovementDetector.h"

namespace Sensors {

MovementDetector::MovementDetector() {
	// TODO Auto-generated constructor stub

}

void MovementDetector::SaveIRSensorReadings(std::vector<int> data)
{
	this->previousData = this->currentData;
	this->currentData = data;
}

bool MovementDetector::IsStandingStill() {
	//http://stackoverflow.com/questions/6248044/c-comparing-two-vectors
	return (equal(this->previousData.begin(), this->previousData.end(), this->currentData.begin()));
}

} /* namespace Sensors */
