/*
 * Testing Hobbyking XC-10A ESC
 * Frode Lillerud
 */

#include <Servo.h>

Servo esc;

void calibrateXC10A()
{
  Serial.print("Calibrating HobbyKing XC-10A ESC...");
  short wait_time = 2500; //milliseconds
  
  //Set maximum forward throtte
  Serial.print("MAX...");
  esc.writeMicroseconds(2000);
  delay(wait_time);

  //Set full reverse
  Serial.print("MIN...");
  esc.writeMicroseconds(1000);
  delay(wait_time);

  //Go to center
  Serial.println("Center");
  esc.writeMicroseconds(1500);
  delay(max(wait_time*2, 6000)); //Need to wait a while here before trying to move motor first time. Minimum about 6000ms. (max() returns the highest of the two numbers)
}

void normalStartup()
{
  esc.writeMicroseconds(1000);
  delay(5000);
}

void setup()
{
  Serial.begin(9600);
  esc.attach(3);

  calibrateXC10A();
//normalStartup();

  //delay(5000);
}

void loop()
{
  /*
  int j;
  for(j=0; j<180; j++) //Running the motor
  {
    Serial.println(j);
    esc.write(j);
    delay(100);
  }
  
  for(j=180; j>=0; j--)
  {
    Serial.println(j);
    esc.write(j);
    delay(100);
  }
  */

  //esc.write(120); //170
  //delay(1000);
  //esc.write(90);
  //delay(100);  

  //Type values from 0 to 90 to 180 in Serial Monitor to manually control motor.
  
  if (Serial.available())
  {
    int value = Serial.parseInt();
    esc.write(value);
    Serial.print("ESC set to ");
    Serial.println(value);
  }
  
}
