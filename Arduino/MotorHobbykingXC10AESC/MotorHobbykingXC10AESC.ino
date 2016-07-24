/*
 * Testing Hobbyking XC-10A ESC
 * Frode Lillerud
 */

#include <Servo.h>

Servo esc;
int j;

void calibrateXC10A()
{
  //Set maximum forward throtte
  esc.writeMicroseconds(2000);
  delay(3000);

  //Set full reverse
  esc.writeMicroseconds(1000);
  delay(3000);

  //Go to center
  esc.writeMicroseconds(1500);
  delay(3000);
}

void setup()
{
//delay(5000); //Delay to give me enough time to control esc to battery
esc.attach(3);

calibrateXC10A();

}

void loop()
{
  for(j=0; j<180; j++) //Running the motor
  {
    esc.write(j);
    delay(100);
  }
  
  for(j=180; j>=0; j--)
  {
    esc.write(j);
    delay(100);
  }
}
