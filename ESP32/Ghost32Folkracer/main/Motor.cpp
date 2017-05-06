/*
 * Motor.cpp
 *
 *  Created on: Apr 14, 2017
 *      Author: frode
 */

#include "Motor.h"

const char* tag = "Motor";

Motor::Motor(int pin, int min, int max) : PWM (pin, LEDC_CHANNEL_0, LEDC_TIMER_0)
{
	this->max = max;
	this->min = min;
	this->current_duty_cycle = ((max-min)/2)+min; //center
	this->center = ((max-min)/2)+min; //center
	this->enabled = false;
	this-> waiting_for_direction_change = false;
}


Motor::~Motor() {
	// TODO Auto-generated destructor stub
}

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
	//https://www.arduino.cc/en/reference/map
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void Motor::ToggleEnable()
{
	//ESP_LOGI(tag, "SetEnable %d", enable);
	this->enabled = !this->enabled;
}

//100 is full forward, 0 is stop, -100 is full reverse
void Motor::SetSpeed(int percent)
{
	//if (!this->enabled)
//		percent = 0;

	//TODO, handle negative percent
	//int duty_cycle;
	//duty_cycle = (((this->max - this->min)*percent)/100)+this->min;


	int target_duty_cycle;
	if (this->current_direction == eDirection::FORWARD)
		target_duty_cycle = map(percent, 0, 100, this->center, this->min);
	else
		target_duty_cycle = map(percent, 0, 100, this->center, this->max);
	ESP_LOGI(tag, "Target Duty cycle: %d", target_duty_cycle);

	//Change speed softly
//	int soft_step_size = 2;
//	while (abs(this->current_duty_cycle - target_duty_cycle) > soft_step_size)
//	{
//		if (this->current_duty_cycle > target_duty_cycle)
//			this->current_duty_cycle-=soft_step_size;
//		else
//			this->current_duty_cycle+=soft_step_size;
//		this->SetDutyCycle(this->current_duty_cycle);
//		vTaskDelay(pdMS_TO_TICKS(10));
//	}

//	if (this->current_duty_cycle > this->center && target_duty_cycle <= this->center)
//	{
//		this->current_duty_cycle = this->center;
//		this->SetDutyCycle(this->center);
//		vTaskDelay(pdMS_TO_TICKS(3000));
//	}
//	if (this->current_duty_cycle < this->center && target_duty_cycle >= this->center)
//	{
//		this->current_duty_cycle = this->center;
//		this->SetDutyCycle(this->center);
//		vTaskDelay(pdMS_TO_TICKS(3000));
//	}

	this->current_duty_cycle = target_duty_cycle;
	this->SetDutyCycle(target_duty_cycle);
}

void Motor::SetDirection(eDirection direction)
{
//	if (!this->enabled)
//		return;

	if (direction != this->current_direction && !this->waiting_for_direction_change) //about to change direction
	{
		this->waiting_for_direction_change = true;
		this->SetSpeed(0);
		vTaskDelay(pdMS_TO_TICKS(1500));
		this->current_direction = direction;
		this->waiting_for_direction_change = false;
	}
}

void Motor::calibrate()
{
	//max: 3400
	//min: 1800
	//center: 2460

	//Maximum throttle
	ESP_LOGI(tag, "Calibration: MAX...");
	this->SetDutyCycle(this->max);
	vTaskDelay(3000 / portTICK_PERIOD_MS); //Delay for 2.5 seconds

	//Minimum throttle
	ESP_LOGI(tag, "Calibration: MIN...");
	this->SetDutyCycle(this->min);
	vTaskDelay(3000 / portTICK_PERIOD_MS); //Delay for 2.5 seconds

	//Center
	ESP_LOGI(tag, "Calibration: CENTER...");
	int center = ((this->max - this->min)/2)+this->min;
	this->SetDutyCycle(center);
	vTaskDelay(3000 / portTICK_PERIOD_MS); //Delay for 2.5 seconds

	ESP_LOGI(tag, "Calibration complete");
}
