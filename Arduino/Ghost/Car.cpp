#include "Arduino.h"
#include "Car.h"
#include "Servo.h"

Car::Car(int startModulePin, int ledPin)
{
	pinMode(startModulePin, INPUT);
  pinMode(ledPin, OUTPUT);
  _ledPin = ledPin;
  //pinMode(motorPin, OUTPUT);
  //Servo motor;
  //motor.attach(motorPin);
  
	_startModulePin = startModulePin;
  //_motorPin = motorPin;
  //_motor = motor;
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

