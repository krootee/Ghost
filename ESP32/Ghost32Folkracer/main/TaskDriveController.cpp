#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include <esp_log.h>
#include "sdkconfig.h"

#include "PWM.h"
#include "Motor.h"
#include "ServoSteering.h"
#include "CarState.h"

void task_drive_controller(void *p)
{
	Motor m(GPIO_NUM_26);
	ServoSteering s;

	CarState *state;
	state = CarState::getInstance();

	for (;;)
	{
		if (state->startmodule_state == eStartModuleState::RUNNING) //Startmodule
		{
			//TODO: Analyze the sensordata

			//TODO: Tell motor and steering what to do
			m.SetSpeed(50);
			s.SetAngle(0);
		}

		vTaskDelay(1000/portTICK_PERIOD_MS);  //Yield CPU time
	}

	vTaskDelete(NULL);
}
