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
#include "pid.h"
//#include "Sensors/IRSensorConfig.h"
#include "VectorCalculator.h"
#include <cmath>

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
	eDirection direction;
	int steering_angle;
	//bool enabled;
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
	//BaseType_t driverTask;
	//BaseType_t actuatorTask;

	while (true) {
		ESP_LOGW(tag, "Listening on queue_startmodule...");
		BaseType_t rc = xQueueReceive(queue_startmodule, &x, portMAX_DELAY);
		ESP_LOGW(tag, "queue_startmodule said %d", rc);

		//movement_t m;
		//m.enabled = true;
		//xQueueSend(queue_actuators, &m, 0);

//		if (x == 1)
//		{
//			driverTask = xTaskCreate(task_drivecomputer, "Driver task", 4096, NULL, 4, NULL);
//		    actuatorTask = xTaskCreate(task_actuators, "Actuators task", 4096, NULL, 5, NULL);
//		}
//		else
//		{
//			vTaskDelete(driverTask);
//			vTaskDelete(actuatorTask);
//		}
	}
}

void task_irsensors(void *p) {
	ESP_LOGI(tag, "task_irsensors started");

	Sensors::TCA9548 tca9548;
	//esp_err_t result =
	tca9548.setChannel(1);

	Sensors::IRSensorConfig irsensor_conf;
	irsensor_conf.mounting_angle = 45.0;
	irsensor_conf.offset_x_mm = 20.0;
	irsensor_conf.offset_y_mm = 9.5;

	Sensors::IRSensor irsensor(irsensor_conf);

	while (true) {
		ESP_LOGI(tag, "IRSensors loop");
//		int left, right = 0;
//
//		tca9548.setChannel(0);
//		left = irsensor.getDistance();
		//ESP_LOGI(tag, "Left: %d", left);

//		tca9548.setChannel(1);
//		right = irsensor.getDistance();
		//ESP_LOGI(tag, "Right: %d", right);
//
//		int angle = 0;
//		if (left > right)
//			angle = 3000;
//		//steering.TurnTo(3000);
//		else
//			angle = 2200;
//		//steering.TurnTo(2200);
		//ESP_LOGI(tag, "Angle %d", angle);

		sensorvalues_t data;
		//data.compass = 300;
		//data.sensor0 = 30;
		//data.sensor1 = 20; //....

		//movement_t m;
		//m.speed = 100;
		//m.steering_angle = angle;

		//Loop over all the 16 IR sensors, and get the distances.
		for (int channel = 0; channel <= 15; channel++) {
			tca9548.setChannel(channel);
			data.irdata[channel] = irsensor.getDistance();
		}

		//xQueueSend(queue_actuators, &m, NULL);
		xQueueSend(queue_sensorvalues, &data, 0);

		vTaskDelay(pdMS_TO_TICKS(20));
	}

	vTaskDelete(NULL);
}

void task_drivecomputer(void *p) {
	ESP_LOGI(tag, "task_drivecomputer started");

	//Wait for StartModule
//	int x = 123;
//	//BaseType_t rc = xQueueReceive(queue_startmodule, &x, portMAX_DELAY);
//	ESP_LOGI(tag, "Drivecomputer waiting for Startmodule");
//	while (x != 1)
//	{
//		BaseType_t rc = xQueueReceive(queue_startmodule, &x, 0);
//	}

	while (true) {
		ESP_LOGI(tag, "DriveComputer loop");



		//Listen for incoming sensor-data
		sensorvalues_t data;
		if (xQueueReceive(queue_sensorvalues, &data, portMAX_DELAY) == pdPASS) {
			movement_t m;

			int left1 = data.irdata[4];
			int right1 = data.irdata[1];
			int left2 = data.irdata[0];
			int right2 = data.irdata[5];
			ESP_LOGI(tag, "Left1: %d", left1);
			ESP_LOGI(tag, "Left2: %d", left2);
			ESP_LOGI(tag, "Right1: %d", right1);
			ESP_LOGI(tag, "Right2: %d", right2);

			int leftTotal = left1 + left2;
			int rightTotal = right1 + right2;
			//ESP_LOGI(tag, "LeftTotal: %d", leftTotal);
			//ESP_LOGI(tag, "RightTotal: %d", rightTotal);

			int percent = (leftTotal*100 / (rightTotal+leftTotal));
			m.steering_angle = percent;

			VectorCalculator calc;
			Point p1 = calc.FindPointFromAngleAndDistance(60, left1);
			//Compensate for X/Y offset sensor positions
			p1.x = p1.x + 5.2;
			p1.y = p1.y + 2.8;
			Point p2 = calc.FindPointFromAngleAndDistance(25, left2);
			Point vWall = calc.SubtractPoints(p2, p1);
			Point vCar = {x: 1, y:0};
			float angleToWall = calc.GetAngleBetweenVectors(vCar, vWall);
			angleToWall = angleToWall * 180.0/M_PI; //From radians to degrees
			if (vWall.x < 0)
				angleToWall *= -1;

			ESP_LOGI(tag, "Angle to wall: %0.2f", angleToWall);

			//Speed
			m.speed = 10;
			m.direction = FORWARD;

			if (left2 < 10 && right2 < 10)
			{
				//Crashing into wall
				m.speed = 30;
				m.direction = BACKWARD;
				m.steering_angle *= 2;
			}
//			else if (left2 < 20 || right2 < 20)
//			{
//				m.speed = 10;
//				m.direction = FORWARD;
//			}
//			else
//			{
//				m.speed = 25;
//				m.direction = FORWARD;
//			}

			//TODO, add PID controller?

			//Send the desired actuator movements to the queue.
			//xQueueSend(queue_actuators, &m, 0);
		}

		vTaskDelay(pdMS_TO_TICKS(20));
	}

	vTaskDelete(NULL);
}

void task_actuators(void *p) {
	ESP_LOGI(tag, "task_actuators started");

	int min = 2000;
	int max = 4100;
	ServoSteering steering(STEERING_PIN, min, max);
	Motor motor(MOTOR_PIN, 1800, 3400);
	motor.calibrate();

	while (true) {
		ESP_LOGI(tag, "Actuators loop");
		movement_t m;
		//ESP_LOGI(tag, "task_actuators waiting for steering command...");

		//Startmodule
//		int x = 0;
//		if (xQueueReceive(queue_startmodule, &x, portMAX_DELAY) == pdPASS) {
//			ESP_LOGI(tag, "Startmodule toggling motors: %d", x);
//			//motor.ToggleEnable();
//		}

		//Wait for an incoming command telling us to change motorspeed, or turn the wheels.
		if (xQueueReceive(queue_actuators, &m, portMAX_DELAY) == pdPASS) {
			ESP_LOGI(tag, "TurnTo(%d)", m.steering_angle);
			//motor.SetEnable(true);
			ESP_LOGI(tag, "Steering angle: %d", m.steering_angle);
			steering.TurnTo(m.steering_angle);
			motor.SetDirection(m.direction);
			motor.SetSpeed(m.speed);
			ESP_LOGI(tag, "SetSpeed(%d)", m.speed);
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
	int queue_size_startmodule = 1;
	queue_startmodule = xQueueCreate(queue_size_startmodule, sizeof(int));
	queue_sensorvalues = xQueueCreate(1, sizeof(sensorvalues_t));
	queue_actuators = xQueueCreate(1, sizeof(movement_t));

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
	xTaskCreate(task_irsensors, "IRSensors", 4096, NULL, 3, NULL);
	//xTaskCreate(task_listener, "Listener", 4096, NULL, 2, NULL);
	xTaskCreate(task_drivecomputer, "Driver task", 4096, NULL, 4, NULL);
	xTaskCreate(task_actuators, "Actuators task", 4096, NULL, 5, NULL);

	for (;;) {
		vTaskDelay(pdMS_TO_TICKS(1000));
	}

	//Experimenting below...

	//Motor motor(MOTOR_PIN, 1800, 3400);
	//motor.calibrate();

	//ServoSteering steering(STEERING_PIN, 2000, 4100);

	//Sensors::TCA9548 tca9548;
	//esp_err_t result = tca9548.setChannel(1);
	//ESP_LOGD(tag, "TCA9548 channel result: %d", result);
	//ESP_ERROR_CHECK(result);

	//IRSensorArray irsensors();
	//int readings[16] = irsensors.getDistances();

	//double mounting_angle = 45.0;

//	Sensors::IRSensorConfig irsensor_conf;
//	irsensor_conf.mounting_angle = 45.0;
//	irsensor_conf.offset_x_mm = 20.0;
//	irsensor_conf.offset_y_mm = 9.5;
//
//	Sensors::IRSensor irsensor(irsensor_conf);
	//esp_err_t irsensor_found = irsensor.detectDevice();
	//if (irsensor_found != ESP_OK)
	//	ESP_LOGE(tag, "Unable to detect IRSensor");

	//Compass compass();
	//int heading = compass.read();

	//LED l(GPIO_NUM_23);
	//l.Blink(200);



//	for (;;) {
//		if (global_state_startmodule == eStartModuleState::WAITING) {
//			ESP_LOGD(tag, "In WAITING state");
//			motor.SetSpeed(0);
//			//steering.TurnTo(2200);
//			int cm = irsensor.getDistance();
//			ESP_LOGD(tag, "Distance: %d", cm);
//			//printf("[W] CM: %d\n", cm);
//		} else if (global_state_startmodule == eStartModuleState::RUNNING) {
//			//ESP_LOGD(tag, "In RUNNING state");
//			//motor.SetSpeed(3000);
//
//			int left, right = 0;
//
//			tca9548.setChannel(0);
//			left = irsensor.getDistance();
//			//ESP_LOGI(tag, "Left: %d", left);
//
//			tca9548.setChannel(1);
//			right = irsensor.getDistance();
//			//ESP_LOGI(tag, "Right: %d", right);
//
//			if (left > right)
//				steering.TurnTo(3000);
//			else
//				steering.TurnTo(2200);
//
//		} else if (global_state_startmodule == eStartModuleState::STOPPED) {
//			//ESP_LOGD(tag, "In STOPPED state");
//			motor.SetSpeed(1500);
//			steering.TurnTo(4000);
//		}
//
//		vTaskDelay(100 / portTICK_PERIOD_MS);
//	}
}
