/*
 * Test the TCA9548PWR and two of the GP2Y0E02B IR sensors
 * The values from the three sensors can be visualized using Serial Plotter in Arduino IDE.
 * Frode Lillerud, 23.july 2016
 */

#include <Wire.h>
extern "C"
{
#include "utility/twi.h" //from Wire library, so we can do bus scanning
}

#define SENSOR_ADDRESS  0x80 >> 1
#define DISTANCE_REG    0x5E
#define SHIFT           0x35
#define TCA_ADDRESS     0x70

int activeSensor = -1;

//Change the channel in the TCA I2C multiplexer
void setActiveSensor(uint8_t i)
{
  if (i > 7) return;

  Wire.beginTransmission(TCA_ADDRESS);
  Wire.write(1 << i);
  Wire.endTransmission();

  activeSensor = i;
}

int shift = 0;
byte hi,low;
int distance;
//Initialize I2C sensor
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

//Get raw centimeters from the currently selected I2C IR sensor
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

void setup()
{
  Serial.begin(38400);
  Trace("Serial OK");
  
  Wire.begin();
  delay(1000);
  setActiveSensor(1);
  setupIRSensors(); 
  Serial.print("Setup done");
}

void loop()
{
  int cm = getSensorDistanceInCm(1);
  Serial.print(cm);
  Serial.print(",");
  cm = getSensorDistanceInCm(0);
  Serial.print(cm);
  Serial.print(",");
  cm = getSensorDistanceInCm(7);
  Serial.println(cm);
  delay(100);
  
}

