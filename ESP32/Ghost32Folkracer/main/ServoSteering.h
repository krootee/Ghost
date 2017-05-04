/*
 * ServoSteering.h
 *
 *  Created on: Apr 17, 2017
 *      Author: frode
 */

#ifndef MAIN_SERVOSTEERING_H_
#define MAIN_SERVOSTEERING_H_

#include <esp_log.h>
#include "PWM.h"

class ServoSteering : public PWM {
public:
	ServoSteering(int, int, int	);
	virtual ~ServoSteering();

	//Set the angle of the servo. 0 is left, 50 is center, 100 is right.
	void TurnTo(int);

private:
	int min_duty_cycle;
	int max_duty_cycle;
};

#endif /* MAIN_SERVOSTEERING_H_ */
