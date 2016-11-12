/*
 * Frode Lillerud
 */

#ifndef Car_h
#define Car_h

#include "Arduino.h"
#include "Servo.h"

class Car
{
	public: 
		Car(int startModulePin, int ledPin);
		void stop();
		void drive();
		void blinkLed(int speed);
    void ledOn();
    void ledOff();
	private:
		int _startModulePin;
		int _motorPin;
		int _ledPin;
};

#endif
