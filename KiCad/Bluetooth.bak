EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:NorBot
LIBS:Ghost-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 4
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 3250 2400 0    60   ~ 0
Bluetooth, HM-11\nVCC: 2.5 - 3.7\nPull Reset-pin to ground for 5ms to reset.\n\nhttp://www.seeedstudio.com/wiki/Bluetooth_V4.0_HM-11_BLE_Module\nhttp://lightlogproject.org/blog/tag/hm-11/
$Comp
L HM-11 U15
U 1 1 5749421B
P 5350 4250
F 0 "U15" H 5350 3800 60  0000 C CNN
F 1 "HM-11" H 5350 4800 60  0000 C CNN
F 2 "" H 5250 4250 60  0000 C CNN
F 3 "" H 5250 4250 60  0000 C CNN
	1    5350 4250
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR41
U 1 1 57494294
P 6400 4550
F 0 "#PWR41" H 6400 4400 50  0001 C CNN
F 1 "+3.3V" H 6400 4690 50  0000 C CNN
F 2 "" H 6400 4550 50  0000 C CNN
F 3 "" H 6400 4550 50  0000 C CNN
	1    6400 4550
	0    1    1    0   
$EndComp
Wire Wire Line
	6050 4550 6400 4550
$Comp
L GND #PWR42
U 1 1 574942BB
P 6450 4250
F 0 "#PWR42" H 6450 4000 50  0001 C CNN
F 1 "GND" H 6450 4100 50  0000 C CNN
F 2 "" H 6450 4250 50  0000 C CNN
F 3 "" H 6450 4250 50  0000 C CNN
	1    6450 4250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6450 4250 6050 4250
Wire Wire Line
	6050 4350 6250 4350
Wire Wire Line
	6250 4350 6250 4700
Connection ~ 6250 4550
$Comp
L LED D3
U 1 1 5749451C
P 6550 3950
F 0 "D3" H 6550 4050 50  0000 C CNN
F 1 "LED" H 6550 3850 50  0000 C CNN
F 2 "LEDs:LED_0805" H 6550 3950 50  0001 C CNN
F 3 "" H 6550 3950 50  0000 C CNN
	1    6550 3950
	-1   0    0    1   
$EndComp
$Comp
L R R24
U 1 1 57494583
P 7050 4100
F 0 "R24" V 7130 4100 50  0000 C CNN
F 1 "220" V 7050 4100 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 6980 4100 50  0001 C CNN
F 3 "" H 7050 4100 50  0000 C CNN
	1    7050 4100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR43
U 1 1 574945BD
P 7050 4350
F 0 "#PWR43" H 7050 4100 50  0001 C CNN
F 1 "GND" H 7050 4200 50  0000 C CNN
F 2 "" H 7050 4350 50  0000 C CNN
F 3 "" H 7050 4350 50  0000 C CNN
	1    7050 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 3950 6350 3950
Wire Wire Line
	6750 3950 7050 3950
Wire Wire Line
	7050 4250 7050 4350
Wire Wire Line
	4650 4150 4450 4150
Wire Wire Line
	4650 3950 4450 3950
NoConn ~ 4650 3850
NoConn ~ 4650 4050
NoConn ~ 6050 3850
NoConn ~ 6050 4050
NoConn ~ 6050 4150
Text HLabel 6250 4700 0    60   Input ~ 0
VCC
Text HLabel 7200 4350 2    60   Input ~ 0
GND
Wire Wire Line
	7050 4350 7200 4350
Text HLabel 4450 4150 0    60   Input ~ 0
BLUETOOTH_RX
Text HLabel 4450 3950 0    60   Input ~ 0
BLUETOOTH_TX
$EndSCHEMATC
