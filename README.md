# Ghost

## Summary

Ghost consists of a is a custom PCB I've made for my folkrace autonomous RC-car.

Ghost is an autonomous car used for Folkrace robot competition. It uses a customized Losi 1/24-scale RTR 4WD Rally Car, and with a custom created PCB and various sensors. The "brain" of the car is a Teensy, and it is programmed using Arduino-C.

This GitHub repository contains all relevant info for creating both hardware and software.

## PCB Features

### Teensy 3.1/3.2 (external)

Uses a standard Teensy 3.2 board from pjrc.com. In later versions I'm planning on incorporating a custom Teensy directly into the PCB.

The Teensy is based around a MK20DX256VLH7, an ARM Cortex-M4 at 72MHz. It contains 2k  EEPROM where the car's configuration is stored.

### HM-11 bluetooth

Revision 1 has both Bluetooth and WiFi.  This version is for determining if BT or WiFi is easiest to work with. Later versions will only have one of the two.

Is is not allowed to remotely control the car during the Folkrace, but the BT/WiFi functionality is very useful during debugging and experimentation. It allows receiving telemetry data during racing, and makes it easy to change configuration without reprogramming entire Teensy.

### ESP8266 WiFi

An ESP8266MOD.

### FreeIMU (accelerometer, gyro and compass)

In order to detect movement there is an MPU6050 MEMS motion tracking device with accelerometer and gyro, and an HMC5883 compass. This is the combination used by FreeIMU (http://www.varesano.net/projects/hardware/FreeIMU).

### I2C multiplexer and 8 IR sensors

Since the I2C IR sensors I'm using all have the same I2C address I need to multiplex between them using an I2C mux.

The multiplexer is an TCA9548APWR with eight channels.

The IR sensors are eight Sharp GP2Y0E02B, which uses I2C. It has range 4-50cm.

### Current sensor

An INA219BIDR is used for sensing current usage. Measures current flow from the battery connected. Device is controlled by I2C. Adafruit has an Arduino library for the INA219.

Arduino code: /Arduino/CurrentSensor/CurrentSensor.ino

### Voltage regulator

The 7.4V Li-Po battery is connected to the XC-10A ESC, and it provides regulated +5V to the PCB.

On the PCB is a MIC5219-3.3YM5 voltage regulator for providing 3.3V. It has a max output of 500mA.

### GPIOs
#### Startmodule

For connecting a Startmodule from http://www.startmodule.com/.

NB - Rev 1 had wrong pinout!

#### Steering servo

For controlling a SG-90 or similar microservo for steering.
  1. PWM control signal to Teensy pin 4.
  2. +5V
  3. GND

#### Motor

A 3 pin header for connecting an Electronic Speed Control (ESC). I'm using the HobbyKing XC-10A esc.
  1. PWM control signal to Teensy pin 3.
  2. Power from the Li-Po battery. Used to power entire PCB.
  3. Ground

#### General purpose button

A generic purpose switch, usage to be determined by user. Use INPUT_PULLUP when setting pinMode(pin, INPUT_PULLUP).

#### General purpose PWM connector

Usage to be defined by user
  1. PWM control signal to Teensy pin 16.
  2. +5V
  3. GND

#### Wheel encoder

Either GP1A51HRJOOF or KTIR0611S photo interrupter.

## Current consumption

## Needed improvements

#### Revision 1
- [ ] Startmodule header needs indicator for direction
- [ ] Startmodule pins are wrong order!! Should be VCC, GND, Start
- [ ] Unable to connect to Bluetooth
- [ ] Red LED doesn't light up. Figure out why.
#### Revision 2

--

<!-- START COMPATIBILITY TABLE -->

## Compatibility

MCU                | Tested Works | Doesn't Work | Not Tested  | Notes
------------------ | :----------: | :----------: | :---------: | -----
Atmega328 @ 16MHz  |      X       |             |            |
Atmega328 @ 12MHz  |      X       |             |            |
Atmega32u4 @ 16MHz |      X       |             |            |
Atmega32u4 @ 8MHz  |      X       |             |            |
ESP8266            |      X       |             |            |
Atmega2560 @ 16MHz |      X       |             |            |
ATSAM3X8E          |      X       |             |            | Use D20/D21.
ATSAM21D           |      X       |             |            |
ATtiny85 @ 16MHz   |      X       |             |            | Use SDA/SCL D0/D2
ATtiny85 @ 8MHz    |      X       |             |            | Use SDA/SCL D0/D2
Intel Curie @ 32MHz |             |             |     X       |
STM32F2            |             |             |     X       |

  * ATmega328 @ 16MHz : Arduino UNO, Adafruit Pro Trinket 5V, Adafruit Metro 328, Adafruit Metro Mini
  * ATmega328 @ 12MHz : Adafruit Pro Trinket 3V
  * ATmega32u4 @ 16MHz : Arduino Leonardo, Arduino Micro, Arduino Yun, Teensy 2.0
  * ATmega32u4 @ 8MHz : Adafruit Flora, Bluefruit Micro
  * ESP8266 : Adafruit Huzzah
  * ATmega2560 @ 16MHz : Arduino Mega
  * ATSAM3X8E : Arduino Due
  * ATSAM21D : Arduino Zero, M0 Pro
  * ATtiny85 @ 16MHz : Adafruit Trinket 5V
  * ATtiny85 @ 8MHz : Adafruit Gemma, Arduino Gemma, Adafruit Trinket 3V

<!-- END COMPATIBILITY TABLE -->
