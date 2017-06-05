#include <Wire.h>

int PIN_LED = 23;

enum startmoduleStates {
  WAITING,
  RUNNING,
  STOPPED
};

const int STARTMODULE_PIN = 25;
const int STARTMODULE_POWER_PIN = 17;
volatile startmoduleStates startmodule_state = WAITING;

void setup() {
  pinMode(PIN_LED, OUTPUT);

  Serial.begin(115200);

  //Startmodule
  Serial.println("Configuring StartModule");
  pinMode(STARTMODULE_POWER_PIN, OUTPUT);
  digitalWrite(STARTMODULE_POWER_PIN, HIGH);
  pinMode(STARTMODULE_PIN, INPUT);
  
  attachInterrupt(STARTMODULE_PIN, changeStartmoduleState, CHANGE);
  startmodule_state = WAITING;

  //TODO - how to set which pins are used for I2C?? https://esp32.com/viewtopic.php?f=19&t=2058
  //setupIRSensors();

}

void loop() {
  digitalWrite(PIN_LED, HIGH);
  delay(1000);
  digitalWrite(PIN_LED, LOW);
  delay(2000);
  Serial.println("{\"message\": \"Hello from custom ESP32!\"}");
  //Serial.println('{"message": "Hello from ESP32"');
  //int dist = getSensorDistanceInCm(0);
  //Serial.println("Distance: " + dist);
}

void changeStartmoduleState()
{
  bool sm_value = digitalRead(STARTMODULE_PIN);
  if (startmodule_state == WAITING && sm_value == true)
    startmodule_state = RUNNING;
  else if (startmodule_state == RUNNING && sm_value == false)
    startmodule_state = STOPPED;

  //Serial.print("STATE CHANGED to ");
  //Serial.println(startmodule_state);
  //String json = "{\"startmodule\": \"" + startmodule_state + "\"}";
  String json = String("{\"startmodule\":\"" + String(startmodule_state) + "\"}");
  Serial.println(json);
  
}
