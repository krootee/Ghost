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
Text Notes 4750 1500 0    118  ~ 24
USB connection
$Comp
L CP2102 U?
U 1 1 5892B42A
P 5600 3500
F 0 "U?" H 6150 2900 60  0000 C CNN
F 1 "CP2102" H 5600 3500 60  0000 C CNN
F 2 "" H 5650 3500 60  0001 C CNN
F 3 "" H 5650 3500 60  0001 C CNN
	1    5600 3500
	1    0    0    -1  
$EndComp
$Comp
L USB_OTG P?
U 1 1 5892BD0E
P 1900 3450
F 0 "P?" H 2225 3325 50  0000 C CNN
F 1 "USB_OTG" H 1900 3650 50  0000 C CNN
F 2 "" V 1850 3350 50  0000 C CNN
F 3 "" V 1850 3350 50  0000 C CNN
	1    1900 3450
	0    -1   1    0   
$EndComp
Text Notes 1750 3050 0    60   ~ 0
Micro-USB connector. Can power the board.\n
$Comp
L D_Schottky_Small_ALT D?
U 1 1 5892BD16
P 2600 3250
F 0 "D?" H 2550 3330 50  0000 L CNN
F 1 "SSA33L (Schottky)" H 2320 3170 50  0000 L CNN
F 2 "" V 2600 3250 50  0000 C CNN
F 3 "" V 2600 3250 50  0000 C CNN
	1    2600 3250
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR?
U 1 1 5892BD1D
P 3000 3250
F 0 "#PWR?" H 3000 3100 50  0001 C CNN
F 1 "+5V" H 3000 3390 50  0000 C CNN
F 2 "" H 3000 3250 50  0000 C CNN
F 3 "" H 3000 3250 50  0000 C CNN
	1    3000 3250
	0    1    1    0   
$EndComp
Wire Wire Line
	2200 3250 2500 3250
Wire Wire Line
	2700 3250 3000 3250
$EndSCHEMATC
