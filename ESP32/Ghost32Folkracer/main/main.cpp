/*
 * 1. Open up the project properties
 * 2. Visit C/C++ General > Preprocessor Include Paths, Macros, etc
 * 3. Select the Providers tab
 * 4. Check the box for "CDT GCC Built-in Compiler Settings"
 * 5. Set the compiler spec command to "xtensa-esp32-elf-gcc ${FLAGS} -E -P -v -dD "${INPUTS}""
 * 6. Rebuild the index
*/

#include <esp_log.h>
#include <string>
#include "sdkconfig.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "TaskMotor.cpp"
#include "TaskDriveController.cpp"
#include "TaskStartModule.cpp"
#include "StartModule.h"
#include "Sensors/IRSensor.h"
//#include "Sensors/IRSensorConfig.h"

#define MOTOR_PIN GPIO_NUM_26
#define STEERING_PIN GPIO_NUM_27

static char tag[]="Ghost32";

extern "C" {
	void app_main(void);
}

//Global variables
int state_motor_speed = 0;
int global_state_startmodule = eStartModuleState::WAITING;

void app_main(void)
{
	//Startmodule task uses interrupt, and updates the global state.
	xTaskCreate(task_startmodule, "Startmodule task", 4096, NULL, 2, NULL);

	//Drive-controller. The main component which examines the result from the sensors, and tells the actuators what to do.
	//xTaskCreate(task_drive_controller, "Drive controller task", 4096, NULL, 2, NULL);

	//Motor task controls the speed of the motor, by looking at state
	//xTaskCreate(task_motor, "Motor task", 4096, NULL, 2, NULL);

	//TODO: Steering task
	//TODO: IR Sensors task
	//TODO: Accelerometer/Compass task

	Motor motor(MOTOR_PIN);
	motor.calibrate();

	ServoSteering steering(STEERING_PIN);

	//IRSensorArray irsensors();
	//int readings[16] = irsensors.getDistances();

	//double mounting_angle = 45.0;

	Sensors::IRSensorConfig irsensor_conf;
	irsensor_conf.mounting_angle = 45.0;
	irsensor_conf.offset_x_mm = 20.0;
	irsensor_conf.offset_y_mm = 9.5;

	Sensors::IRSensor irsensor(irsensor_conf);

	//Compass compass();
	//int heading = compass.read();

	//LED l(GPIO_NUM_23);
	//l.Blink(200);

	for (;;)
	{
		if (global_state_startmodule == eStartModuleState::WAITING)
		{
			ESP_LOGD(tag, "In WAITING state");
			motor.SetSpeed(0);
			steering.TurnTo(2200);
			int cm = irsensor.getDistance();
			printf("CM: %d", cm);
		}
		else if (global_state_startmodule == eStartModuleState::RUNNING)
		{
			ESP_LOGD(tag, "In RUNNING state");
			motor.SetSpeed(3000);
			steering.TurnTo(3000);
		}
		else if (global_state_startmodule == eStartModuleState::STOPPED)
		{
			ESP_LOGD(tag, "In STOPPED state");
			motor.SetSpeed(1500);
			steering.TurnTo(4000);
		}

		vTaskDelay(100 / portTICK_PERIOD_MS);
	}
}
