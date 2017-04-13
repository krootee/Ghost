/*
 * LED.h
 *
 *  Created on: Apr 13, 2017
 *      Author: frode
 */

#ifndef MAIN_LED_H_
#define MAIN_LED_H_

class LED {
public:
	LED(int);
	virtual ~LED();

	void Blink(int);

private:
	int pin;
};

#endif /* MAIN_LED_H_ */
