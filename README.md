# Ghost

## Summary

Ghost is an autonomous car used for Folkrace robot competition. It uses a customized Losi 1/24-scale RTR 4WD Rally Car, and with a custom created PCB and various sensors. The "brain" of the car is a Teensy, and it is programmed using Arduino-C.

This GitHub repository contains all relevant info for creating both hardware and software.

## TODO list

- [ ] Startmodule header needs indicator for direction
- [ ] Startmodule pins are wrong order!! Should be VCC, GND, Start
- [ ] Unable to connect to Bluetooth
- [ ] Red LED doesn't light up. Figure out why.
- [ ] If Wifi stays, should I connect the Reset pin Teensy so that I can reset via software?
- [ ] GND pins on Encoder needs to be connected to same GND. No internal connection in component.

## Bill of materials / Partlist



### RC car
                   | Tested Works | Doesn't Work | Not Tested
------------------ | :----------: | :----------: | :---------
Losi 1/24 RC car |      X       |             |
HobbyKing XC-10s |      X       |             |
Motor KV4000(?)  |      X       |             |


### PCB

                    |  Footprint
------------------- | :------------
Teensy 3.2          | Custom
HM-11               | Custom
Startmodule         | 3 pin header
etc                 |

## PCB Features

### Teensy 3.1/3.2 (external)

Uses a standard Teensy 3.2 board from pjrc.com. In later versions I'm planning on incorporating a custom Teensy directly into the PCB.

The Teensy is based around a MK20DX256VLH7, an ARM Cortex-M4 at 72MHz. It contains 2k  EEPROM where the car's configuration is stored.

### HM-11 bluetooth

Revision 1 has both Bluetooth and WiFi.  This version is for determining if BT or WiFi is easiest to work with. Later versions will only have one of the two.

Is is not allowed to remotely control the car during the Folkrace, but the BT/WiFi functionality is very useful during debugging and experimentation. It allows receiving telemetry data during racing, and makes it easy to change configuration without reprogramming entire Teensy.

### ESP8266 WiFi

An ESP8266MOD.

(NB, seems to be the same chip as the Fishino Guppy uses)

Information gathered from (http://www.esp8266.com/wiki/doku.php?id=esp8266-module-family).
Pin 1, RST: Connect to switch to GND in order to reset.
Pin 3, EN : Connect to 3.3V to enable.
Pin 8, VCC: To 3.3V
Pin 15,GND: To GND
Pin 16,GPIO15: Need to connect to GND.

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

#### Revision 2
