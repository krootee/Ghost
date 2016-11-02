/*
 * Ghost - folkracer for Stockholm 2016
 * Frode Lillerud
 */

#include <Servo.h>
#include <Wire.h>
#include <PID_v1.h>
#include "Car.h"
extern "C"
{
  #include "utility/twi.h"
}

enum startmoduleStates {
  WAITING,
  RUNNING,
  STOPPED
};



const int STARTMODULE_PIN = 5;
volatile startmoduleStates startmodule_state = WAITING;




//PID regulator
double Setpoint, Input, Output;
double Kp = 2, Ki = 5, Kd = 1;
PID pid(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

//Servo related variables
int servoPin = 4;
Servo steering;
int motorPin = 3;
Servo motor;

const int LED_PIN = 13;

Car car(STARTMODULE_PIN, LED_PIN);

void Trace(const String& message)
{
  Serial.println(message);
}

void TraceNoLine(const String& message)
{
  Serial.print(message);
}

void setup() {
  Serial.begin(115200);
  Trace("Serial OK");

  Serial.println("Configuring steering");
  steering.attach(servoPin); 
  steering.write(130); //ca middle

  Serial.println("Configuring motor");
  motor.attach(motorPin);
  calibrateXC10A();

  Serial.println("Configuring I2C and sensors");
  Wire.begin();
  delay(1000);
  setActiveSensor(1);
  setupIRSensors(); 
  
  //PID
  Serial.println("Configuring PID");
  Input = 50.0;
  Setpoint = 50.0;
  Kp = 10.0; //5
  Ki = 0.1; //0
  Kd = 10000; //2
  pid.SetOutputLimits(95, 180); //
  pid.SetSampleTime(20); //ms
  pid.SetControllerDirection(REVERSE);
  pid.SetTunings(Kp, Ki, Kd);
  pid.SetResolution(MICROS);
  pid.SetMode(AUTOMATIC);

  //Startmodule
  Serial.println("Configuring StartModule");
  pinMode(STARTMODULE_PIN, INPUT);
  attachInterrupt(STARTMODULE_PIN, changeStartmoduleState, CHANGE);
  startmodule_state = WAITING;

  //Configure Car
  car.stop();

  Serial.print("Setup done");
}

elapsedMicros elapsed;

void loop() {

  if (startmodule_state == WAITING)
  {
    Serial.print("WAITING");
  }
  else if (startmodule_state == RUNNING)
  {
    //Get value from sensors
    int left = getSensorDistanceInCm(1);
    int right = getSensorDistanceInCm(7);
  
    //NOT PID
    int pos = (right*100 / (right+left));
  
    //PID
    //Input = (right*100.0 / (right+left));
    //pid.Compute();
  
    //Serial.print(left);
    //Serial.print(",");
    //Serial.println(right);
  
    //Figure out where to turn
  
    //Turn
    //int pos = 120;
    //Serial.print(Input);
    //Serial.print(",");
    //Serial.println(Output);
    //Serial.print(",");
    int ms = map(pos, 0, 100, 90, 180);
    //Serial.println(ms);
    steering.write(ms);
    //delay(50);
  
    int speed = 82;
    motor.write(speed);
  }
  else if (startmodule_state == STOPPED)
  {
    motor.writeMicroseconds(1500);
    Serial.print("STOPPED");
    car.blinkLed(500);
  }
  else {
    Serial.print("Unknown startmodule state");
  }
  /*
  if (Serial.available())
  {
    int value = Serial.parseInt();
    motor.write(value);
    Serial.print("ESC set to ");
    Serial.println(value);
  }
  */

  //Serial.print("Elapsed us: ");
  //Serial.print(",");
  //Serial.println(elapsed);

  //Wait here so that each loop takes an exact amount of time.
  unsigned loopTime = 2000; //us
  while (elapsed < loopTime) {}
  elapsed = 0; 
  
}
