# Ghost

## Summary

Ghost is a custom PCB I've made for my folkrace autonomous RC-car.

## Features

### Teensy 3.1/3.2 (external)
### HM-11 bluetooth
### ESP8266 WiFi
### I2C multiplexer and 8 IR sensors
### Current sensor
### Voltage regulator
### GPIOs
#### Startmodule
#### Steering servo

For controlling a SG-90 or similar microservo for steering.
Pin 1 = PWM control signal
Pin 2 = +5V
Pin 3 = GND

#### Motor

A 3 pin header for connecting an Electronic Speed Control (ESC). I'm using the HobbyKing XC-10A esc.
Pin 1 = PWM control signal
Pin 2 = Power from the Li-Po battery. Used to power entire PCB.
Pin 3 = Ground

#### General purpose button

A generic purpose switch, usage to be determined by user. Use INPUT_PULLUP when setting pinMode(pin, INPUT_PULLUP).

#### Wheel encoder

Either GP1A51HRJOOF or KTIR0611S photo interrupter.

## Current consumption

## Needed improvements

- Startmodule header needs indicator for direction
- Startmodule pins are wrong order!! Should be VCC, GND, Start


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
