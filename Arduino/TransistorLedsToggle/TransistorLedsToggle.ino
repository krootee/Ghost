/*
 * Feature test
 * 
 * The two leds GREEN and RED should be toggled on/off using PIN 2
 */

int led = 2;

void setup() {                

  pinMode(led, OUTPUT);     
}


void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(5000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(5000);               // wait for a second
}
