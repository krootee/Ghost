#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include <esp_log.h>
#include "sdkconfig.h"

#include "PWM.h"
#include "Motor.h"
#include "CarState.h"

#define MOTOR_PIN GPIO_NUM_26

void task_motor(void *p)
{
	//Configure the motor

	Motor motor(MOTOR_PIN, 1800, 3400);

	for(;;)
	{
		//CarState &CarState::getInstance();

		//CarState::getInstance()->
		//FreeRTOS::sleep(100);

//		if (state_startmodule == 0 || state_startmodule == 2)
//			CarState::getInstance()->motor_set_speed(0);
//		else if (state_startmodule == 1)
//			CarState::getInstance()->motor_set_speed(2500);
	}

	vTaskDelete(NULL);
}
