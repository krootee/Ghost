/*
 * Testing the ESP-12E
 * Serial data is sent from Arduino Serial Monitor, to the Teensy, and then to ESP-12.
 * ESP8266 pin 22 is connected to Teensy pin 9
 * ESP8266 pin 21 is connected to Teensy pin 10
 */
 
#define USB Serial
#define WIFI Serial2

int espEnablePin = 8;

void setup ()
{
  pinMode(espEnablePin, OUTPUT);
  delay(500);
  digitalWrite(espEnablePin, HIGH);

  USB.begin(9600);
  WIFI.begin(9600);
}

void loop()
{
  int incomingByte;

  //Data coming from Arduino Serial Monitor to the Teensy. All data is just passed to the ESP-12.
  if (USB.available() > 0)
  {
    incomingByte = USB.read();
    WIFI.write(incomingByte+"\r\n");
    //WIFI.println(incomingByte, DEC);

    //USB.print("From USB: ");
    //USB.println(incomingByte, DEC);
    USB.write(incomingByte+"\r\n");
  }

  //Data received from the ESP-12.
  if (WIFI.available() > 0)
  {
    incomingByte = WIFI.read();
    //USB.print("From WIFI: ");
    USB.write(incomingByte+"\r\n");
  }

  delay(501);
}

