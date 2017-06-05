
//Sensor related variables
int activeSensor = -1;
int shift = 0;
byte hi,low;
int distance;

#define SENSOR_ADDRESS  0x80 >> 1
#define DISTANCE_REG    0x5E
#define SHIFT           0x35
#define TCA_ADDRESS     0x70


void setupIRSensors()
{
  //TODO, what does the SHIFT register actually contain? And why do we care?
  Wire.beginTransmission(SENSOR_ADDRESS);
  Wire.write(SHIFT);
  Wire.endTransmission();

  delay(200); //Sometimes the below code never receives data back... Is this really needed?

  Wire.requestFrom(SENSOR_ADDRESS, 1, 0);
  while (Wire.available() == 0)
    Serial.println("Waiting for TCA9548/sensor to reply...");
  shift = Wire.read();
  //Trace(shift);
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
