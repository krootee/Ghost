/*
 * LED.h
 *
 *  Created on: Apr 13, 2017
 *      Author: frode
 */

#ifndef MAIN_LED_H_
#define MAIN_LED_H_

//#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
//#include "esp_system.h"
//#include "nvs_flash.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

class LED {
public:
	LED(gpio_num_t);
	virtual ~LED();

	void Blink(int count);

private:
	gpio_num_t pin;
};

#endif /* MAIN_LED_H_ */
