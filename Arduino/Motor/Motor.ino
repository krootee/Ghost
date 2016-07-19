#include <Servo.h>

Servo esc;
int j;

void setup()
{
//delay(5000); //Delay to give me enough time to control esc to battery
esc.attach(3);

esc.write(180);
delay(3000);

esc.write(0);
delay(3000);

esc.write(90);
/*
 for(int i=0; i<1000; i++) //Arming
{
esc.write(180);
delay(20);
}

*/

}
void loop()
{
for(j=0; j<180; j++) //Running the motor
{
esc.write(j);
}
for(j=180; j>=0; j--)
{
esc.write(j);
}
}
