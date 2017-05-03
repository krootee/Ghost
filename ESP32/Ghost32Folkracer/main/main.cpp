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

static char tag[] = "Ghost32";

extern "C" {
void app_main(void);
}

//Global variables
int state_motor_speed = 0;
int global_state_startmodule = eStartModuleState::WAITING;
QueueHandle_t queue_startmodule;
QueueHandle_t queue_sensorvalues;
QueueHandle_t queue_actuators;

struct movement_t {
	int speed;
	int steering_angle;
};

struct sensorvalues_t {
	int sensor0;
	int sensor1;
	int sensor2;
	int sensor3;
	int sensor4;
	int sensor5;
	int sensor6;
	int sensor7;
	int sensor8;
	int sensor9;
	int sensor10;
	int sensor11;
	int sensor12;
	int sensor13;
	int sensor14;
	int sensor15;
	int compass;
	int irdata[16];

};

void task_listener(void *parameters) {
	int x = 89;

	while (true) {
		ESP_LOGW(tag, "Listening on queue_startmodule...");
		BaseType_t rc = xQueueReceive(queue_startmodule, &x, portMAX_DELAY);
		ESP_LOGW(tag, "queue_startmodule said %d", rc);
	}
}

void task_irsensors(void *p) {
	ESP_LOGI(tag, "task_irsensors started");

	Sensors::TCA9548 tca9548;
	esp_err_t result = tca9548.setChannel(1);

	Sensors::IRSensorConfig irsensor_conf;
	irsensor_conf.mounting_angle = 45.0;
	irsensor_conf.offset_x_mm = 20.0;
	irsensor_conf.offset_y_mm = 9.5;

	Sensors::IRSensor irsensor(irsensor_conf);

	while (true) {
		int left, right = 0;

		tca9548.setChannel(0);
		left = irsensor.getDistance();
		//ESP_LOGI(tag, "Left: %d", left);

		tca9548.setChannel(1);
		right = irsensor.getDistance();
		//ESP_LOGI(tag, "Right: %d", right);

		int angle = 0;
		if (left > right)
			angle = 3000;
		//steering.TurnTo(3000);
		else
			angle = 2200;
		//steering.TurnTo(2200);
		ESP_LOGI(tag, "Angle %d", angle);

		sensorvalues_t data;
		//data.compass = 300;
		//data.sensor0 = 30;
		//data.sensor1 = 20; //....

		//movement_t m;
		//m.speed = 100;
		//m.steering_angle = angle;

		for (int channel = 0; channel <= 15; channel++) {
			tca9548.setChannel(channel);
			data.irdata[channel] = irsensor.getDistance();
		}

		//xQueueSend(queue_actuators, &m, NULL);
		xQueueSend(queue_sensorvalues, &data, NULL);

		vTaskDelay(pdMS_TO_TICKS(20));
	}

	vTaskDelete(NULL);
}

void task_drivecomputer(void *p) {
	ESP_LOGI(tag, "task_drivecomputer started");

	while (true) {
		movement_t m;

		//Listen for incoming sensor-data
		sensorvalues_t data;
		if (xQueueReceive(queue_sensorvalues, &data, portMAX_DELAY) == pdPASS) {
			if (data.irdata[4] > data.irdata[1]) {
				m.speed = 50;
				m.steering_angle = 2700;
			}
			else
			{
				m.steering_angle = 1200;
			}

			//Send the desired actuator movements to the queue.
			xQueueSend(queue_actuators, &m, NULL);
		}

		vTaskDelay(pdMS_TO_TICKS(20));
	}

	vTaskDelete(NULL);
}

void task_actuators(void *p) {
	ESP_LOGI(tag, "task_actuators started");

	ServoSteering steering(STEERING_PIN);

	while (true) {
		movement_t m;
		ESP_LOGI(tag, "task_actuators waiting for steering command...");

		//Wait for an incoming command telling us to change motorspeed, or turn the wheels.
		if (xQueueReceive(queue_actuators, &m, portMAX_DELAY) == pdPASS) {
			ESP_LOGI(tag, "TurnTo(%d)", m.steering_angle);
			steering.TurnTo(m.steering_angle);

			//TODO, motor
		}
		vTaskDelay(pdMS_TO_TICKS(20));
	}

	vTaskDelete(NULL);
}

void app_main(void) {
	//Setup I2C
	i2c_config_t conf;
	conf.mode = I2C_MODE_MASTER;
	conf.sda_io_num = SDA_PIN;
	conf.scl_io_num = SCL_PIN;
	conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
	conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
	conf.master.clk_speed = 1000000;
	i2c_param_config(I2C_NUM_0, &conf);
	i2c_driver_install(I2C_NUM_0, I2C_MODE_MASTER, 0, 0, 0);

	//Create Queues
	int queue_size_startmodule = 2;
	queue_startmodule = xQueueCreate(queue_size_startmodule, sizeof(int));
	queue_sensorvalues = xQueueCreate(10, sizeof(sensorvalues_t));
	queue_actuators = xQueueCreate(10, sizeof(movement_t));

	/*
	 * Create Tasks
	 *
	 * The lowest priority tasks gather sensorvalues, and passes them to higher level
	 * task which processes the data. Then that task sends drive instructions to even higher
	 * level tasks which manipulates actuators (steering and motor).
	 *
	 * IRSensors -> array of distances -> DriveComputer
	 * Compass -> heading -> DriveComputer
	 * DriveComputer -> Motor
	 * DriveComputer -> Steering
	 */

	xTaskCreate(task_startmodule, "Startmodule task", 4096, NULL, 2, NULL);
	xTaskCreate(task_irsensors, "IRSensors", 4096, NULL, 2, NULL);
	xTaskCreate(task_drivecomputer, "Driver task", 4096, NULL, 4, NULL);
	xTaskCreate(task_actuators, "Actuators task", 4096, NULL, 5, NULL);

	//Experimenting below...

	Motor motor(MOTOR_PIN);
	motor.calibrate();

	ServoSteering steering(STEERING_PIN);

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

	for (;;) {
		vTaskDelay(pdMS_TO_TICKS(500));
	}

	for (;;) {
		if (global_state_startmodule == eStartModuleState::WAITING) {
			ESP_LOGD(tag, "In WAITING state");
			motor.SetSpeed(0);
			//steering.TurnTo(2200);
			int cm = irsensor.getDistance();
			ESP_LOGD(tag, "Distance: %d", cm);
			//printf("[W] CM: %d\n", cm);
		} else if (global_state_startmodule == eStartModuleState::RUNNING) {
			//ESP_LOGD(tag, "In RUNNING state");
			//motor.SetSpeed(3000);

			int left, right = 0;

			tca9548.setChannel(0);
			left = irsensor.getDistance();
			//ESP_LOGI(tag, "Left: %d", left);

			tca9548.setChannel(1);
			right = irsensor.getDistance();
			//ESP_LOGI(tag, "Right: %d", right);

			if (left > right)
				steering.TurnTo(3000);
			else
				steering.TurnTo(2200);

		} else if (global_state_startmodule == eStartModuleState::STOPPED) {
			//ESP_LOGD(tag, "In STOPPED state");
			motor.SetSpeed(1500);
			steering.TurnTo(4000);
		}

		vTaskDelay(100 / portTICK_PERIOD_MS);
	}
}
