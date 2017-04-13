/*
 * LED.cpp
 *
 *  Created on: Apr 13, 2017
 *      Author: frode
 */

#include "LED.h"

LED::LED(int pin) {
	// TODO Auto-generated constructor stub
	this->pin = pin;

	gpio_pad_select_gpio(pin);
}

LED::~LED() {
	// TODO Auto-generated destructor stub
}

LED::Blink(int count)
{

}
