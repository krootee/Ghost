/*
 * Creating a HTTP webserver for ESP8266
 * Frode Lillerud, 22.july 2016
 * Inspired by http://allaboutee.com/2014/12/30/esp8266-and-arduino-webserver/
 */

#define TEENSY Serial
#define ESP8266 Serial2

int espEnablePin = 8;

void setup ()
{
  TEENSY.begin(9600);
  ESP8266.begin(115200);
  
  pinMode(espEnablePin, OUTPUT);
  delay(500);
  digitalWrite(espEnablePin, HIGH);

  //send("AT+RST", 2000);
  //send("AT+CWMODE=3", 1000);
  //send("AT+CWJAP=\"
}

void loop()
{
  int incomingByte;

  //Data coming from Arduino Serial Monitor to the Teensy. All data is just passed to the ESP-12.
  if (TEENSY.available() > 0)
  {
    incomingByte = TEENSY.read();
    ESP8266.write(incomingByte);
  }

  //Data received from the ESP-12.
  if (ESP8266.available() > 0)
  {
    incomingByte = ESP8266.read();
    TEENSY.write(incomingByte);

    //if (ESP8266.find("+IPD"))
    //{
      //ESP8266.print("YES!");
    //}
  }
}

String send(String command, const int timeout)
{
  String response;
  ESP8266.print(command + "\r\n");

  long int time = millis();
  while ((time+timeout) > millis()) //Check if we've reached the timeout
  {
    while (ESP8266.available())
    {
      response += ESP8266.read();    
    }
  }

  return response;
}

