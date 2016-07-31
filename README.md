# Ghost

## Summary

Ghost is an autonomous car used for Folkrace robot competition. It uses a customized Losi 1/24-scale RTR 4WD Rally Car, and with a custom created PCB and various sensors. The "brain" of the car is a Teensy, and it is programmed using Arduino-C.

This GitHub repository contains all relevant info for creating both hardware and software.

## TODO list

#### PCB
- [ ] Startmodule header needs indicator for direction
- [ ] Startmodule pins are wrong order!! Should be VCC, GND, Start
- [ ] Unable to connect to Bluetooth
- [ ] Red LED doesn't light up. Figure out why.
- [ ] If Wifi stays, should I connect the Reset pin Teensy so that I can reset via software?
- [ ] Switch for pulling GPIO0 on ESP8266 to GND for firmware programming.
- [ ] Change to TCA9548ARGER
- [ ] Change to 0603 size for capacitors and resistors
- [ ] Make board smaller. Move mounting holes.
- [ ] Remove extra PWM pins?
- [ ] Change pin headers around so that pin 1 (the square) is GND
- [ ] Put all pin headers on the border of the PCB
- [ ] Use resistor array for IR sensor resistors
- [ ] Add 6 pin header for FTDI Basic, for programming ESP8266
- [ ] Change the Q1 transistor schematic component to use Q_NPN_BEC
- [ ] Fix missing trace between R7 and D3(red)
- [ ] Move LEDs to a more visible place. They are under Teensy USB now.
- [ ] Move MPU-6050 to the center of the board.
- [ ] Make sure I have four mountingholes for acrylic cover
- [ ] Current size is about 90mm x 63mm. Try to reduce to "Sick of Beige" size 80x49 or 70x43.

#### Car
- [ ] Change the steering servo
- [ ] Mount wheel encoder
- [ ] Create mount for IR sensors
- [ ] Figure out which battery to use
- [ ] Mount new motor.
- [ ] Figure out the gears for the motor

#### Other
- [ ] Laser-cut an acrylic cover for PCB

## Bill of materials / Partlist



### RC car
                   | Tested Works | Doesn't Work | Not Tested
------------------ | :----------: | :----------: | :---------
Losi 1/24 RC car |      X       |             |
HobbyKing XC-10s |      X       |             |
Motor KV4000(?)  |      X       |             |


### PCB

                    |  Tested
------------------- | :------------
Teensy 3.2          | OK
ESP-12E             | OK, connects to WiFi
HM-11               | Blinks, but needs more testing
Startmodule         | WRONG PINS! Should be VCC, GND, Start
MPU-6050            | OK
HMC5883             | (not tested)
TCA9548APWR + IR    | Partially tested. I2C responds, but sensors give weird values.
Encoder             | OK
Steering servo      | OK
Motor               | Partially tested. Car moves :)
INA219              | Partially tested. I2C works, but needs more testing.
RGB                 | (not tested)
PWM                 | (not tested)
General purp. button| OK
Transistor LEDS     | Green works, but not Red. Missing trace on PCB + wrong schematic part. Collector and Emitter are switched! Change to Q_NPN_BEC in KiCad.


## PCB Features

### Teensy 3.1/3.2 (external)

Uses a standard Teensy 3.2 board from pjrc.com. In later versions I'm planning on incorporating a custom Teensy directly into the PCB.

The Teensy is based around a MK20DX256VLH7, an ARM Cortex-M4 at 72MHz. It contains 2k  EEPROM where the car's configuration is stored.

### HM-11 bluetooth

Revision 1 has both Bluetooth and WiFi.  This version is for determining if BT or WiFi is easiest to work with. Later versions will only have one of the two.

Is is not allowed to remotely control the car during the Folkrace, but the BT/WiFi functionality is very useful during debugging and experimentation. It allows receiving telemetry data during racing, and makes it easy to change configuration without reprogramming entire Teensy.

### ESP8266 WiFi

An ESP-12E.

The ESP8266 contains an 80MHz 32-bit RISC CPU with 16 GPIOs, SPI, UART and I2C. In itself it is a powerful chip, and could potentially make the Teensy redundant.

Information gathered from (http://www.esp8266.com/wiki/doku.php?id=esp8266-module-family).
Pin 1, RST: Connect to switch to GND in order to reset.
Pin 3, EN : Connect to 3.3V to enable.
Pin 8, VCC: To 3.3V
Pin 15,GND: To GND
Pin 16,GPIO15: Need to connect to GND.

### MPU-6050 (accelerometer and gyro)

In order to detect movement there is an MPU6050 MEMS motion tracking device with accelerometer and gyro, and an HMC5883 compass.

To interface the MPU-6050 I'm using code from Jeff Rowberg (https://github.com/jrowberg/i2cdevlib/tree/master/Arduino/MPU6050)

 Alternatively I'm going to use FreeIMU (http://www.varesano.net/projects/hardware/FreeIMU).

### HMC5883 (compass)

The compass is a slave-I2C device where the MPU-6050 is the master. FreeIMU uses these two components together.

### I2C multiplexer and 8 IR sensors

Since the I2C IR sensors I'm using all have the same I2C address I need to multiplex between them using an I2C mux.

The multiplexer is an TCA9548APWR with eight channels.
In Rev1 I'm using a multiplexer with footprint TSSOP (7.8 x 4.4 mm). In future revisions I'm considering changing to TCA9548ARGER which has a VQFN footprint (4 x 4 mm). They both have 24 pins.

The IR sensors are eight Sharp GP2Y0E02B, which uses I2C. It has range 4-50cm.

### Current sensor

An INA219BIDR is used for sensing current usage. Measures current flow from the battery connected. Device is controlled by I2C. Adafruit has an Arduino library for the INA219.

Arduino code: /Arduino/CurrentSensor/CurrentSensor.ino

### Voltage regulator

The 7.4V Li-Po battery is connected to the XC-10A ESC, and it provides regulated +5V/1A to the PCB. The Hobbyking XC-10A accepts from 3v-13V, so I could potentially use an 11.1V LiPo.

On the PCB is a MIC5219-3.3YM5 voltage regulator for providing 3.3V. It has a max output of 500mA.

### Toggle LEDs

There are two leds, one red and one green, which can be toggled from Teensy. Only one of them can be active at any given time.

When Teensy pin 2 is HIGH the transistor turns on, and the Green led lights up. When pin 2 is LOW the Red LED lights up.

NB, in Rev 1 the schematic part for the transistor is wrong. It has switched Collector and Emitter, leaving the red led on always.

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
