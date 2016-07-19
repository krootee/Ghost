/*
 * Encoder - Photo Transistor
 */

int encoderPin = 17;
int ledPin = 13;

void setup()
{
  pinMode(encoderPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  digitalWrite(ledPin, digitalRead(encoderPin));
}

