# Custom PCB for


https://esp-idf.readthedocs.io/

### PCBs

The electronics use two boards that are connected together using a Hirose FX8C connector.

The bottom board, the GhostESP32, contains primarily the ESP32 and micro USB.

The top board, the GhostSensorboard, contains primarily connectors for all the sensors, servos, power, startmodule, etc.

In the first revision it used the "Sick of Beige" 50x50 formfactor, but in the second revision this has been reduced to the slightly smaller 60x37 formfactor. Also, in the second revision the accelerometer/gyro and compass has been moved from the top board to the bottom board.

There is a KiCad footprint for the Hirose FX8C-60 pin connector at: https://github.com/librespacefoundation/lsf-kicad-libs
and Sick-of-beige layout from https://github.com/TomKeddie/openscad-scripts

#### PCB - GhostESP32 (Microcontroller)

- [x] ESP-WROOM-32
- [x] MicroUSB
- [x] USB-to-UART (CP2102)
- [x] Power LED
- [x] Tx/Rx LEDs
- [x] Reset buttons for ESP-WROOM-32 (Reset)
- [x] Accelerometer/Gyro (MPU-6050)
- [x] Compass (HMC5883)

##### PCB - GhostSensorboard (Sensors and connectors)

- [x] I2C multipexer (TCA9548ARGER, 2pcs)
- [x] 16 connectors for I2C/IR sensors
- [ ] RGB LED
- [x] Connector for Startmodule
- [x] Connector for Steering servo
- [x] Connector for ESC/Motor
- [x] 3V3->5V level shifter (BSS138, see Sparkfun)

### Notes for Rev 3
- [ ] Replace MPU6050 and HMC5883 with a MPU9250
- [ ] 6mm keepout around the mounting holes, see Sick of Beiges specs
- [ ] Is the button on Sensorboard tall enough?

------- OLD BELOW ----------

### Schematic

- [x] Startmodule pins are wrong order!! Should be VCC, GND, Start
- [x] Add two buttons for ESP-WROOM-32
- [x] Change to TCA9548ARGER (smaller footprint than TCA9548APWR)
- [x] Change from 0805 to 0603 size for capacitors, resistors and leds.
- [x] Remove extra PWM pins?
- [x] Change pin headers around so that pin 1 (the square) is GND
- [x] Use resistor array for IR sensor resistors
- [x] Red LED is always on. Figure out why. (was Q1 pins switched)
- [x] Change the Q1 transistor schematic component to use Q_NPN_BEC
- [x] Add 6 pin header for FTDI Basic, for programming ESP8266
- [ ] Remove LED strip connector?
- [ ] Add connectors to breakout ESP-WROOM-32 pins?
- [ ] Micro USB for programming ESP-WROOM-32s
- [ ] CP2102 (or similar USB-to-UART bridge)
- [ ] Use the new 47uF or 100uF alu caps?
- [ ] Use the new resistor networks?

##### Board/layout
- [ ] Current size is about 90mm x 63mm. Try to reduce to "Sick of Beige" size 80x49 or 70x43.
- [ ] Make sure I have four mountingholes for acrylic cover
- [ ] Startmodule header needs indicator for direction
- [ ] Put all pin headers on the border of the PCB
- [ ] Fix missing trace between R7 and D3(red)
- [ ] Move LEDs to a more visible place. They are under Teensy USB now.
- [ ] Move MPU-6050 to the center of the board.
- [ ] Make sure antenna part of ESP-WROOM-32 sticks outside board.

#### Car
- [X] Fix wireposition on steering servo
- [ ] Change the steering servo
- [ ] Mount wheel encoder
- [ ] Create mount for IR sensors
- [ ] Figure out which battery to use
- [ ] Mount new motor.
- [ ] Figure out the gears for the motor

#### Other
- [ ] Draw acrylic cover for PCB in OpenSCAD
- [ ] Laser-cut an acrylic cover for PCB
- [ ] Use 0.1 ohm 1% 2W current sense resistor for the INA219. Find part at Farnell.

## Bill of materials / Partlist



### RC car

## PCB Features

### Teensy 3.1/3.2 (external)

Uses a standard Teensy 3.2 board from pjrc.com.

The Teensy is based around a MK20DX256VLH7, an ARM Cortex-M4 at 72MHz. It contains 2k EEPROM where the car's configuration is stored.

In later versions I'm planning on incorporating a custom Teensy directly into the PCB. If so, then I can remove the MIC5219-3.3, since the Teensy also comes with a 3.3V regulator.

### HM-11 bluetooth

Revision 1 has both Bluetooth and WiFi. This version is for determining if BT or WiFi is easiest to work with. Later versions will only have one of the two.

It is not allowed to remotely control the car during the Folkrace, but the BT/WiFi functionality is very useful during debugging and experimentation. It allows receiving telemetry data during racing, and makes it easy to change configuration without reprogramming entire Teensy.

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

 Future revisions might replace this with a MPU-9250.

### HMC5883 (compass)

The compass is a slave-I2C device where the MPU-6050 is the master. FreeIMU uses these two components together.

### I2C multiplexer and 8 IR sensors

Since the I2C IR sensors I'm using all have the same I2C address I need to multiplex between them using an I2C mux.

The multiplexer is an TCA9548APWR with eight channels.
In Rev 1 I'm using a multiplexer with footprint TSSOP (7.8 x 4.4 mm). In future revisions I'm considering changing to TCA9548ARGER which has a VQFN footprint (4 x 4 mm). They both have 24 pins, but NOT the same pin configuration.

The IR sensors are eight Sharp GP2Y0E02B, which uses I2C. It has range 4-50cm.

### Current sensor

An INA219BIDR is used for sensing current usage. Measures current flow from the battery connected. Device is controlled by I2C. Adafruit has an Arduino library for the INA219.

The sensor can sense up to 3.2A in 0.8mA steps.

Arduino code: /Arduino/CurrentSensor/CurrentSensor.ino

### Voltage regulator

The 7.4V Li-Po battery is connected to the XC-10A ESC, and it provides regulated +5V/1A to the PCB. The Hobbyking XC-10A accepts from 3v-13V, so I could potentially use an 11.1V LiPo.

On the PCB is a MIC5219-3.3YM5 voltage regulator for providing 3.3V. It has a max output of 500mA.

The Teensy also has built in 3.3V regulator. It can supply 500mA. Currently not used.

### Toggle LEDs

There are two leds, one red and one green, which can be toggled from Teensy. Only one of them can be active at any given time.

When Teensy pin 2 is HIGH the transistor turns on, and the Green led lights up. When pin 2 is LOW the Red LED lights up.

NB, in Rev 1 the schematic part for the transistor is wrong. It has switched Collector and Emitter, leaving the red led on always. Fixed in Rev 2.

### GPIOs
#### Startmodule

For connecting a Startmodule from http://www.startmodule.com/.

NB - Rev 1 had wrong pinout! Fixed in Rev 2.

#### Steering servo

For controlling a SG-90 or similar microservo for steering. I'm using Losi part LOSB0814, which is a three-pin replacement servo with servo saver.

  1. PWM control signal to Teensy pin 4.
  2. +5V
  3. GND

#### Motor

A 3 pin header for connecting an Electronic Speed Control (ESC). I'm using the HobbyKing XC-10A esc.

  1. PWM control signal to Teensy pin 3.
  2. Power from the Li-Po battery. Used to power entire PCB.
  3. Ground

Arduino code: Arduino\MotorHobbykingXC10AESC\MotorHobbykingXC10AESC.ino

#### General purpose button

A generic purpose switch, usage to be determined by user. Use INPUT_PULLUP when setting pinMode(pin, INPUT_PULLUP).

#### General purpose PWM connector

Usage to be defined by user
  1. PWM control signal to Teensy pin 16.
  2. +5V
  3. GND

#### Wheel encoder

Either GP1A51HRJOOF or KTIR0611S photo interrupter. Used to measure rate of spinning for the main drive shaft.

## Current consumption

If I need more than 500mA on the 3.3V rail I might go for å AMS1117 or similar, which can handle 1A.

(todo)

## Further research

https://github.com/guyc/RC5

https://github.com/platisd/AndroidCar/

https://github.com/esp8266/Arduino/blob/master/doc/reference.md

http://control.ee.ethz.ch/index.cgi?page=publications&action=list&publty=all&author=&firstyear=&lastyear=&ta_words=rule&ifagroup=all

Check out the USB driver chip CH340.
