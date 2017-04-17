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
//#include "LED.h"

#include "StartModule.c"
//#include "ResetButton.c"
#include "TaskMotor.cpp"


//static char tag[]="cpp_helloworld";

extern "C" {
	void app_main(void);
}

//class Greeting {
//public:
//	void helloEnglish() {
//		ESP_LOGD(tag, "Hello %s", name.c_str());
//	}
//
//	void helloFrench() {
//		ESP_LOGD(tag, "Bonjour %s", name.c_str());
//	}
//
//	void setName(std::string name) {
//		this->name = name;
//	}
//private:
//	std::string name = "";
//
//};

//static char tag[] = "Ghost32";
//static const char* tag = "Ghost32";

//struct car_state {
//	int startmodule_state;
//};

int state_motor_speed = 0;
int state_startmodule = 0;

void app_main(void)
{
	//Startmodule task uses interrupt, and updates the global state.
	xTaskCreate(startmodule_task, "Startmodule task", 4096, NULL, 2, NULL);

	//Motor task controls the speed of the motor, by looking at state
	xTaskCreate(task_motor, "Motor task", 4096, NULL, 2, NULL);

	//TODO: Steering task
	//TODO: IR Sesors task
	//TODO: Accelerometer/Compass task


	//LED l(GPIO_NUM_23);
	//l.Blink(200);

	for (;;)
	{
		//printf("State from other file: %d\n", state);
		vTaskDelay(1000 / portTICK_PERIOD_MS);
	}
}
