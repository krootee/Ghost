/*
   Frode Lillerud
*/

#ifndef Car_h
#define Car_h

#include "Arduino.h"
#include "Servo.h"

class Car
{
  public:
    Car(int startModulePin, int ledPin, int steeringPin);
    void configureSteering(int minSteering, int maxSteering);
    void turn(int angle);
    void stop();
    void drive();
    void blinkLed(int speed);
	int readSensor(int sensorId);
	startmodule_state getState();
  private:
    int _startModulePin;
    int _motorPin;
    int _ledPin;
    int _steeringPin;
    Servo _steering;
    int _minSteering;
    int _maxSteering; //a
};

typedef	enum {
	UNKNOWN = -1,
	WAITING = 0,
	RUNNING,
	STOPPED
} startmodule_state;

#endif
