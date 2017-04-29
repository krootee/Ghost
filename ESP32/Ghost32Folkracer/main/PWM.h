/*
 * PWM.h
 *
 *  Created on: Apr 13, 2017
 *      Author: frode
 */

#ifndef MAIN_PWM_H_
#define MAIN_PWM_H_

#include "driver/ledc.h"

class PWM {
public:
	PWM(int, ledc_channel_t, ledc_timer_t);
	virtual ~PWM();

	void SetDutyCycle(int);
	void SetFreqency(int);
private:
	ledc_channel_t channel;
	ledc_timer_t timer;
};

#endif /* MAIN_PWM_H_ */
