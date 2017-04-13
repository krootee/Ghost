/*
 * LED.cpp
 *
 *  Created on: Apr 13, 2017
 *      Author: frode
 */

#include "LED.h"

LED::LED(gpio_num_t pin) {
	this->pin = pin;

	gpio_pad_select_gpio(pin);
	gpio_set_direction(pin, GPIO_MODE_OUTPUT);
}

LED::~LED() {
}

void LED::Blink(int count)
{
	for (int i = 0; i <= count; i++)
	{
		gpio_set_level(this->pin, 1);
		vTaskDelay(500 / portTICK_PERIOD_MS);

		gpio_set_level(this->pin, 0);
		vTaskDelay(500 / portTICK_PERIOD_MS);
	}
}
