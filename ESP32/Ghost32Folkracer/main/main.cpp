/*
 * 1. Open up the project properties
 * 2. Visit C/C++ General > Preprocessor Include Paths, Macros, etc
 * 3. Select the Providers tab
 * 4. Check the box for "CDT GCC Built-in Compiler Settings"
 * 5. Set the compiler spec command to "xtensa-esp32-elf-gcc ${FLAGS} -E -P -v -dD "${INPUTS}""
 * 6. Rebuild the index
 */

#include <stdio.h>
#include <esp_log.h>
#include <string.h>
#include "sdkconfig.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "nvs_flash.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "TaskMotor.cpp"
#include "TaskDriveController.cpp"
#include "TaskStartModule.cpp"
#include "StartModule.h"
#include "Sensors/IRSensor.h"
#include "Sensors/TCA9548.h"
#include "pid.h"
//#include "Sensors/IRSensorConfig.h"
#include "VectorCalculator.h"
#include "MovementDetector.h"
#include "Sensors/MPU6050.h"

#include "Task.h"
#include "WiFi.h"
#include "WiFiEventHandler.h"

#include <cmath>
#include "SockServ.h"
#include "WebSocketTask.h"

#define MOTOR_PIN GPIO_NUM_26
#define STEERING_PIN GPIO_NUM_27

#define SDA_PIN GPIO_NUM_13 //33
#define SCL_PIN GPIO_NUM_14 //32

//#undef ESP_ERROR_CHECK
//#define ESP_ERROR_CHECK(x)   do { esp_err_t rc = (x); if (rc != ESP_OK) { ESP_LOGE("err", "esp_err_t = %d", rc); assert(0 && #x);} } while(0);

static char tag[] = "Ghost32";
static WiFi *wifi;

extern "C" {
void app_main(void);
}

//Global variables
int state_motor_speed = 0;
int global_state_startmodule = eStartModuleState::WAITING;
QueueHandle_t queue_startmodule;
QueueHandle_t queue_sensorvalues;
QueueHandle_t queue_actuators;
QueueHandle_t WebSocket_rx_queue;

//Configuration
bool useWallCompensation = true;
bool doubleSpeedWhenUsingWallCompensation = false; //Double speed if we're driving parallell to wall.
bool useCrashSensing = true; //If we're about to hit a wall, then perform quick turn.
bool useReverseOnCrash = true; //If up-close to wall in front, then reverse.
int defaultSpeed = 12;
//Configuration end

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

//extern struct accelerometer_data {
//	int x;
//	int y;
//	int z;
//};

esp_err_t event_handler(void *ctx, system_event_t *event)
{
    return ESP_OK;
}

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
//		ESP_LOGI(tag, "IRSensors loop");
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

		vTaskDelay(pdMS_TO_TICKS(10));
	}

	vTaskDelete(NULL);
}

void task_drivecomputer(void *p) {
	ESP_LOGI(tag, "task_drivecomputer started");

	Sensors::MovementDetector movementDetector;

	Sensors::MPU6050 mpu6050;

	//Wait for StartModule

//	int x = 123;
//	//BaseType_t rc = xQueueReceive(queue_startmodule, &x, portMAX_DELAY);
//	ESP_LOGI(tag, "Drivecomputer waiting for Startmodule");
//	while (x != 1)
//	{
//		BaseType_t rc = xQueueReceive(queue_startmodule, &x, 0);
//	}

	while (true) {
		if (global_state_startmodule == eStartModuleState::WAITING
				|| global_state_startmodule == eStartModuleState::STOPPED) {
			movement_t m;
			m.speed = 0;
			m.steering_angle = 50;
			xQueueSend(queue_actuators, &m, 0);
			//continue;
		} else if (global_state_startmodule == eStartModuleState::RUNNING) {

			//ESP_LOGI(tag, "DriveComputer loop");

//			Sensors::accelerometer_data acc = mpu6050.Read();
//			ESP_LOGI(tag, "X: %d", acc.x);
//			ESP_LOGI(tag, "Y: %d", acc.y);
//			ESP_LOGI(tag, "Z: %d", acc.z);

			//Listen for incoming sensor-data
			sensorvalues_t data;
			if (xQueueReceive(queue_sensorvalues, &data, portMAX_DELAY)
					== pdPASS) {

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

				int percent = (leftTotal * 100 / (rightTotal + leftTotal));
				m.steering_angle = percent;

				//Start calculating angle to wall

				float angleToWall = 0.0;
				if (useWallCompensation) {
					VectorCalculator calc;
					Point p1 = calc.FindPointFromAngleAndDistance(60, left1);
					//Compensate for X/Y offset sensor positions
					p1.x = p1.x - 5.2;
					p1.y = p1.y + 2.8;
					Point p2 = calc.FindPointFromAngleAndDistance(25, left2);
					Point vWall = calc.SubtractPoints(p2, p1);
					Point
					vCar = {x: 1, y:0};
					angleToWall = calc.GetAngleBetweenVectors(vCar, vWall);
					angleToWall = angleToWall * 180.0 / M_PI; //From radians to degrees
					if (vWall.y < 0)
						angleToWall *= -1;
					float wallAngleCompensation = 1.0; //1.0 is keep as is.
					if (angleToWall > 45)
						wallAngleCompensation = 0.5;
					if (angleToWall < -45)
						wallAngleCompensation = 1.5;
					m.steering_angle *= wallAngleCompensation;
					ESP_LOGI(tag, "Angle to wall: %0.2f", angleToWall);
				}
				//End calculating angle to wall

				//Speed - set default speed and direction
				m.speed = defaultSpeed;
				m.direction = FORWARD;

				//Standing still? Then stop the motor.
//				std::vector<int> s;
//				s.assign(data.irdata, data.irdata+16);
//				movementDetector.SaveIRSensorReadings(s);
//				if (movementDetector.IsStandingStill())
//				{
//					ESP_LOGW(tag, "NO MOTION DETECTED!");
//					m.speed = 0;
//				}

				//Adjust speed (go twice as fast if we are parallell to the wall)
				if (useWallCompensation
						&& doubleSpeedWhenUsingWallCompensation) {
					if (abs(angleToWall) < 10)
						m.speed *= 2;
				}

				//About to crash, make big turn!
				if (useCrashSensing) {
					if (left2 < 20 && right2 < 20) {
						if (m.steering_angle > 50)
							m.steering_angle = 100;
						else
							m.steering_angle = 0;
					}
				}

				//Crashed into wall
				if (useReverseOnCrash) {
					if (left2 < 10 && right2 < 10) {
						m.speed = 20;
						m.direction = BACKWARD;
						m.steering_angle *= -2;
					}
				}

				//TODO, add PID controller?

				//Send the desired actuator movements to the queue.
				xQueueSend(queue_actuators, &m, 0);
			}
		}

		vTaskDelay(pdMS_TO_TICKS(10));
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
		vTaskDelay(pdMS_TO_TICKS(10));
	}

	vTaskDelete(NULL);
}

void task_process_WebSocket( void *pvParameters ){
    (void)pvParameters;

    //frame buffer
    WebSocket_frame_t __RX_frame;

    //create WebSocket RX Queue
    WebSocket_rx_queue = xQueueCreate(10,sizeof(WebSocket_frame_t));

    while (1){
        //receive next WebSocket frame from queue
        if(xQueueReceive(WebSocket_rx_queue,&__RX_frame, 3*portTICK_PERIOD_MS)==pdTRUE){

        	//write frame inforamtion to UART
        	printf("New Websocket frame. Length %d, payload %.*s \r\n", __RX_frame.payload_length, __RX_frame.payload_length, __RX_frame.payload);

        	//loop back frame
        	WS_write_data(__RX_frame.payload, __RX_frame.payload_length);

        	//free memory
			if (__RX_frame.payload != NULL)
				free(__RX_frame.payload);

        }
    }
}

void app_main(void) {

    nvs_flash_init();

	//Connect to Wi-Fi
	wifi = new WiFi();
	//wifi->setWifiEventHandler(eventHandler);
	wifi->connectAP("Skynet", "W4r3Zl4ck");

	char test[6];
	strcpy(test, "Hallo");

	//SockServ mySockServer = SockServ(9876);
	//mySockServer.start();

	xTaskCreate(&task_process_WebSocket, "ws_process_rx", 2048, NULL, 5, NULL);
	xTaskCreate(&ws_server, "ws_server", 2048, NULL, 5, NULL);

	//create WebSocket receive task
    //xTaskCreate	(&task_process_WebSocket, "ws_process_rx", 2048, NULL, 5, NULL);

	//Create Websocket Server Task
	//xTaskCreate(&ws_server, "ws_server", 2048, NULL, 5, NULL);

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
		//WS_write_data("Ghost says hi!", 14);
		//mySockServer.sendData("Ghost32!");
	}
}
