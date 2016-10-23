/*
 * Testing the steering servo
 */

#include <Servo.h>

int servoPin = 4;
Servo servo;

int delayTime = 7; //ms. Interval [0,100]. Low turns fast, high value turns slowly.

//Change values between 0 and 180 to tune servo.
int minPos = 90;
int maxPos = 180;

void setup() {
  servo.attach(servoPin); 
}

void loop() {
  
  for (int pos = minPos; pos <= maxPos; pos += 1) {
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(delayTime);                       // waits 15ms for the servo to reach the position
  }
  
  delay(1000/delayTime);
  for (int pos = maxPos; pos >= minPos; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo.write(pos);     // tell servo to go to position in variable 'pos'
    delay(delayTime);     // waits 15ms for the servo to reach the position
  }
  delay(1000/delayTime);  //Give time for servo to settle before turning other way.
}
