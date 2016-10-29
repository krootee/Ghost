#include <PID_v1.h>

//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
PID myPID(&Input, &Output, &Setpoint,2,5,1, DIRECT);

void setup()
{
  //initialize the variables we're linked to
  Serial.begin(115200);
  
  Input = 0;
  Setpoint = 100;

  //turn the PID on
  
  myPID.SetTunings(1,1,1);
  myPID.SetSampleTime(30);
  //myPID.SetOutputLimits(90,180);
  myPID.SetMode(AUTOMATIC);
}

void loop()
{
  myPID.Compute();
  Serial.print(Setpoint);
  Serial.print(",");
  Serial.print(Input);
  Serial.print(",");
  Serial.println(Output);

  if (Serial.available() > 0)
  {
    Setpoint = Serial.parseInt();
  }

  if (Output > Input)
    Input++;
  else if (Output == Input)
    ;
  else
    Input--;

  delay(100);
}
