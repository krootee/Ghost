/*
 * Feature test - general purpose button
 * 
 * The button input pin should use internal pullup resistor.
 * The LED stops shining when button is pressed.
 */

int ledPin = 13;
int btnPin = 7;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(btnPin, INPUT_PULLUP);
}

void loop()
{
  digitalWrite(ledPin, digitalRead(btnPin));
}

