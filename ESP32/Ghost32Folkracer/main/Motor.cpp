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
}

//	//Configure PWM for this pin
//	//TODO - move to PWM class
//	ledc_timer_config_t timer_conf;
//	timer_conf.bit_num = LEDC_TIMER_15_BIT;
//	timer_conf.freq_hz = 50; //50 = 20ms
//	timer_conf.speed_mode = LEDC_HIGH_SPEED_MODE;
//	timer_conf.timer_num = LEDC_TIMER_0;
//	ledc_timer_config(&timer_conf);
//
//	//Set a LEDC channel for PWM
//	ledc_channel_config_t ledc_conf;
//	ledc_conf.channel = LEDC_CHANNEL_0;
//	ledc_conf.duty = 3276;
//	ledc_conf.gpio_num = pin;
//	ledc_conf.intr_type = LEDC_INTR_DISABLE;
//	ledc_conf.speed_mode = LEDC_HIGH_SPEED_MODE;
//	ledc_conf.timer_sel = LEDC_TIMER_0;
//	ledc_channel_config(&ledc_conf);
//}

Motor::~Motor() {
	// TODO Auto-generated destructor stub
}

//100 is full forward, 0 is stop, -100 is full reverse
void Motor::SetSpeed(int percent)
{
	//TODO, handle negative percent
	int duty_cycle;
	duty_cycle = (((this->max - this->min)*percent)/100)+this->min;

	this->SetDutyCycle(duty_cycle);
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
