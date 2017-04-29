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
	PWM(int);
	virtual ~PWM();

	void SetDutyCycle(int);
	void SetFreqency(int);
};

#endif /* MAIN_PWM_H_ */
