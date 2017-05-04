/*
 * ServoSteering.cpp
 *
 *  Created on: Apr 17, 2017
 *      Author: frode
 */

#include "ServoSteering.h"

ServoSteering::ServoSteering(int pin, int min, int max) : PWM(pin, LEDC_CHANNEL_1, LEDC_TIMER_1){

	this->min_duty_cycle = min;
	this->max_duty_cycle = max;

}

ServoSteering::~ServoSteering() {
	// TODO Auto-generated destructor stub
}

void ServoSteering::TurnTo(int percent)
{
	int duty_cycle;
	duty_cycle = (((this->max_duty_cycle - this->min_duty_cycle)*percent)/100)+this->min_duty_cycle;

	//ESP_LOGI("ServoSteering", "DutyCycle: %d", duty_cycle);

	this->SetDutyCycle(duty_cycle);
}
