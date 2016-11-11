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
		Car(int startModulePin, int ledPin, int steeringPin);
    void Configure(int minSteering, int maxSteering);
    void turn(int angle);
		void stop();
		void drive();
		void blinkLed(int speed);
	private:
		int _startModulePin;
		int _motorPin;
		int _ledPin;
    int _steeringPin;
    Servo _steering;
    int _minSteering;
    int _maxSteering;
};

#endif
