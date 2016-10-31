/*
 * Ghost - folkracer for Stockholm 2016
 * Frode Lillerud
 */

#include <Servo.h>
#include <Wire.h>
#include <PID_v1.h>
extern "C"
{
  #include "utility/twi.h"
}

#define SENSOR_ADDRESS  0x80 >> 1
#define DISTANCE_REG    0x5E
#define SHIFT           0x35
#define TCA_ADDRESS     0x70

//PID regulator
double Setpoint, Input, Output;
double Kp = 2, Ki = 5, Kd = 1;
PID pid(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

//Servo related variables
int servoPin = 4;
Servo steering;
int motorPin = 3;
Servo motor;

//Sensor related variables
int activeSensor = -1;
int shift = 0;
byte hi,low;
int distance;

void calibrateXC10A()
{
  Serial.print("Calibrating HobbyKing XC-10A ESC...");
  short wait_time = 2500; //milliseconds
  
  //Set maximum forward throtte
  Serial.print("MAX...");
  motor.writeMicroseconds(2000);
  delay(wait_time);

  //Set full reverse
  Serial.print("MIN...");
  motor.writeMicroseconds(1000);
  delay(wait_time);

  //Go to center
  Serial.println("Center");
  motor.writeMicroseconds(1500);
  delay(max(wait_time*2, 6000)); //Need to wait a while here before trying to move motor first time. Minimum about 6000ms. (max() returns the highest of the two numbers)
}

//Change the channel in the TCA I2C multiplexer
void setActiveSensor(uint8_t i)
{
  if (i > 7) return;

  Wire.beginTransmission(TCA_ADDRESS);
  Wire.write(1 << i);
  Wire.endTransmission();

  activeSensor = i;
}

void setupIRSensors()
{
  //TODO, what does the SHIFT register actually contain? And why do we care?
  Wire.beginTransmission(SENSOR_ADDRESS);
  Wire.write(SHIFT);
  Wire.endTransmission();

  delay(200); //Sometimes the below code never receives data back... Is this really needed?

  Wire.requestFrom(SENSOR_ADDRESS, 1, false);
  while (Wire.available() == 0)
    Trace("Waiting for TCA9548/sensor to reply...");
  shift = Wire.read();
  //Trace(shift);
}

int readFromActiveSensor()
{
  Wire.beginTransmission(SENSOR_ADDRESS);
  Wire.write(DISTANCE_REG);
  Wire.endTransmission();

  Wire.requestFrom(SENSOR_ADDRESS, 2);
  while (Wire.available() < 2)
  {
    //TraceNoLine("Waiting for sensor: ");
    //Trace(activeSensor);
  }

  hi = Wire.read();
  low = Wire.read();
  distance = (hi * 16 + low) / 16 / (int)pow(2, shift);

  return distance;
}

int getSensorDistanceInCm(int sensornumber)
{
  //Serial.println(sensornumber);
  //Set active channel on the TCA I2C multiplexer
  setActiveSensor(sensornumber);
  int cm = readFromActiveSensor();
  return cm;
}

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

  Serial.print("Setup done");
}

elapsedMicros elapsed;

void loop() {

  int loopTime = 5000; //us

  //Get value from sensors
  int left = getSensorDistanceInCm(1);
  int right = getSensorDistanceInCm(7);

  //int pos = (right*100 / (right+left));

  //PID
  Input = (right*100.0 / (right+left));
  pid.Compute();

  //Serial.print(left);
  //Serial.print(",");
  //Serial.println(right);

  //Figure out where to turn

  //Turn
  //int pos = 120;
  Serial.print(Input);
  Serial.print(",");
  Serial.println(Output);
  //Serial.print(",");
  //int ms = map(pos, 0, 100, 90, 180);
  //Serial.println(ms);
  steering.write(Output);
  //delay(50);

  //int speed = 82;
  //motor.write(speed);
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
  while (elapsed < loopTime) {}
  elapsed = 0; 
  
}
