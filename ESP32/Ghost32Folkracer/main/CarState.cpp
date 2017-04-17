/*
 * CarState.cpp
 *
 *  Created on: Apr 16, 2017
 *      Author: frode
 */

#include "CarState.h"

CarState::CarState() {
	// TODO Auto-generated constructor stub

}

CarState& CarState::getInstance() {
	//Singleton
	static CarState instance;
	return instance;
}

void CarState::motor_set_speed(int speed)
{
	this->DesiredSpeed = speed;
}

CarState::~CarState() {
	// TODO Auto-generated destructor stub
}

