/*
 * Motor.cpp
 *
 *  Created on: Apr 14, 2017
 *      Author: frode
 */

#include "Motor.h"

Motor::Motor(int pin) {

	//Configure PWM for this pin
	//TODO - move to PWM class
	ledc_timer_config_t timer_conf;
	timer_conf.bit_num = LEDC_TIMER_15_BIT;
	timer_conf.freq_hz = 50; //50 = 20ms
	timer_conf.speed_mode = LEDC_HIGH_SPEED_MODE;
	timer_conf.timer_num = LEDC_TIMER_0;
	ledc_timer_config(&timer_conf);

	//Set a LEDC channel for PWM
	ledc_channel_config_t ledc_conf;
	ledc_conf.channel = LEDC_CHANNEL_0;
	ledc_conf.duty = 3276;
	ledc_conf.gpio_num = pin;
	ledc_conf.intr_type = LEDC_INTR_DISABLE;
	ledc_conf.speed_mode = LEDC_HIGH_SPEED_MODE;
	ledc_conf.timer_sel = LEDC_TIMER_0;
	ledc_channel_config(&ledc_conf);
}

Motor::~Motor() {
	// TODO Auto-generated destructor stub
}

void SetSpeed(int speed)
{
	//TODO, control speed by setting PWM dutycycle/frequency/duration
	int duty_cycle = speed;

	ledc_set_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0, duty_cycle);
	ledc_update_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0);
}
