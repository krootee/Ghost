#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include <esp_log.h>
#include "sdkconfig.h"

#include "StartModule.h"
#include "CarState.h"

/*
 * Frode Lillerud, march 2017
 */

#define LED_GPIO GPIO_NUM_23
#define STARTMODULE_GPIO GPIO_NUM_17
#define POWER_GPIO GPIO_NUM_25

//enum eStartModuleState {
//  WAITING = 0,
//  STARTED = 1,
//  STOPPED = 2
//};

static int state = 0;

void isr_startmodule_toggled(void *args)
{
  int startmodule_state = gpio_get_level(STARTMODULE_GPIO);
  gpio_set_level(LED_GPIO, startmodule_state);

  //CarState *state;
  //state = CarState::getInstance();
  //((int)(state->startmodule_state))++;

  StartModule sm(STARTMODULE_GPIO);
  //sm->GoToNextState();
  sm.GoToNextState();

  state++;
}

//Configure the PIN's used by starmodule, and add interrupt handler.
void task_startmodule(void *pvParameter)
{
  //Configure Startmodule
  gpio_config_t btn_config;
  btn_config.intr_type = GPIO_INTR_ANYEDGE; 	//Enable interrupt on both rising and falling edges
  btn_config.mode = GPIO_MODE_INPUT;        	//Set as Input
  btn_config.pin_bit_mask = (1 << STARTMODULE_GPIO); //Bitmask
  btn_config.pull_up_en = GPIO_PULLUP_DISABLE; 	//Disable pullup
  btn_config.pull_down_en = GPIO_PULLDOWN_ENABLE; //Enable pulldown
  gpio_config(&btn_config);
  printf("Startmodule configured\n");

  //Configure GPIO pin as output for powering the Startmodule
  gpio_pad_select_gpio(POWER_GPIO);
  gpio_set_direction(POWER_GPIO, GPIO_MODE_OUTPUT);
  gpio_set_level(POWER_GPIO, 1);

  //Configure LED on ESP32 board to mimic LED on Startmodule
  gpio_pad_select_gpio(LED_GPIO);					//Set pin as GPIO
  gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);	//Set as Output
  printf("LED configured\n");

  //Configure interrupt and add handler
  gpio_install_isr_service(0);						//Start Interrupt Service Routine service
  gpio_isr_handler_add(STARTMODULE_GPIO, isr_startmodule_toggled, NULL); //Add handler of interrupt
  printf("Interrupt configured\n");

  //Wait
  while (1)
  {
      ESP_LOGD("Startmodule", "Current state: %d", state);
      vTaskDelay(1000/portTICK_PERIOD_MS);  //Yield CPU time
  }
}
