# Ghost Design Notes

*These design notes are scribbled down as I'm doing research for my autonomous Folkrace cars. Hopefully these will appply both for the Arduino/Teensy based car, and the C++/ESP32 based one.*

*I'm working on two cars. They use primarily the same hardware platform, but differ in electronics and some of the sensors.*

* *The first car, Ghost, is based on Teensy and the software is written in Arduino.*
* *The second car, Ghost32, is based on ESP32, and the software is written in C++/FreeRTOS.*

## Sensors

### Ghost
* Up to 8 IR sensors.

### Ghost32
* Up to 16 IR sensors.
* Compass
* Accelerometer/Gyro
* Wheel encoder

___
## State handling

Overall car state:

```
{
  env: {
    leftwalll: 32,
    rightwall: 29,
    incline: 3
  },
  pose: {
    velocity: 180,
    direction: 230,
    steering: 76,
    motorspeed: 102,
    odometer: 79
  },
  sensors: {
    irsensor1: true,
    irsensor2: true,
    irsensor3: true,
    irsensor4: false,
    irsensor5: true,
    odometer: true,
    compass: true,
    startmodule: true,
    accelerometer: true
  }
}
```

The modes can be: 'waiting', 'driving', 'stopped'.

Heading is degrees in [0-360].

Speed is in centimeters pr second. It is the actual speed, not the desired speed.
___

## Sensor Fusion
