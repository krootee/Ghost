/*
 * Testing the ESP-12E
 * Serial data is sent from Arduino Serial Monitor, to the Teensy, and then to ESP-12.
 * PC ->  Teensy -> ES8266
 * ESP8266 pin 22 is connected to Teensy pin 9
 * ESP8266 pin 21 is connected to Teensy pin 10
 */
 
#define USB Serial
#define WIFI Serial2

int espEnablePin = 8;

void setup ()
{
  USB.begin(9600);
  WIFI.begin(115200);
  
  pinMode(espEnablePin, OUTPUT);
  delay(500);
  digitalWrite(espEnablePin, HIGH);
}

void loop()
{
  int incomingByte;

  //Data coming from Arduino Serial Monitor to the Teensy. All data is just passed to the ESP-12.
  if (USB.available() > 0)
  {
    incomingByte = USB.read();
    WIFI.write(incomingByte);
  }

  //Data received from the ESP-12.
  if (WIFI.available() > 0)
  {
    incomingByte = WIFI.read();
    USB.write(incomingByte);
  }
}

/*
 * AT							//OK
 * AT+RST						//RESET
 * AT+GMR						//Firmware version
 * AT+CWMODE=3					//3 = AP and client. 2=AP only
 * AT+CWJAP="SKYNET","Password"	//Connect to access point
 * AT+CIFSR						//Get IP address
 * ATE0                         //ECHO OFF
 * ATE1                         //ECHO ON
 * AT+CIPMUX=1					//Enable multiple connections
 * AT+CIPSERVER=1,80			//Turn on server. Requires CIPMUX to be set first.
 * AT+IPR=115200				//Set Baud rate
 * AT+CWLAP						//List access points
 */
