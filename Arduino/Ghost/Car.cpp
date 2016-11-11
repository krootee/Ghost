#include "Arduino.h"
#include "Car.h"
//#include "Servo.h"

Servo _steering;

Car::Car(int startModulePin, int ledPin, int steeringPin)
{
	pinMode(startModulePin, INPUT);
  pinMode(ledPin, OUTPUT);
  _ledPin = ledPin;
  _steeringPin = steeringPin;
  _steering.attach(_steeringPin);
  //pinMode(motorPin, OUTPUT);
  //Servo motor;
  //motor.attach(motorPin);
  
	_startModulePin = startModulePin;
  //_motorPin = motorPin;
  //_motor = motor;
}

/*
 * Minimum is typically around -35, and maximum around 35 (???)
 */
void Car::Configure(int minSteeringAngle, int maxSteeringAngle)
{
  _minSteering = minSteeringAngle;
  _maxSteering = maxSteeringAngle;
}

void Car::turn(int angle)
{
  /*
   * 0 is straight ahead. Positive number is to the right, and negative is to the left.
   */
   angle = constrain(angle, _minSteering, _maxSteering);
   ms = map(angle, -45, 45, 90, 180); //TODO, need to measure the maximumm angles the wheels can turn
  _steering.write(ms);
}

void Car::stop()
{
  //_motor.
  return;
}

void Car::blinkLed(int speed)
{
  digitalWrite(_ledPin, HIGH);
  delay(speed);
  digitalWrite(_ledPin, LOW);
  delay(speed);
}
