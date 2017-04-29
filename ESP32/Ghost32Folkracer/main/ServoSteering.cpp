/*
 * ServoSteering.cpp
 *
 *  Created on: Apr 17, 2017
 *      Author: frode
 */

#include "ServoSteering.h"

ServoSteering::ServoSteering(int pin) : PWM(pin, LEDC_CHANNEL_1, LEDC_TIMER_1){
	// TODO Auto-generated constructor stub

}

ServoSteering::~ServoSteering() {
	// TODO Auto-generated destructor stub
}

void ServoSteering::TurnTo(int angle)
{
	this->SetDutyCycle(angle); //TODO
}
