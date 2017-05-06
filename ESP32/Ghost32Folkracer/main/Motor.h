/*
 * Motor.h
 *
 *  Created on: Apr 14, 2017
 *      Author: frode
 */

#ifndef MAIN_MOTOR_H_
#define MAIN_MOTOR_H_

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include <esp_log.h>
#include "sdkconfig.h"
#include "driver/ledc.h"
#include "PWM.h"
#include <cmath>

enum eDirection : int {
  BACKWARD = 0,
  FORWARD = 1
};

class Motor : public PWM
{
public:
	//Motor(int pin) : PWM(pin);
	Motor (int pin, int, int);
	virtual ~Motor();

	//void SetPin(int);
	void SetSpeed(int);
	void SetDirection(eDirection);
	void ToggleEnable();
	void calibrate();

private:
	int min;
	int max;
	int center;
	int current_duty_cycle;
	eDirection current_direction;
	bool enabled;
};

#endif /* MAIN_MOTOR_H_ */
