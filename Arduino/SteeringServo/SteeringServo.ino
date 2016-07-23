/*
 * Testing the steering servo
 */

#include <Servo.h>

int servoPin = 4;
Servo servo;

int pos = 0;

void setup() {
  servo.attach(servoPin); 
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) {
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
