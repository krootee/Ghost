EESchema Schematic File Version 4
LIBS:GhostESP32-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
Title "Ghost ESP32"
Date "2017-03-19"
Rev "2"
Comp "Frode Lillerud"
Comment1 "https://github.com/Scalpel78/Ghost/tree/master/KiCad/GhostESP32/Rev2"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 2100 2300 0    60   ~ 0
MPU-6050 (Farnell: 186474, QFN-24)\nI2C address: 0x68 / 0x69 (depends on AD0 low or high)
Text HLabel 2000 3400 0    60   Input ~ 0
VCC
$Comp
L GhostESP32-rescue:C-RESCUE-GhostESP32 C12
U 1 1 58C9D2F8
P 2400 3100
F 0 "C12" H 2425 3200 50  0000 L CNN
F 1 "10nF" H 2425 3000 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2438 2950 50  0001 C CNN
F 3 "" H 2400 3100 50  0000 C CNN
	1    2400 3100
	1    0    0    -1  
$EndComp
$Comp
L GhostESP32-rescue:GND-RESCUE-GhostESP32 #PWR052
U 1 1 58C9D2F9
P 2400 2850
F 0 "#PWR052" H 2400 2600 50  0001 C CNN
F 1 "GND" H 2400 2700 50  0000 C CNN
F 2 "" H 2400 2850 50  0000 C CNN
F 3 "" H 2400 2850 50  0000 C CNN
	1    2400 2850
	-1   0    0    1   
$EndComp
Text HLabel 2000 3650 0    60   Input ~ 0
INT
$Comp
L GhostESP32-rescue:GND-RESCUE-GhostESP32 #PWR053
U 1 1 58C9D2FA
P 2700 3850
F 0 "#PWR053" H 2700 3600 50  0001 C CNN
F 1 "GND" H 2700 3700 50  0000 C CNN
F 2 "" H 2700 3850 50  0000 C CNN
F 3 "" H 2700 3850 50  0000 C CNN
	1    2700 3850
	0    1    1    0   
$EndComp
$Comp
L GhostESP32-rescue:GND-RESCUE-GhostESP32 #PWR054
U 1 1 58C9D2FB
P 2800 4750
F 0 "#PWR054" H 2800 4500 50  0001 C CNN
F 1 "GND" H 2800 4600 50  0000 C CNN
F 2 "" H 2800 4750 50  0000 C CNN
F 3 "" H 2800 4750 50  0000 C CNN
	1    2800 4750
	1    0    0    -1  
$EndComp
Text HLabel 2950 4550 2    60   Input ~ 0
GND
$Comp
L GhostESP32-rescue:C-RESCUE-GhostESP32 C11
U 1 1 58C9D2FC
P 2150 4300
F 0 "C11" H 2175 4400 50  0000 L CNN
F 1 "0.1uF" H 2175 4200 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2188 4150 50  0001 C CNN
F 3 "" H 2150 4300 50  0000 C CNN
	1    2150 4300
	-1   0    0    1   
$EndComp
$Comp
L GhostESP32-rescue:C-RESCUE-GhostESP32 C13
U 1 1 58C9D2FD
P 2450 4300
F 0 "C13" H 2475 4400 50  0000 L CNN
F 1 "2.2nF" H 2475 4200 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2488 4150 50  0001 C CNN
F 3 "" H 2450 4300 50  0000 C CNN
	1    2450 4300
	-1   0    0    1   
$EndComp
$Comp
L GhostESP32-rescue:GND-RESCUE-GhostESP32 #PWR055
U 1 1 58C9D2FE
P 4250 4000
F 0 "#PWR055" H 4250 3750 50  0001 C CNN
F 1 "GND" H 4250 3850 50  0000 C CNN
F 2 "" H 4250 4000 50  0000 C CNN
F 3 "" H 4250 4000 50  0000 C CNN
	1    4250 4000
	1    0    0    -1  
$EndComp
$Comp
L NorBot:HMC5883 U6
U 1 1 58C9D2FF
P 7500 3750
F 0 "U6" H 8000 3050 60  0000 C CNN
F 1 "HMC5883" H 7500 3750 60  0000 C CNN
F 2 "Housings_DFN_QFN:QFN-16-1EP_3x3mm_Pitch0.5mm" H 7500 3750 60  0001 C CNN
F 3 "" H 7500 3750 60  0000 C CNN
	1    7500 3750
	1    0    0    -1  
$EndComp
Text HLabel 6400 3650 0    60   Input ~ 0
VCC
Text HLabel 6400 4050 0    60   Input ~ 0
VCC
$Comp
L GhostESP32-rescue:C-RESCUE-GhostESP32 C14
U 1 1 58C9D300
P 7800 5000
F 0 "C14" H 7825 5100 50  0000 L CNN
F 1 "0.22uF" H 7825 4900 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7838 4850 50  0001 C CNN
F 3 "" H 7800 5000 50  0000 C CNN
	1    7800 5000
	-1   0    0    1   
$EndComp
$Comp
L GhostESP32-rescue:GND-RESCUE-GhostESP32 #PWR056
U 1 1 58C9D301
P 9450 4350
F 0 "#PWR056" H 9450 4100 50  0001 C CNN
F 1 "GND" H 9450 4200 50  0000 C CNN
F 2 "" H 9450 4350 50  0000 C CNN
F 3 "" H 9450 4350 50  0000 C CNN
	1    9450 4350
	1    0    0    -1  
$EndComp
$Comp
L GhostESP32-rescue:C-RESCUE-GhostESP32 C15
U 1 1 58C9D302
P 8850 3850
F 0 "C15" H 8875 3950 50  0000 L CNN
F 1 "4.7uF" H 8875 3750 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 8888 3700 50  0001 C CNN
F 3 "" H 8850 3850 50  0000 C CNN
	1    8850 3850
	0    1    1    0   
$EndComp
Wire Wire Line
	2000 3400 2800 3400
Wire Wire Line
	2400 3250 2400 3500
Connection ~ 2400 3400
Wire Wire Line
	2400 3500 2800 3500
Wire Wire Line
	2400 2950 2400 2850
Wire Wire Line
	2000 3650 2800 3650
Wire Wire Line
	2700 3750 2800 3750
Wire Wire Line
	2800 3850 2700 3850
Wire Wire Line
	2800 4150 2800 4750
Wire Wire Line
	2150 3950 2800 3950
Wire Wire Line
	2150 3950 2150 4150
Wire Wire Line
	2800 4050 2450 4050
Wire Wire Line
	2450 4050 2450 4150
Wire Wire Line
	2450 4450 2450 4550
Wire Wire Line
	2150 4550 2950 4550
Connection ~ 2800 4550
Wire Wire Line
	2150 4450 2150 4550
Connection ~ 2450 4550
Wire Wire Line
	4250 4000 4250 3900
Wire Wire Line
	4250 3900 4100 3900
Wire Wire Line
	4100 3800 4450 3800
Wire Wire Line
	4100 3700 4450 3700
Wire Wire Line
	6450 3450 6600 3450
Wire Wire Line
	7200 2850 7200 2700
Wire Wire Line
	6600 3650 6400 3650
Wire Wire Line
	6600 4050 6400 4050
Wire Wire Line
	8400 3450 9850 3450
Wire Wire Line
	7800 4850 7800 4650
Wire Wire Line
	7800 5400 7800 5150
Wire Wire Line
	9450 4050 8400 4050
Wire Wire Line
	9450 3650 9450 4350
Wire Wire Line
	8400 3650 9450 3650
Connection ~ 9450 4050
Wire Wire Line
	8400 3850 8700 3850
Wire Wire Line
	9000 3850 9450 3850
Connection ~ 9450 3850
Text HLabel 7800 2700 1    60   Input ~ 0
VCC
Text HLabel 7400 2700 1    60   Input ~ 0
DRDY
Wire Wire Line
	7400 2700 7400 2850
Wire Wire Line
	7800 2850 7800 2700
$Comp
L NorBot:MPU-6050 U5
U 1 1 58C9D303
P 3450 3900
F 0 "U5" H 3450 3450 60  0000 C CNN
F 1 "MPU-6050" H 3450 4600 60  0000 C CNN
F 2 "Housings_DFN_QFN:QFN-24-1EP_4x4mm_Pitch0.5mm" H 3250 3950 60  0001 C CNN
F 3 "" H 3250 3950 60  0000 C CNN
	1    3450 3900
	1    0    0    -1  
$EndComp
Text HLabel 4450 3700 2    60   Input ~ 0
SCL
Text HLabel 4450 3800 2    60   Input ~ 0
SDA
Wire Wire Line
	9850 3450 9850 5400
Wire Wire Line
	9850 5400 7800 5400
NoConn ~ 4100 3500
NoConn ~ 4100 3400
Text HLabel 6450 3450 0    60   Input ~ 0
SCL
Text HLabel 7200 2700 1    60   Input ~ 0
SDA
$Comp
L GhostESP32-rescue:GND-RESCUE-GhostESP32 #PWR057
U 1 1 58CD4E8D
P 2700 3750
F 0 "#PWR057" H 2700 3500 50  0001 C CNN
F 1 "GND" H 2700 3600 50  0000 C CNN
F 2 "" H 2700 3750 50  0000 C CNN
F 3 "" H 2700 3750 50  0000 C CNN
	1    2700 3750
	0    1    1    0   
$EndComp
Text Notes 6300 2250 0    60   ~ 0
HMC5883 compass\nFarnell no: 197-1743\n\nDRDY pin: "Data Ready, Interrupt Pin. Internally pulled high. Optional connection. Low for 250\nµsec when data is placed in the data output registers"
$EndSCHEMATC
