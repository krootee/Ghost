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
