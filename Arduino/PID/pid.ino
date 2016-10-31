#include <PID_v1.h>

//Define Variables we'll be connecting to
double Setpoint, Temperature, Power;

//Specify the links and initial tuning parameters
PID myPID(&Temperature, &Power, &Setpoint,2,5,1, DIRECT);

void setup()
{
  //initialize the variables we're linked to
  Serial.begin(115200);
  
  Power = 0;
  Temperature = 0;
  Setpoint = 220; //degrees 

  //turn the PID on
  
  myPID.SetTunings(10,1,1);
  myPID.SetSampleTime(30);
  //myPID.SetOutputLimits(90,180);
  myPID.SetMode(AUTOMATIC);
}

void loop()
{
  myPID.Compute();

  setOvenPower(Power);
  
  Serial.print(Setpoint);
  Serial.print(",");
  Serial.print(Temperature);
  Serial.print(",");
  Serial.println(Power);

  if (Serial.available() > 0)
  {
    Setpoint = Serial.parseInt();
  }

  

  //Temperature = getOvenTemperature();

  delay(100);
}

void setOvenPower(double power)
{
  if (power > 128)
    Temperature++;
  if (power = 128)
    ;
  if (power < 128)
    Temperature--;
}

int getOvenTemperature()
{
  return Temperature;
}

