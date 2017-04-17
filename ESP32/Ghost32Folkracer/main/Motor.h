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

class Motor {
public:
	Motor(int);
	virtual ~Motor();

	//void SetPin(int);
	void SetSpeed(int);
};

#endif /* MAIN_MOTOR_H_ */
