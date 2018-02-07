EESchema Schematic File Version 4
LIBS:GhostSensorboard-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 2
Title "Ghost Sensorboard"
Date "2017-03-20"
Rev "2"
Comp "Frode Lillerud"
Comment1 "https://github.com/Scalpel78/Ghost/tree/master/KiCad/GhostSensorboard/Rev2"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 4800 950  0    118  ~ 24
Ghost Sensorboard
Text Notes 4800 1250 0    59   ~ 0
A shield for the Ghost32 board.\nContains sensors and connectors.
$Comp
L GhostSensorboard-rescue:BSS138-RESCUE-GhostSensorboard Q1
U 1 1 5897081C
P 10100 6150
F 0 "Q1" V 10400 6100 50  0000 L CNN
F 1 "BSS138" V 10300 6050 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 10300 6075 50  0001 L CIN
F 3 "" H 10100 6150 50  0000 L CNN
	1    10100 6150
	0    1    1    0   
$EndComp
$Comp
L GhostSensorboard-rescue:R-RESCUE-GhostSensorboard R3
U 1 1 58970CD6
P 9800 6000
F 0 "R3" V 9880 6000 50  0000 C CNN
F 1 "10k" V 9800 6000 50  0000 C CNN
F 2 "Resistors_SMD:R_0402" V 9730 6000 50  0001 C CNN
F 3 "" H 9800 6000 50  0000 C CNN
	1    9800 6000
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:R-RESCUE-GhostSensorboard R6
U 1 1 58970E21
P 10400 5900
F 0 "R6" V 10480 5900 50  0000 C CNN
F 1 "10k" V 10400 5900 50  0000 C CNN
F 2 "Resistors_SMD:R_0402" V 10330 5900 50  0001 C CNN
F 3 "" H 10400 5900 50  0000 C CNN
	1    10400 5900
	1    0    0    -1  
$EndComp
Text GLabel 9700 6250 0    39   Input ~ 0
STEERING_3V3_PWM
$Comp
L GhostSensorboard-rescue:+3V3-RESCUE-GhostSensorboard #PWR01
U 1 1 589710D9
P 9800 5700
F 0 "#PWR01" H 9800 5550 50  0001 C CNN
F 1 "+3V3" H 9800 5840 50  0000 C CNN
F 2 "" H 9800 5700 50  0000 C CNN
F 3 "" H 9800 5700 50  0000 C CNN
	1    9800 5700
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:+5V-RESCUE-GhostSensorboard #PWR02
U 1 1 589710F7
P 10400 5700
F 0 "#PWR02" H 10400 5550 50  0001 C CNN
F 1 "+5V" H 10400 5840 50  0000 C CNN
F 2 "" H 10400 5700 50  0000 C CNN
F 3 "" H 10400 5700 50  0000 C CNN
	1    10400 5700
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:CONN_01X03-RESCUE-GhostSensorboard P2
U 1 1 589717B1
P 900 5800
F 0 "P2" H 900 6000 50  0000 C CNN
F 1 "SteeringServo" V 1000 5800 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 900 5800 50  0001 C CNN
F 3 "" H 900 5800 50  0000 C CNN
	1    900  5800
	-1   0    0    -1  
$EndComp
Text Notes 10700 650  2    39   ~ 0
NB, GPIO pins from ESP is 3.3V level!
Text GLabel 1250 5700 2    39   Input ~ 0
STEERING_5V_PWM
$Comp
L GhostSensorboard-rescue:+5V-RESCUE-GhostSensorboard #PWR03
U 1 1 58972924
P 1600 5800
F 0 "#PWR03" H 1600 5650 50  0001 C CNN
F 1 "+5V" H 1600 5940 50  0000 C CNN
F 2 "" H 1600 5800 50  0000 C CNN
F 3 "" H 1600 5800 50  0000 C CNN
	1    1600 5800
	0    1    1    0   
$EndComp
$Comp
L GhostSensorboard-rescue:GND-RESCUE-GhostSensorboard #PWR04
U 1 1 58972A51
P 1250 5900
F 0 "#PWR04" H 1250 5650 50  0001 C CNN
F 1 "GND" H 1250 5750 50  0000 C CNN
F 2 "" H 1250 5900 50  0000 C CNN
F 3 "" H 1250 5900 50  0000 C CNN
	1    1250 5900
	0    -1   -1   0   
$EndComp
Text Notes 800  4450 0    39   ~ 0
Startmodule\nUse a female 3pin header.\nAccepts both 3V3 and 5V.\nPower is supplied via GPIO, so that recycle can be done via software.
Wire Notes Line
	8950 500  8950 4200
Wire Notes Line
	8950 4200 11150 4200
Wire Wire Line
	9700 6250 9800 6250
Wire Wire Line
	9800 6150 9800 6250
Connection ~ 9800 6250
Wire Wire Line
	10300 6250 10400 6250
Wire Wire Line
	10400 6050 10400 6250
Connection ~ 10400 6250
Wire Wire Line
	10050 5950 10050 5800
Wire Wire Line
	10050 5800 9800 5800
Wire Wire Line
	9800 5700 9800 5800
Connection ~ 9800 5800
Wire Wire Line
	10400 5700 10400 5750
Text Notes 800  5500 0    39   ~ 0
SteeringServo\nPWM signal has been levelshifted from 3V3 to 5V logic.
$Comp
L GhostSensorboard-rescue:CONN_01X03-RESCUE-GhostSensorboard P1
U 1 1 589803A2
P 900 4750
F 0 "P1" H 900 4950 50  0000 C CNN
F 1 "StartModule" V 1000 4750 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 900 4750 50  0001 C CNN
F 3 "" H 900 4750 50  0000 C CNN
	1    900  4750
	-1   0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:GND-RESCUE-GhostSensorboard #PWR05
U 1 1 58980519
P 1400 4750
F 0 "#PWR05" H 1400 4500 50  0001 C CNN
F 1 "GND" H 1400 4600 50  0000 C CNN
F 2 "" H 1400 4750 50  0000 C CNN
F 3 "" H 1400 4750 50  0000 C CNN
	1    1400 4750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1100 4650 1200 4650
Wire Wire Line
	1100 4750 1400 4750
Wire Wire Line
	1100 4850 1200 4850
Wire Wire Line
	1250 5700 1100 5700
Wire Wire Line
	1100 5800 1600 5800
Wire Wire Line
	1250 5900 1100 5900
$Comp
L GhostSensorboard-rescue:CONN_01X03-RESCUE-GhostSensorboard P3
U 1 1 589822C3
P 900 6800
F 0 "P3" H 900 7000 50  0000 C CNN
F 1 "Motor" V 1000 6800 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 900 6800 50  0001 C CNN
F 3 "" H 900 6800 50  0000 C CNN
	1    900  6800
	-1   0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:GND-RESCUE-GhostSensorboard #PWR06
U 1 1 589822D0
P 1250 6900
F 0 "#PWR06" H 1250 6650 50  0001 C CNN
F 1 "GND" H 1250 6750 50  0000 C CNN
F 2 "" H 1250 6900 50  0000 C CNN
F 3 "" H 1250 6900 50  0000 C CNN
	1    1250 6900
	0    -1   -1   0   
$EndComp
Text Notes 800  6500 0    39   ~ 0
Motor\nThis is where 5V is supplied to the system!\nPWM signal has been levelshifted from 3V3 to 5V logic.
Wire Wire Line
	1250 6700 1100 6700
Wire Wire Line
	1100 6800 1650 6800
Wire Wire Line
	1100 6900 1150 6900
$Comp
L GhostSensorboard-rescue:BSS138-RESCUE-GhostSensorboard Q2
U 1 1 58982B38
P 10100 5250
F 0 "Q2" V 10400 5200 50  0000 L CNN
F 1 "BSS138" V 10300 5150 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 10300 5175 50  0001 L CIN
F 3 "" H 10100 5250 50  0000 L CNN
	1    10100 5250
	0    1    1    0   
$EndComp
$Comp
L GhostSensorboard-rescue:R-RESCUE-GhostSensorboard R7
U 1 1 58982B3E
P 9800 5100
F 0 "R7" V 9880 5100 50  0000 C CNN
F 1 "10k" V 9800 5100 50  0000 C CNN
F 2 "Resistors_SMD:R_0402" V 9730 5100 50  0001 C CNN
F 3 "" H 9800 5100 50  0000 C CNN
	1    9800 5100
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:R-RESCUE-GhostSensorboard R8
U 1 1 58982B44
P 10400 5000
F 0 "R8" V 10480 5000 50  0000 C CNN
F 1 "10k" V 10400 5000 50  0000 C CNN
F 2 "Resistors_SMD:R_0402" V 10330 5000 50  0001 C CNN
F 3 "" H 10400 5000 50  0000 C CNN
	1    10400 5000
	1    0    0    -1  
$EndComp
Text GLabel 9700 5350 0    39   Input ~ 0
MOTOR__3V3_PWM
Text GLabel 10550 5350 2    39   Input ~ 0
MOTOR_5V_PWM
$Comp
L GhostSensorboard-rescue:+3V3-RESCUE-GhostSensorboard #PWR07
U 1 1 58982B4C
P 9800 4800
F 0 "#PWR07" H 9800 4650 50  0001 C CNN
F 1 "+3V3" H 9800 4940 50  0000 C CNN
F 2 "" H 9800 4800 50  0000 C CNN
F 3 "" H 9800 4800 50  0000 C CNN
	1    9800 4800
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:+5V-RESCUE-GhostSensorboard #PWR08
U 1 1 58982B52
P 10400 4800
F 0 "#PWR08" H 10400 4650 50  0001 C CNN
F 1 "+5V" H 10400 4940 50  0000 C CNN
F 2 "" H 10400 4800 50  0000 C CNN
F 3 "" H 10400 4800 50  0000 C CNN
	1    10400 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	9700 5350 9800 5350
Wire Wire Line
	9800 5250 9800 5350
Connection ~ 9800 5350
Wire Wire Line
	10300 5350 10400 5350
Wire Wire Line
	10400 5150 10400 5350
Connection ~ 10400 5350
Wire Wire Line
	10050 5050 10050 4900
Wire Wire Line
	10050 4900 9800 4900
Wire Wire Line
	9800 4800 9800 4900
Connection ~ 9800 4900
Wire Wire Line
	10400 4800 10400 4850
Text Notes 10550 4500 2    39   ~ 0
Level shifting IO signals from 3V3 to 5V.
Text GLabel 1200 4850 2    39   Input ~ 0
STARTMODULE_SIGNAL
$Comp
L GhostSensorboard-rescue:SW_Push-RESCUE-GhostSensorboard SW1
U 1 1 5898C790
P 5100 1950
F 0 "SW1" H 5150 2050 50  0000 L CNN
F 1 "SW_Push" H 5100 1890 50  0000 C CNN
F 2 "Buttons_Switches_SMD:SW_SPST_EVQP2" H 5100 2150 50  0001 C CNN
F 3 "" H 5100 2150 50  0000 C CNN
	1    5100 1950
	1    0    0    -1  
$EndComp
Text GLabel 4300 1950 0    39   Input ~ 0
BUTTON
$Comp
L GhostSensorboard-rescue:GND-RESCUE-GhostSensorboard #PWR09
U 1 1 5898D566
P 5550 2150
F 0 "#PWR09" H 5550 1900 50  0001 C CNN
F 1 "GND" H 5550 2000 50  0000 C CNN
F 2 "" H 5550 2150 50  0000 C CNN
F 3 "" H 5550 2150 50  0000 C CNN
	1    5550 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 1950 4850 1950
Wire Wire Line
	5550 1950 5550 2150
Text Notes 4350 1750 0    39   ~ 0
General purpose switch.\nUse internal pull-up resistor in ESP32.
$Comp
L GhostSensorboard-rescue:PWR_FLAG-RESCUE-GhostSensorboard #FLG010
U 1 1 5898E8D8
P 1650 6850
F 0 "#FLG010" H 1650 6945 50  0001 C CNN
F 1 "PWR_FLAG" H 1650 7030 50  0000 C CNN
F 2 "" H 1650 6850 50  0000 C CNN
F 3 "" H 1650 6850 50  0000 C CNN
	1    1650 6850
	-1   0    0    1   
$EndComp
$Comp
L GhostSensorboard-rescue:PWR_FLAG-RESCUE-GhostSensorboard #FLG011
U 1 1 5898ED01
P 1150 7000
F 0 "#FLG011" H 1150 7095 50  0001 C CNN
F 1 "PWR_FLAG" H 1150 7180 50  0000 C CNN
F 2 "" H 1150 7000 50  0000 C CNN
F 3 "" H 1150 7000 50  0000 C CNN
	1    1150 7000
	-1   0    0    1   
$EndComp
$Comp
L NorBot:TSOP753 U4
U 1 1 5898F42A
P 4900 7100
F 0 "U4" H 5150 6750 60  0000 C CNN
F 1 "TSOP753" H 4950 7350 60  0000 C CNN
F 2 "NorBotKiCadFootprints:TSOP75x" H 4850 7250 60  0001 C CNN
F 3 "" H 4850 7250 60  0001 C CNN
	1    4900 7100
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:C-RESCUE-GhostSensorboard C1
U 1 1 5898FEA1
P 4050 7150
F 0 "C1" H 4075 7250 50  0000 L CNN
F 1 "0.1uF" H 4075 7050 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 4088 7000 50  0001 C CNN
F 3 "" H 4050 7150 50  0000 C CNN
	1    4050 7150
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:R-RESCUE-GhostSensorboard R2
U 1 1 58990394
P 3750 7000
F 0 "R2" V 3830 7000 50  0000 C CNN
F 1 "100" V 3750 7000 50  0000 C CNN
F 2 "Resistors_SMD:R_0402" V 3680 7000 50  0001 C CNN
F 3 "" H 3750 7000 50  0000 C CNN
	1    3750 7000
	0    1    1    0   
$EndComp
$Comp
L GhostSensorboard-rescue:+3V3-RESCUE-GhostSensorboard #PWR012
U 1 1 589906CA
P 3500 6950
F 0 "#PWR012" H 3500 6800 50  0001 C CNN
F 1 "+3V3" H 3500 7090 50  0000 C CNN
F 2 "" H 3500 6950 50  0000 C CNN
F 3 "" H 3500 6950 50  0000 C CNN
	1    3500 6950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 6950 3500 7000
Wire Wire Line
	3900 7000 4050 7000
Connection ~ 4050 7000
Text GLabel 5550 7000 2    39   Input ~ 0
IR
Wire Wire Line
	5550 7000 5400 7000
Wire Wire Line
	3500 7000 3600 7000
Text Notes 4450 6700 0    39   ~ 0
Infrared Receiver, 38kHz\n(May optionally replace StartModule)\nTSOP75538WTR, Farnell no: 225-1430 (or similar)\nVoltage: 2.5-5.5V
Text GLabel 2150 3050 2    39   Input ~ 0
SDA_1
Text GLabel 2150 3150 2    39   Input ~ 0
SCL_1
$Comp
L GhostSensorboard-rescue:+3V3-RESCUE-GhostSensorboard #PWR013
U 1 1 5899A13A
P 1900 2550
F 0 "#PWR013" H 1900 2400 50  0001 C CNN
F 1 "+3V3" H 1900 2690 50  0000 C CNN
F 2 "" H 1900 2550 50  0000 C CNN
F 3 "" H 1900 2550 50  0000 C CNN
	1    1900 2550
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:R-RESCUE-GhostSensorboard R9
U 1 1 5899A68F
P 1900 2800
F 0 "R9" V 1980 2800 50  0000 C CNN
F 1 "2k2" V 1900 2800 50  0000 C CNN
F 2 "Resistors_SMD:R_0402" V 1830 2800 50  0001 C CNN
F 3 "" H 1900 2800 50  0000 C CNN
	1    1900 2800
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:R-RESCUE-GhostSensorboard R10
U 1 1 5899A851
P 2150 2800
F 0 "R10" V 2230 2800 50  0000 C CNN
F 1 "2k2" V 2150 2800 50  0000 C CNN
F 2 "Resistors_SMD:R_0402" V 2080 2800 50  0001 C CNN
F 3 "" H 2150 2800 50  0000 C CNN
	1    2150 2800
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:+3V3-RESCUE-GhostSensorboard #PWR014
U 1 1 5899AF0F
P 2150 2550
F 0 "#PWR014" H 2150 2400 50  0001 C CNN
F 1 "+3V3" H 2150 2690 50  0000 C CNN
F 2 "" H 2150 2550 50  0000 C CNN
F 3 "" H 2150 2550 50  0000 C CNN
	1    2150 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 3050 2150 2950
Wire Wire Line
	2150 2650 2150 2550
Wire Wire Line
	1900 2550 1900 2650
Wire Wire Line
	1900 2950 1900 3150
Wire Wire Line
	1900 3150 2150 3150
Text Notes 1800 2350 0    39   ~ 0
Pull-up resistors for \nI2C channel 1
$Comp
L GhostSensorboard-rescue:LED-RESCUE-GhostSensorboard D1
U 1 1 5899CB18
P 5200 3350
F 0 "D1" H 5200 3450 50  0000 C CNN
F 1 "LED" H 5200 3250 50  0000 C CNN
F 2 "LEDs:LED_0805" H 5200 3350 50  0001 C CNN
F 3 "" H 5200 3350 50  0000 C CNN
	1    5200 3350
	-1   0    0    1   
$EndComp
$Comp
L GhostSensorboard-rescue:R-RESCUE-GhostSensorboard R5
U 1 1 5899CD1A
P 4750 3350
F 0 "R5" V 4830 3350 50  0000 C CNN
F 1 "330" V 4750 3350 50  0000 C CNN
F 2 "Resistors_SMD:R_0402" V 4680 3350 50  0001 C CNN
F 3 "" H 4750 3350 50  0000 C CNN
	1    4750 3350
	0    1    1    0   
$EndComp
Text GLabel 5500 3350 2    39   Input ~ 0
LED
Wire Wire Line
	5500 3350 5350 3350
Text Notes 4550 3150 0    39   ~ 0
General purpose LED
Wire Wire Line
	5050 3350 4900 3350
Wire Wire Line
	4600 3350 4350 3350
$Comp
L GhostSensorboard-rescue:C-RESCUE-GhostSensorboard C2
U 1 1 589C78EB
P 5150 2150
F 0 "C2" H 5175 2250 50  0000 L CNN
F 1 "1nF" H 5175 2050 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5188 2000 50  0001 C CNN
F 3 "" H 5150 2150 50  0000 C CNN
	1    5150 2150
	0    1    1    0   
$EndComp
Wire Wire Line
	5000 2150 4850 2150
Wire Wire Line
	4850 2150 4850 1950
Connection ~ 4850 1950
$Comp
L GhostSensorboard-rescue:R-RESCUE-GhostSensorboard R4
U 1 1 589C8196
P 4550 1950
F 0 "R4" V 4630 1950 50  0000 C CNN
F 1 "470" V 4550 1950 50  0000 C CNN
F 2 "Resistors_SMD:R_0402" V 4480 1950 50  0001 C CNN
F 3 "" H 4550 1950 50  0000 C CNN
	1    4550 1950
	0    1    1    0   
$EndComp
Wire Wire Line
	5550 2150 5300 2150
Wire Wire Line
	5550 1950 5300 1950
Wire Wire Line
	4400 1950 4300 1950
$Comp
L GhostSensorboard-rescue:GND-RESCUE-GhostSensorboard #PWR015
U 1 1 589CADB2
P 4450 7400
F 0 "#PWR015" H 4450 7150 50  0001 C CNN
F 1 "GND" H 4450 7250 50  0000 C CNN
F 2 "" H 4450 7400 50  0000 C CNN
F 3 "" H 4450 7400 50  0000 C CNN
	1    4450 7400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 7200 4450 7300
Connection ~ 4450 7300
Wire Wire Line
	4050 7300 4450 7300
Wire Wire Line
	1150 7000 1150 6900
Connection ~ 1150 6900
Wire Wire Line
	1650 6850 1650 6800
Connection ~ 1650 6800
$Comp
L GhostSensorboard-rescue:PWR_FLAG-RESCUE-GhostSensorboard #FLG016
U 1 1 58ABBBC8
P 4050 6950
F 0 "#FLG016" H 4050 7045 50  0001 C CNN
F 1 "PWR_FLAG" H 4050 7130 50  0000 C CNN
F 2 "" H 4050 6950 50  0000 C CNN
F 3 "" H 4050 6950 50  0000 C CNN
	1    4050 6950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 6950 4050 7000
NoConn ~ 11350 3950
Text GLabel 1200 4650 2    39   Input ~ 0
STARTMODULE_POWER
$Sheet
S 950  750  1200 750 
U 58C865A6
F0 "IRSensors" 60
F1 "IRSensors.sch" 60
F2 "GPIO_SDA_0" I R 2150 900 60 
F3 "GPIO_SCL_0" I R 2150 1050 60 
F4 "GPIO_SDA_1" I R 2150 1200 60 
F5 "GPIO_SCL_1" I R 2150 1350 60 
$EndSheet
Text GLabel 2350 900  2    39   Input ~ 0
SDA_0
Text GLabel 2350 1050 2    39   Input ~ 0
SCL_0
Text GLabel 2350 1350 2    39   Input ~ 0
SCL_1
Text GLabel 2350 1200 2    39   Input ~ 0
SDA_1
Wire Wire Line
	2350 900  2150 900 
Wire Wire Line
	2150 1050 2350 1050
Wire Wire Line
	2350 1200 2150 1200
Wire Wire Line
	2150 1350 2350 1350
Text GLabel 1250 3050 2    39   Input ~ 0
SDA_0
Text GLabel 1250 3150 2    39   Input ~ 0
SCL_0
$Comp
L GhostSensorboard-rescue:+3V3-RESCUE-GhostSensorboard #PWR017
U 1 1 58CB73E4
P 1000 2550
F 0 "#PWR017" H 1000 2400 50  0001 C CNN
F 1 "+3V3" H 1000 2690 50  0000 C CNN
F 2 "" H 1000 2550 50  0000 C CNN
F 3 "" H 1000 2550 50  0000 C CNN
	1    1000 2550
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:R-RESCUE-GhostSensorboard R1
U 1 1 58CB73EA
P 1000 2800
F 0 "R1" V 1080 2800 50  0000 C CNN
F 1 "2k2" V 1000 2800 50  0000 C CNN
F 2 "Resistors_SMD:R_0402" V 930 2800 50  0001 C CNN
F 3 "" H 1000 2800 50  0000 C CNN
	1    1000 2800
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:R-RESCUE-GhostSensorboard R11
U 1 1 58CB73F0
P 1250 2800
F 0 "R11" V 1330 2800 50  0000 C CNN
F 1 "2k2" V 1250 2800 50  0000 C CNN
F 2 "Resistors_SMD:R_0402" V 1180 2800 50  0001 C CNN
F 3 "" H 1250 2800 50  0000 C CNN
	1    1250 2800
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:+3V3-RESCUE-GhostSensorboard #PWR018
U 1 1 58CB73F6
P 1250 2550
F 0 "#PWR018" H 1250 2400 50  0001 C CNN
F 1 "+3V3" H 1250 2690 50  0000 C CNN
F 2 "" H 1250 2550 50  0000 C CNN
F 3 "" H 1250 2550 50  0000 C CNN
	1    1250 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1250 3050 1250 2950
Wire Wire Line
	1250 2650 1250 2550
Wire Wire Line
	1000 2550 1000 2650
Wire Wire Line
	1000 2950 1000 3150
Wire Wire Line
	1000 3150 1250 3150
Text Notes 900  2350 0    39   ~ 0
Pull-up resistors for \nI2C channel 0
$Comp
L GhostSensorboard-rescue:+5V-RESCUE-GhostSensorboard #PWR019
U 1 1 58CA0557
P 1750 6800
F 0 "#PWR019" H 1750 6650 50  0001 C CNN
F 1 "+5V" H 1750 6940 50  0000 C CNN
F 2 "" H 1750 6800 50  0000 C CNN
F 3 "" H 1750 6800 50  0000 C CNN
	1    1750 6800
	0    1    1    0   
$EndComp
Text GLabel 9700 1800 0    39   Input ~ 0
IO32
$Comp
L GhostSensorboard-rescue:CONN_02X20-RESCUE-GhostSensorboard J2
U 1 1 58CCD7A3
P 10100 2550
F 0 "J2" H 10100 3715 50  0000 C CNN
F 1 "CONN_02X20" H 10100 3624 50  0000 C CNN
F 2 "hrs-fx8c:hrs-fx8c-40s-sv5" H 10100 1600 50  0001 C CNN
F 3 "" H 10100 1600 50  0001 C CNN
	1    10100 2550
	1    0    0    -1  
$EndComp
$Comp
L NorBot:Transmissive_Photo_Interrupter U5
U 1 1 58CCEC44
P 6800 5400
F 0 "U5" H 6875 6137 60  0000 C CNN
F 1 "Transmissive_Photo_Interrupter" H 6875 6031 60  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 6800 5400 60  0001 C CNN
F 3 "" H 6800 5400 60  0000 C CNN
	1    6800 5400
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:GND-RESCUE-GhostSensorboard #PWR020
U 1 1 58CCF0A9
P 5950 5650
F 0 "#PWR020" H 5950 5400 50  0001 C CNN
F 1 "GND" H 5955 5477 50  0000 C CNN
F 2 "" H 5950 5650 50  0001 C CNN
F 3 "" H 5950 5650 50  0001 C CNN
	1    5950 5650
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:+5V-RESCUE-GhostSensorboard #PWR021
U 1 1 58CCF43A
P 5550 4950
F 0 "#PWR021" H 5550 4800 50  0001 C CNN
F 1 "+5V" H 5565 5123 50  0000 C CNN
F 2 "" H 5550 4950 50  0001 C CNN
F 3 "" H 5550 4950 50  0001 C CNN
	1    5550 4950
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:R-RESCUE-GhostSensorboard R14
U 1 1 58CCF4A6
P 5800 5000
F 0 "R14" V 5593 5000 50  0000 C CNN
F 1 "270" V 5684 5000 50  0000 C CNN
F 2 "Resistors_SMD:R_0402" V 5730 5000 50  0001 C CNN
F 3 "" H 5800 5000 50  0001 C CNN
	1    5800 5000
	0    1    1    0   
$EndComp
$Comp
L GhostSensorboard-rescue:GND-RESCUE-GhostSensorboard #PWR022
U 1 1 58CCF842
P 7850 5000
F 0 "#PWR022" H 7850 4750 50  0001 C CNN
F 1 "GND" H 7855 4827 50  0000 C CNN
F 2 "" H 7850 5000 50  0001 C CNN
F 3 "" H 7850 5000 50  0001 C CNN
	1    7850 5000
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:R-RESCUE-GhostSensorboard R15
U 1 1 58CCF899
P 8050 5500
F 0 "R15" V 7843 5500 50  0000 C CNN
F 1 "10k" V 7934 5500 50  0000 C CNN
F 2 "Resistors_SMD:R_0402" V 7980 5500 50  0001 C CNN
F 3 "" H 8050 5500 50  0001 C CNN
	1    8050 5500
	0    1    1    0   
$EndComp
$Comp
L GhostSensorboard-rescue:+5V-RESCUE-GhostSensorboard #PWR023
U 1 1 58CD056A
P 8350 5500
F 0 "#PWR023" H 8350 5350 50  0001 C CNN
F 1 "+5V" H 8365 5673 50  0000 C CNN
F 2 "" H 8350 5500 50  0001 C CNN
F 3 "" H 8350 5500 50  0001 C CNN
	1    8350 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 4950 7850 4950
Wire Wire Line
	7850 4950 7850 5000
Wire Wire Line
	7700 5500 7800 5500
Wire Wire Line
	8200 5500 8350 5500
Wire Wire Line
	8050 5700 7800 5700
Wire Wire Line
	7800 5700 7800 5500
Connection ~ 7800 5500
Wire Wire Line
	6050 5550 5950 5550
Wire Wire Line
	5950 5550 5950 5650
Wire Wire Line
	6050 5000 5950 5000
Wire Wire Line
	5650 5000 5550 5000
Wire Wire Line
	5550 5000 5550 4950
Text Notes 6600 5950 0    60   ~ 0
Encoder\nKTIR0611S
$Comp
L GhostSensorboard-rescue:GND-RESCUE-GhostSensorboard #PWR024
U 1 1 58CD8239
P 9650 2300
F 0 "#PWR024" H 9650 2050 50  0001 C CNN
F 1 "GND" H 9650 2150 50  0000 C CNN
F 2 "" H 9650 2300 50  0000 C CNN
F 3 "" H 9650 2300 50  0000 C CNN
	1    9650 2300
	0    1    1    0   
$EndComp
$Comp
L GhostSensorboard-rescue:+3V3-RESCUE-GhostSensorboard #PWR025
U 1 1 58CD83E6
P 9550 1900
F 0 "#PWR025" H 9550 1750 50  0001 C CNN
F 1 "+3V3" H 9550 2040 50  0000 C CNN
F 2 "" H 9550 1900 50  0000 C CNN
F 3 "" H 9550 1900 50  0000 C CNN
	1    9550 1900
	0    -1   -1   0   
$EndComp
$Comp
L GhostSensorboard-rescue:+5V-RESCUE-GhostSensorboard #PWR026
U 1 1 58CD843D
P 9650 3300
F 0 "#PWR026" H 9650 3150 50  0001 C CNN
F 1 "+5V" H 9650 3440 50  0000 C CNN
F 2 "" H 9650 3300 50  0000 C CNN
F 3 "" H 9650 3300 50  0000 C CNN
	1    9650 3300
	0    -1   -1   0   
$EndComp
Text Notes 9550 1200 0    60   ~ 0
Bottom connector, 40 pin\nHirose FX8C-40S-SV5\nFarnell no: 249-8688
$Comp
L GhostSensorboard-rescue:+3V3-RESCUE-GhostSensorboard #PWR027
U 1 1 58CD905B
P 9150 2000
F 0 "#PWR027" H 9150 1850 50  0001 C CNN
F 1 "+3V3" H 9150 2140 50  0000 C CNN
F 2 "" H 9150 2000 50  0000 C CNN
F 3 "" H 9150 2000 50  0000 C CNN
	1    9150 2000
	0    -1   -1   0   
$EndComp
$Comp
L GhostSensorboard-rescue:+3V3-RESCUE-GhostSensorboard #PWR028
U 1 1 58CD90E6
P 10550 1900
F 0 "#PWR028" H 10550 1750 50  0001 C CNN
F 1 "+3V3" H 10550 2040 50  0000 C CNN
F 2 "" H 10550 1900 50  0000 C CNN
F 3 "" H 10550 1900 50  0000 C CNN
	1    10550 1900
	0    1    1    0   
$EndComp
$Comp
L GhostSensorboard-rescue:+3V3-RESCUE-GhostSensorboard #PWR029
U 1 1 58CD9189
P 10650 2000
F 0 "#PWR029" H 10650 1850 50  0001 C CNN
F 1 "+3V3" H 10650 2140 50  0000 C CNN
F 2 "" H 10650 2000 50  0000 C CNN
F 3 "" H 10650 2000 50  0000 C CNN
	1    10650 2000
	0    1    1    0   
$EndComp
$Comp
L GhostSensorboard-rescue:+5V-RESCUE-GhostSensorboard #PWR030
U 1 1 58CD92C2
P 9650 3400
F 0 "#PWR030" H 9650 3250 50  0001 C CNN
F 1 "+5V" H 9650 3540 50  0000 C CNN
F 2 "" H 9650 3400 50  0000 C CNN
F 3 "" H 9650 3400 50  0000 C CNN
	1    9650 3400
	0    -1   -1   0   
$EndComp
$Comp
L GhostSensorboard-rescue:+5V-RESCUE-GhostSensorboard #PWR031
U 1 1 58CD9319
P 9650 3500
F 0 "#PWR031" H 9650 3350 50  0001 C CNN
F 1 "+5V" H 9650 3640 50  0000 C CNN
F 2 "" H 9650 3500 50  0000 C CNN
F 3 "" H 9650 3500 50  0000 C CNN
	1    9650 3500
	0    -1   -1   0   
$EndComp
$Comp
L GhostSensorboard-rescue:+5V-RESCUE-GhostSensorboard #PWR032
U 1 1 58CD9370
P 10500 3300
F 0 "#PWR032" H 10500 3150 50  0001 C CNN
F 1 "+5V" H 10500 3440 50  0000 C CNN
F 2 "" H 10500 3300 50  0000 C CNN
F 3 "" H 10500 3300 50  0000 C CNN
	1    10500 3300
	0    1    1    0   
$EndComp
$Comp
L GhostSensorboard-rescue:+5V-RESCUE-GhostSensorboard #PWR033
U 1 1 58CD9413
P 10500 3400
F 0 "#PWR033" H 10500 3250 50  0001 C CNN
F 1 "+5V" H 10500 3540 50  0000 C CNN
F 2 "" H 10500 3400 50  0000 C CNN
F 3 "" H 10500 3400 50  0000 C CNN
	1    10500 3400
	0    1    1    0   
$EndComp
$Comp
L GhostSensorboard-rescue:+5V-RESCUE-GhostSensorboard #PWR034
U 1 1 58CD946A
P 10500 3500
F 0 "#PWR034" H 10500 3350 50  0001 C CNN
F 1 "+5V" H 10500 3640 50  0000 C CNN
F 2 "" H 10500 3500 50  0000 C CNN
F 3 "" H 10500 3500 50  0000 C CNN
	1    10500 3500
	0    1    1    0   
$EndComp
$Comp
L GhostSensorboard-rescue:GND-RESCUE-GhostSensorboard #PWR035
U 1 1 58CDA5F7
P 9650 2400
F 0 "#PWR035" H 9650 2150 50  0001 C CNN
F 1 "GND" H 9650 2250 50  0000 C CNN
F 2 "" H 9650 2400 50  0000 C CNN
F 3 "" H 9650 2400 50  0000 C CNN
	1    9650 2400
	0    1    1    0   
$EndComp
$Comp
L GhostSensorboard-rescue:GND-RESCUE-GhostSensorboard #PWR036
U 1 1 58CDA64E
P 9650 2500
F 0 "#PWR036" H 9650 2250 50  0001 C CNN
F 1 "GND" H 9650 2350 50  0000 C CNN
F 2 "" H 9650 2500 50  0000 C CNN
F 3 "" H 9650 2500 50  0000 C CNN
	1    9650 2500
	0    1    1    0   
$EndComp
$Comp
L GhostSensorboard-rescue:GND-RESCUE-GhostSensorboard #PWR037
U 1 1 58CDA6A5
P 10500 2300
F 0 "#PWR037" H 10500 2050 50  0001 C CNN
F 1 "GND" H 10500 2150 50  0000 C CNN
F 2 "" H 10500 2300 50  0000 C CNN
F 3 "" H 10500 2300 50  0000 C CNN
	1    10500 2300
	0    -1   -1   0   
$EndComp
$Comp
L GhostSensorboard-rescue:GND-RESCUE-GhostSensorboard #PWR038
U 1 1 58CDA748
P 10500 2400
F 0 "#PWR038" H 10500 2150 50  0001 C CNN
F 1 "GND" H 10500 2250 50  0000 C CNN
F 2 "" H 10500 2400 50  0000 C CNN
F 3 "" H 10500 2400 50  0000 C CNN
	1    10500 2400
	0    -1   -1   0   
$EndComp
$Comp
L GhostSensorboard-rescue:GND-RESCUE-GhostSensorboard #PWR039
U 1 1 58CDA79F
P 10500 2500
F 0 "#PWR039" H 10500 2250 50  0001 C CNN
F 1 "GND" H 10500 2350 50  0000 C CNN
F 2 "" H 10500 2500 50  0000 C CNN
F 3 "" H 10500 2500 50  0000 C CNN
	1    10500 2500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9850 2300 9650 2300
Wire Wire Line
	9850 2400 9650 2400
Wire Wire Line
	9650 2500 9850 2500
Wire Wire Line
	9550 1900 9850 1900
Wire Wire Line
	9850 2000 9200 2000
Wire Wire Line
	10550 1900 10350 1900
Wire Wire Line
	10350 2000 10650 2000
Wire Wire Line
	10500 2300 10350 2300
Wire Wire Line
	10350 2400 10500 2400
Wire Wire Line
	10500 2500 10350 2500
Wire Wire Line
	9650 3300 9850 3300
Wire Wire Line
	9850 3400 9650 3400
Wire Wire Line
	9650 3500 9850 3500
Wire Wire Line
	10500 3300 10350 3300
Wire Wire Line
	10350 3400 10500 3400
Wire Wire Line
	10500 3500 10350 3500
Text GLabel 9700 1600 0    39   Input ~ 0
IO27
Text GLabel 9700 1700 0    39   Input ~ 0
IO25
Wire Wire Line
	9850 1600 9700 1600
Wire Wire Line
	9700 1700 9850 1700
Text GLabel 7650 2750 0    39   Input ~ 0
IO27
Wire Wire Line
	7850 2750 7650 2750
Text Notes 7450 950  0    60   ~ 0
Mapping of ESP32 GPIO's \nto physical devices
Wire Notes Line
	8900 4200 7150 4200
Wire Notes Line
	7150 4200 7150 550 
Text GLabel 7650 2550 0    39   Input ~ 0
IO25
Wire Wire Line
	7850 2550 7650 2550
Wire Wire Line
	9850 1800 9700 1800
Text GLabel 10500 1600 2    39   Input ~ 0
IO26
Text GLabel 10500 1700 2    39   Input ~ 0
IO33
NoConn ~ 10350 1800
NoConn ~ 10350 2100
NoConn ~ 9850 2100
$Comp
L GhostSensorboard-rescue:GND-RESCUE-GhostSensorboard #PWR040
U 1 1 58CE5F6D
P 9650 2200
F 0 "#PWR040" H 9650 1950 50  0001 C CNN
F 1 "GND" H 9650 2050 50  0000 C CNN
F 2 "" H 9650 2200 50  0000 C CNN
F 3 "" H 9650 2200 50  0000 C CNN
	1    9650 2200
	0    1    1    0   
$EndComp
$Comp
L GhostSensorboard-rescue:GND-RESCUE-GhostSensorboard #PWR041
U 1 1 58CE5FC4
P 10500 2200
F 0 "#PWR041" H 10500 1950 50  0001 C CNN
F 1 "GND" H 10500 2050 50  0000 C CNN
F 2 "" H 10500 2200 50  0000 C CNN
F 3 "" H 10500 2200 50  0000 C CNN
	1    10500 2200
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9850 2200 9650 2200
Wire Wire Line
	10350 2200 10500 2200
Text GLabel 9750 2700 0    39   Input ~ 0
IO21
Text GLabel 9750 2800 0    39   Input ~ 0
IO18
Text GLabel 9750 2900 0    39   Input ~ 0
IO16
NoConn ~ 9850 3000
NoConn ~ 9850 3100
Text GLabel 9750 3200 0    39   Input ~ 0
IO13
Wire Wire Line
	9850 2600 9750 2600
Wire Wire Line
	9750 2700 9850 2700
Wire Wire Line
	9850 2800 9750 2800
Wire Wire Line
	9750 2900 9850 2900
Wire Wire Line
	9850 3200 9750 3200
Text GLabel 10500 2600 2    39   Input ~ 0
IO22
Text GLabel 10500 2700 2    39   Input ~ 0
IO19
Text GLabel 10500 2800 2    39   Input ~ 0
IO17
Text GLabel 10500 2900 2    39   Input ~ 0
IO4
Text GLabel 10500 3200 2    39   Input ~ 0
IO14
NoConn ~ 10350 3000
NoConn ~ 10350 3100
Wire Wire Line
	10500 3200 10350 3200
Wire Wire Line
	10500 2600 10350 2600
Wire Wire Line
	10350 2700 10500 2700
Wire Wire Line
	10500 2800 10350 2800
Wire Wire Line
	10350 2900 10500 2900
Text GLabel 7650 2850 0    39   Input ~ 0
IO32
Text GLabel 7650 2350 0    39   Input ~ 0
IO22
Text GLabel 7650 2250 0    39   Input ~ 0
IO21
Text GLabel 7650 2050 0    39   Input ~ 0
IO18
Text GLabel 7650 1850 0    39   Input ~ 0
IO16
Text GLabel 7650 1650 0    39   Input ~ 0
IO13
Text GLabel 7650 2650 0    39   Input ~ 0
IO26
Text GLabel 7650 2950 0    39   Input ~ 0
IO33
Text GLabel 7650 2150 0    39   Input ~ 0
IO19
Text GLabel 7650 1950 0    39   Input ~ 0
IO17
Text GLabel 7650 1550 0    39   Input ~ 0
IO4
Text GLabel 7650 1750 0    39   Input ~ 0
IO14
Text GLabel 7850 2050 2    39   Input ~ 0
BUTTON
Text GLabel 9750 2600 0    39   Input ~ 0
LED
Text GLabel 7850 1650 2    39   Input ~ 0
SDA_0
Text GLabel 7850 1750 2    39   Input ~ 0
SCL_0
Text GLabel 7850 2950 2    39   Input ~ 0
SDA_1
Text GLabel 7850 2850 2    39   Input ~ 0
SCL_1
Text GLabel 7850 2350 2    39   Input ~ 0
IR
Wire Wire Line
	7650 1950 7850 1950
Wire Wire Line
	7850 2050 7650 2050
Wire Wire Line
	7650 2150 7850 2150
Wire Wire Line
	7850 1650 7650 1650
Wire Wire Line
	7650 1750 7850 1750
Wire Wire Line
	7850 2850 7650 2850
NoConn ~ 7650 1550
$Comp
L GhostSensorboard-rescue:PWR_FLAG-RESCUE-GhostSensorboard #FLG042
U 1 1 58CEF1EF
P 9200 1900
F 0 "#FLG042" H 9200 1995 50  0001 C CNN
F 1 "PWR_FLAG" H 9200 2080 50  0000 C CNN
F 2 "" H 9200 1900 50  0000 C CNN
F 3 "" H 9200 1900 50  0000 C CNN
	1    9200 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	9200 1900 9200 2000
Connection ~ 9200 2000
Wire Wire Line
	10350 1600 10500 1600
Wire Wire Line
	10500 1700 10350 1700
Text GLabel 7850 2150 2    39   Input ~ 0
ENCODER
Text GLabel 8050 5700 2    39   Input ~ 0
ENCODER
Text GLabel 1250 6700 2    39   Input ~ 0
MOTOR_5V_PWM
Text GLabel 7850 2750 2    39   Input ~ 0
MOTOR__3V3_PWM
Text GLabel 7850 1950 2    39   Input ~ 0
STARTMODULE_POWER
Text GLabel 7850 2550 2    39   Input ~ 0
STARTMODULE_SIGNAL
Text GLabel 10550 6250 2    39   Input ~ 0
STEERING_5V_PWM
Text GLabel 7850 2650 2    39   Input ~ 0
STEERING_3V3_PWM
Text Notes 7300 1400 0    39   ~ 0
NB, IO23 is dedicated to LED\nNB, IO32 (SCL) and IO33 (SDA) is dedicated to I2C
Wire Wire Line
	7650 2650 7850 2650
Wire Wire Line
	7650 2950 7850 2950
NoConn ~ 7650 2250
Wire Wire Line
	7850 2350 7650 2350
NoConn ~ 7650 1850
$Comp
L GhostSensorboard-rescue:+3V3-RESCUE-GhostSensorboard #PWR043
U 1 1 58CE6D89
P 4350 3350
F 0 "#PWR043" H 4350 3200 50  0001 C CNN
F 1 "+3V3" H 4350 3490 50  0000 C CNN
F 2 "" H 4350 3350 50  0000 C CNN
F 3 "" H 4350 3350 50  0000 C CNN
	1    4350 3350
	0    -1   -1   0   
$EndComp
Wire Notes Line
	8750 4250 8750 6500
Wire Notes Line
	600  1950 3400 1950
Wire Notes Line
	3400 1950 3400 550 
Wire Notes Line
	550  3600 3400 3600
Wire Notes Line
	3400 3600 3400 2000
Wire Notes Line
	3200 3700 3200 7700
Wire Notes Line
	3200 7700 3250 7700
Wire Notes Line
	7050 4200 3350 4200
Wire Notes Line
	6900 6500 6900 6200
Wire Notes Line
	6900 6200 3400 6200
Wire Notes Line
	3700 2700 6950 2700
Wire Notes Line
	6950 2700 6950 2750
Wire Wire Line
	9800 6250 9900 6250
Wire Wire Line
	10400 6250 10550 6250
Wire Wire Line
	9800 5800 9800 5850
Wire Wire Line
	9800 5350 9900 5350
Wire Wire Line
	10400 5350 10550 5350
Wire Wire Line
	9800 4900 9800 4950
Wire Wire Line
	4050 7000 4450 7000
Wire Wire Line
	4850 1950 4900 1950
Wire Wire Line
	4450 7300 4450 7400
Wire Wire Line
	1150 6900 1250 6900
Wire Wire Line
	1650 6800 1750 6800
Wire Wire Line
	7800 5500 7900 5500
Wire Wire Line
	9200 2000 9150 2000
$EndSCHEMATC
