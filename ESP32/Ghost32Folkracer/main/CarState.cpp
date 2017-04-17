/*
 * CarState.cpp
 *
 *  Created on: Apr 16, 2017
 *      Author: frode
 */

#include <iostream>
#include "CarState.h"

using namespace std;

CarState::CarState() {
	// TODO Auto-generated constructor stub

}

bool CarState::instanceFlag = false;
CarState* CarState::instance = NULL;

CarState* CarState::getInstance() {

	if (!instanceFlag)
	{
		instance = new CarState();
		instanceFlag = true;
		return instance;
	}
	else
	{
		return instance;
	}
}

void CarState::motor_set_speed(int speed)
{
	this->DesiredSpeed = speed;
}

CarState::~CarState() {
	instanceFlag = false;
}

