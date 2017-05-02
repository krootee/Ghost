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
#include "freertos/queue.h"
#include "TaskMotor.cpp"
#include "TaskDriveController.cpp"
#include "TaskStartModule.cpp"
#include "StartModule.h"
#include "Sensors/IRSensor.h"
#include "Sensors/TCA9548.h"
//#include "Sensors/IRSensorConfig.h"

#define MOTOR_PIN GPIO_NUM_26
#define STEERING_PIN GPIO_NUM_27

#define SDA_PIN GPIO_NUM_13 //33
#define SCL_PIN GPIO_NUM_14 //32

//#undef ESP_ERROR_CHECK
//#define ESP_ERROR_CHECK(x)   do { esp_err_t rc = (x); if (rc != ESP_OK) { ESP_LOGE("err", "esp_err_t = %d", rc); assert(0 && #x);} } while(0);


static char tag[]="Ghost32";

extern "C" {
	void app_main(void);
}

//Global variables
int state_motor_speed = 0;
int global_state_startmodule = eStartModuleState::WAITING;
QueueHandle_t queue_startmodule;

void task_listener(void *parameters)
{
	int x = 123;

	while (true)
	{
		ESP_LOGI(tag, "Waiting for queue");
		BaseType_t rc = xQueueReceive(queue_startmodule, &x, portMAX_DELAY);
		ESP_LOGI(tag, "Queue said %d", rc);
	}
}

void app_main(void)
{
	//Queue
	int queue_size = 1;
	queue_startmodule = xQueueCreate(queue_size, sizeof(int));

	//Startmodule task uses interrupt, and updates the global state.
	xTaskCreate(task_startmodule, "Startmodule task", 4096, NULL, 2, NULL);

	xTaskCreate(task_listener, "Queue listener task", 4096, NULL, 3, NULL);

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

	//Set up I2C
	i2c_config_t conf;
	conf.mode = I2C_MODE_MASTER;
	conf.sda_io_num = SDA_PIN;
	conf.scl_io_num = SCL_PIN;
	conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
	conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
	conf.master.clk_speed = 1000000;
	i2c_param_config(I2C_NUM_0, &conf);

	i2c_driver_install(I2C_NUM_0, I2C_MODE_MASTER, 0, 0, 0);

	Sensors::TCA9548 tca9548;
	esp_err_t result = tca9548.setChannel(1);
	ESP_LOGD(tag, "TCA9548 channel result: %d", result);
	ESP_ERROR_CHECK(result);


	//IRSensorArray irsensors();
	//int readings[16] = irsensors.getDistances();

	//double mounting_angle = 45.0;

	Sensors::IRSensorConfig irsensor_conf;
	irsensor_conf.mounting_angle = 45.0;
	irsensor_conf.offset_x_mm = 20.0;
	irsensor_conf.offset_y_mm = 9.5;

	Sensors::IRSensor irsensor(irsensor_conf);
	//esp_err_t irsensor_found = irsensor.detectDevice();
	//if (irsensor_found != ESP_OK)
	//	ESP_LOGE(tag, "Unable to detect IRSensor");

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
			//steering.TurnTo(2200);
			int cm = irsensor.getDistance();
			ESP_LOGD(tag, "Distance: %d", cm);
			//printf("[W] CM: %d\n", cm);
		}
		else if (global_state_startmodule == eStartModuleState::RUNNING)
		{
			ESP_LOGD(tag, "In RUNNING state");
			//motor.SetSpeed(3000);

			int left, right = 0;

			tca9548.setChannel(0);
			left = irsensor.getDistance();
			ESP_LOGI(tag, "Left: %d", left);

			tca9548.setChannel(1);
			right = irsensor.getDistance();
			ESP_LOGI(tag, "Right: %d", right);

			if (left > right)
				steering.TurnTo(3000);
			else
				steering.TurnTo(2200);
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
