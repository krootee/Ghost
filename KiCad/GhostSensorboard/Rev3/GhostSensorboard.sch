EESchema Schematic File Version 4
LIBS:GhostSensorboard-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 2
Title "Ghost Sensorboard"
Date "2017-08-08"
Rev "3"
Comp "Frode Lillerud"
Comment1 "https://github.com/Scalpel78/Ghost/tree/master/KiCad/GhostSensorboard/Rev3"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 4250 950  0    118  ~ 24
Ghost Sensorboard Rev 3
Text Notes 4600 1250 0    59   ~ 0
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
Text Notes 10600 850  2    39   ~ 0
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
Text Notes 10550 4500 2    39   ~ 0
Level shifting IO signals from 3V3 to 5V.
Text GLabel 1200 4850 2    39   Input ~ 0
STARTMODULE_SIGNAL
$Comp
L GhostSensorboard-rescue:SW_Push-RESCUE-GhostSensorboard SW1
U 1 1 5898C790
P 6550 3500
F 0 "SW1" H 6600 3600 50  0000 L CNN
F 1 "SW_Push" H 6550 3440 50  0000 C CNN
F 2 "Buttons_Switches_SMD:SW_SPST_EVQP2" H 6550 3700 50  0001 C CNN
F 3 "" H 6550 3700 50  0000 C CNN
	1    6550 3500
	1    0    0    -1  
$EndComp
Text GLabel 5750 3500 0    39   Input ~ 0
BUTTON
$Comp
L GhostSensorboard-rescue:GND-RESCUE-GhostSensorboard #PWR09
U 1 1 5898D566
P 7000 3700
F 0 "#PWR09" H 7000 3450 50  0001 C CNN
F 1 "GND" H 7000 3550 50  0000 C CNN
F 2 "" H 7000 3700 50  0000 C CNN
F 3 "" H 7000 3700 50  0000 C CNN
	1    7000 3700
	1    0    0    -1  
$EndComp
Text Notes 5800 3300 0    39   ~ 0
General purpose switch.\nUse internal pull-up resistor in ESP32.\nKMR2216 (Farnell no: 120-1424)
$Comp
L GhostSensorboard-rescue:PWR_FLAG-RESCUE-GhostSensorboard #FLG010
U 1 1 5898ED01
P 1150 7000
F 0 "#FLG010" H 1150 7095 50  0001 C CNN
F 1 "PWR_FLAG" H 1150 7180 50  0000 C CNN
F 2 "" H 1150 7000 50  0000 C CNN
F 3 "" H 1150 7000 50  0000 C CNN
	1    1150 7000
	-1   0    0    1   
$EndComp
$Comp
L GhostSensorboard-rescue:C-RESCUE-GhostSensorboard C1
U 1 1 5898FEA1
P 4050 7150
F 0 "C1" H 4075 7250 50  0000 L CNN
F 1 "1uF" H 4075 7050 50  0000 L CNN
F 2 "Capacitors_SMD:C_0402" H 4088 7000 50  0001 C CNN
F 3 "" H 4050 7150 50  0000 C CNN
	1    4050 7150
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:R-RESCUE-GhostSensorboard R2
U 1 1 58990394
P 3750 7000
F 0 "R2" V 3650 7000 50  0000 C CNN
F 1 "33-1k ohm" V 3850 6950 50  0000 C CNN
F 2 "Resistors_SMD:R_0402" V 3680 7000 50  0001 C CNN
F 3 "" H 3750 7000 50  0000 C CNN
	1    3750 7000
	0    1    1    0   
$EndComp
$Comp
L GhostSensorboard-rescue:+3V3-RESCUE-GhostSensorboard #PWR011
U 1 1 589906CA
P 3500 6950
F 0 "#PWR011" H 3500 6800 50  0001 C CNN
F 1 "+3V3" H 3500 7090 50  0000 C CNN
F 2 "" H 3500 6950 50  0000 C CNN
F 3 "" H 3500 6950 50  0000 C CNN
	1    3500 6950
	1    0    0    -1  
$EndComp
Text GLabel 5550 7000 2    39   Input ~ 0
IR
Text Notes 4450 6700 0    39   ~ 0
Infrared Receiver, 38kHz\n(May optionally replace StartModule)\nTSOP75438WTT, Farnell no: 225-1422 (or similar)\nVoltage: 2.5-5.5V\nResistor should be in range 33 -> 1k ohm\nCapacitor should be over 0.1uF
$Comp
L GhostSensorboard-rescue:LED-RESCUE-GhostSensorboard D1
U 1 1 5899CB18
P 4700 3100
F 0 "D1" H 4700 3200 50  0000 C CNN
F 1 "LED" H 4700 3000 50  0000 C CNN
F 2 "LEDs:LED_0603" H 4700 3100 50  0001 C CNN
F 3 "" H 4700 3100 50  0000 C CNN
	1    4700 3100
	-1   0    0    1   
$EndComp
$Comp
L GhostSensorboard-rescue:R-RESCUE-GhostSensorboard R5
U 1 1 5899CD1A
P 4250 3100
F 0 "R5" V 4330 3100 50  0000 C CNN
F 1 "330" V 4250 3100 50  0000 C CNN
F 2 "Resistors_SMD:R_0402" V 4180 3100 50  0001 C CNN
F 3 "" H 4250 3100 50  0000 C CNN
	1    4250 3100
	0    1    1    0   
$EndComp
Text GLabel 5000 3100 2    39   Input ~ 0
LED
Text Notes 4050 2900 0    39   ~ 0
General purpose LEDs
$Comp
L GhostSensorboard-rescue:C-RESCUE-GhostSensorboard C2
U 1 1 589C78EB
P 6600 3700
F 0 "C2" H 6625 3800 50  0000 L CNN
F 1 "1nF" H 6625 3600 50  0000 L CNN
F 2 "Capacitors_SMD:C_0402" H 6638 3550 50  0001 C CNN
F 3 "" H 6600 3700 50  0000 C CNN
	1    6600 3700
	0    1    1    0   
$EndComp
$Comp
L GhostSensorboard-rescue:R-RESCUE-GhostSensorboard R4
U 1 1 589C8196
P 6000 3500
F 0 "R4" V 6080 3500 50  0000 C CNN
F 1 "470" V 6000 3500 50  0000 C CNN
F 2 "Resistors_SMD:R_0402" V 5930 3500 50  0001 C CNN
F 3 "" H 6000 3500 50  0000 C CNN
	1    6000 3500
	0    1    1    0   
$EndComp
$Comp
L GhostSensorboard-rescue:GND-RESCUE-GhostSensorboard #PWR012
U 1 1 589CADB2
P 4450 7400
F 0 "#PWR012" H 4450 7150 50  0001 C CNN
F 1 "GND" H 4450 7250 50  0000 C CNN
F 2 "" H 4450 7400 50  0000 C CNN
F 3 "" H 4450 7400 50  0000 C CNN
	1    4450 7400
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:PWR_FLAG-RESCUE-GhostSensorboard #FLG013
U 1 1 58ABBBC8
P 4050 6950
F 0 "#FLG013" H 4050 7045 50  0001 C CNN
F 1 "PWR_FLAG" H 4050 7130 50  0000 C CNN
F 2 "" H 4050 6950 50  0000 C CNN
F 3 "" H 4050 6950 50  0000 C CNN
	1    4050 6950
	1    0    0    -1  
$EndComp
Text GLabel 1200 4650 2    39   Input ~ 0
STARTMODULE_POWER
$Sheet
S 950  750  700  450 
U 58C865A6
F0 "IRSensors" 60
F1 "IRSensors.sch" 60
F2 "GPIO_SDA_0" I R 1650 900 60 
F3 "GPIO_SCL_0" I R 1650 1050 60 
$EndSheet
Text GLabel 1850 1050 2    39   Input ~ 0
SCL
Text GLabel 1250 3050 2    39   Input ~ 0
SDA
Text GLabel 1250 3150 2    39   Input ~ 0
SCL
$Comp
L GhostSensorboard-rescue:+3V3-RESCUE-GhostSensorboard #PWR014
U 1 1 58CB73E4
P 1000 2550
F 0 "#PWR014" H 1000 2400 50  0001 C CNN
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
L GhostSensorboard-rescue:+3V3-RESCUE-GhostSensorboard #PWR015
U 1 1 58CB73F6
P 1250 2550
F 0 "#PWR015" H 1250 2400 50  0001 C CNN
F 1 "+3V3" H 1250 2690 50  0000 C CNN
F 2 "" H 1250 2550 50  0000 C CNN
F 3 "" H 1250 2550 50  0000 C CNN
	1    1250 2550
	1    0    0    -1  
$EndComp
Text Notes 900  2350 0    39   ~ 0
(Not connected if used on main board)\nPull-up resistors for \nI2C channel 0
$Comp
L GhostSensorboard-rescue:+5V-RESCUE-GhostSensorboard #PWR016
U 1 1 58CA0557
P 1750 6800
F 0 "#PWR016" H 1750 6650 50  0001 C CNN
F 1 "+5V" H 1750 6940 50  0000 C CNN
F 2 "" H 1750 6800 50  0000 C CNN
F 3 "" H 1750 6800 50  0000 C CNN
	1    1750 6800
	0    1    1    0   
$EndComp
Text GLabel 9550 2250 0    39   Input ~ 0
IO32/SCL
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
L GhostSensorboard-rescue:GND-RESCUE-GhostSensorboard #PWR017
U 1 1 58CCF0A9
P 5950 5650
F 0 "#PWR017" H 5950 5400 50  0001 C CNN
F 1 "GND" H 5955 5477 50  0000 C CNN
F 2 "" H 5950 5650 50  0001 C CNN
F 3 "" H 5950 5650 50  0001 C CNN
	1    5950 5650
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:+5V-RESCUE-GhostSensorboard #PWR018
U 1 1 58CCF43A
P 5550 4950
F 0 "#PWR018" H 5550 4800 50  0001 C CNN
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
L GhostSensorboard-rescue:GND-RESCUE-GhostSensorboard #PWR019
U 1 1 58CCF842
P 7850 5000
F 0 "#PWR019" H 7850 4750 50  0001 C CNN
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
L GhostSensorboard-rescue:+5V-RESCUE-GhostSensorboard #PWR020
U 1 1 58CD056A
P 8350 5500
F 0 "#PWR020" H 8350 5350 50  0001 C CNN
F 1 "+5V" H 8365 5673 50  0000 C CNN
F 2 "" H 8350 5500 50  0001 C CNN
F 3 "" H 8350 5500 50  0001 C CNN
	1    8350 5500
	1    0    0    -1  
$EndComp
Text Notes 6600 5950 0    60   ~ 0
Encoder\nKTIR0611S
Text GLabel 9550 1850 0    39   Input ~ 0
IO27
Text GLabel 9550 2050 0    39   Input ~ 0
IO25
Text GLabel 7650 2750 0    39   Input ~ 0
IO27
Text Notes 7450 950  0    60   ~ 0
Mapping of ESP32 GPIO's \nto physical devices
Text GLabel 7650 2550 0    39   Input ~ 0
IO25
Text GLabel 9550 1950 0    39   Input ~ 0
IO26
Text GLabel 9550 2150 0    39   Input ~ 0
IO33/SDA
Text GLabel 10550 2250 2    39   Input ~ 0
IO21
Text GLabel 10550 2050 2    39   Input ~ 0
IO18
Text GLabel 10550 1850 2    39   Input ~ 0
IO16
Text GLabel 9550 2450 0    39   Input ~ 0
IO13
Text GLabel 10550 2350 2    39   Input ~ 0
IO22
Text GLabel 10550 2150 2    39   Input ~ 0
IO19
Text GLabel 10550 1950 2    39   Input ~ 0
IO17
Text GLabel 10550 1750 2    39   Input ~ 0
IO4
Text GLabel 9550 2350 0    39   Input ~ 0
IO14
Text GLabel 7650 2850 0    39   Input ~ 0
IO32/SCL
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
IO33/SDA
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
Text GLabel 10550 1650 2    39   Input ~ 0
LED
Text GLabel 7850 2950 2    39   Input ~ 0
SDA
Text GLabel 7850 2850 2    39   Input ~ 0
SCL
Text GLabel 7850 2350 2    39   Input ~ 0
IR
NoConn ~ 7650 1550
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
$Comp
L GhostSensorboard-rescue:+3V3-RESCUE-GhostSensorboard #PWR021
U 1 1 58CE6D89
P 3850 3100
F 0 "#PWR021" H 3850 2950 50  0001 C CNN
F 1 "+3V3" H 3850 3240 50  0000 C CNN
F 2 "" H 3850 3100 50  0000 C CNN
F 3 "" H 3850 3100 50  0000 C CNN
	1    3850 3100
	0    -1   -1   0   
$EndComp
$Comp
L GhostSensorboard-rescue:CONN_01X14-RESCUE-GhostSensorboard J1
U 1 1 5942E695
P 9900 2200
F 0 "J1" H 9900 3000 50  0000 L CNN
F 1 "CONN_01X14" V 10000 1900 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x14_Pitch2.54mm" H 9900 2200 50  0001 C CNN
F 3 "" H 9900 2200 50  0001 C CNN
	1    9900 2200
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:CONN_01X10-RESCUE-GhostSensorboard J2
U 1 1 5942E9B1
P 10250 2000
F 0 "J2" H 10250 2550 50  0000 L CNN
F 1 "CONN_01X10" V 10350 1500 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x10_Pitch2.54mm" H 10250 2000 50  0001 C CNN
F 3 "" H 10250 2000 50  0001 C CNN
	1    10250 2000
	-1   0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:+BATT-RESCUE-GhostSensorboard #PWR022
U 1 1 5942F6FD
P 9550 1550
F 0 "#PWR022" H 9550 1400 50  0001 C CNN
F 1 "+BATT" V 9565 1677 50  0000 L CNN
F 2 "" H 9550 1550 50  0001 C CNN
F 3 "" H 9550 1550 50  0001 C CNN
	1    9550 1550
	0    -1   -1   0   
$EndComp
$Comp
L GhostSensorboard-rescue:GND-RESCUE-GhostSensorboard #PWR023
U 1 1 5942FA42
P 9550 1650
F 0 "#PWR023" H 9550 1400 50  0001 C CNN
F 1 "GND" V 9550 1450 50  0000 C CNN
F 2 "" H 9550 1650 50  0000 C CNN
F 3 "" H 9550 1650 50  0000 C CNN
	1    9550 1650
	0    1    1    0   
$EndComp
$Comp
L GhostSensorboard-rescue:+3V3-RESCUE-GhostSensorboard #PWR024
U 1 1 5942FAE9
P 9100 1750
F 0 "#PWR024" H 9100 1600 50  0001 C CNN
F 1 "+3V3" V 9100 2000 50  0000 C CNN
F 2 "" H 9100 1750 50  0000 C CNN
F 3 "" H 9100 1750 50  0000 C CNN
	1    9100 1750
	0    -1   -1   0   
$EndComp
Text GLabel 9550 2550 0    39   Input ~ 0
I34
Text GLabel 9550 2650 0    39   Input ~ 0
I39
Text GLabel 9550 2750 0    39   Input ~ 0
I36
Text GLabel 9550 2850 0    39   Input ~ 0
EN
$Comp
L GhostSensorboard-rescue:GND-RESCUE-GhostSensorboard #PWR025
U 1 1 594327BE
P 10600 2500
F 0 "#PWR025" H 10600 2250 50  0001 C CNN
F 1 "GND" H 10600 2350 50  0000 C CNN
F 2 "" H 10600 2500 50  0000 C CNN
F 3 "" H 10600 2500 50  0000 C CNN
	1    10600 2500
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:VBUS-RESCUE-GhostSensorboard #PWR026
U 1 1 594328DF
P 10850 1350
F 0 "#PWR026" H 10850 1200 50  0001 C CNN
F 1 "VBUS" H 10865 1523 50  0000 C CNN
F 2 "" H 10850 1350 50  0001 C CNN
F 3 "" H 10850 1350 50  0001 C CNN
	1    10850 1350
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:PWR_FLAG-RESCUE-GhostSensorboard #FLG027
U 1 1 59432CA3
P 10600 1450
F 0 "#FLG027" H 10600 1525 50  0001 C CNN
F 1 "PWR_FLAG" H 10600 1624 50  0000 C CNN
F 2 "" H 10600 1450 50  0001 C CNN
F 3 "" H 10600 1450 50  0001 C CNN
	1    10600 1450
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:LED-RESCUE-GhostSensorboard D2
U 1 1 594382C7
P 4700 3400
F 0 "D2" H 4700 3500 50  0000 C CNN
F 1 "LED" H 4700 3300 50  0000 C CNN
F 2 "LEDs:LED_0603" H 4700 3400 50  0001 C CNN
F 3 "" H 4700 3400 50  0000 C CNN
	1    4700 3400
	-1   0    0    1   
$EndComp
$Comp
L GhostSensorboard-rescue:R-RESCUE-GhostSensorboard R16
U 1 1 594382CD
P 4250 3400
F 0 "R16" V 4330 3400 50  0000 C CNN
F 1 "330" V 4250 3400 50  0000 C CNN
F 2 "Resistors_SMD:R_0402" V 4180 3400 50  0001 C CNN
F 3 "" H 4250 3400 50  0000 C CNN
	1    4250 3400
	0    1    1    0   
$EndComp
Text GLabel 5000 3400 2    39   Input ~ 0
LED
$Comp
L GhostSensorboard-rescue:+3V3-RESCUE-GhostSensorboard #PWR028
U 1 1 594382D7
P 3850 3400
F 0 "#PWR028" H 3850 3250 50  0001 C CNN
F 1 "+3V3" H 3850 3540 50  0000 C CNN
F 2 "" H 3850 3400 50  0000 C CNN
F 3 "" H 3850 3400 50  0000 C CNN
	1    3850 3400
	0    -1   -1   0   
$EndComp
$Comp
L GhostSensorboard-rescue:LED-RESCUE-GhostSensorboard D3
U 1 1 59438571
P 4700 3700
F 0 "D3" H 4700 3800 50  0000 C CNN
F 1 "LED" H 4700 3600 50  0000 C CNN
F 2 "LEDs:LED_0603" H 4700 3700 50  0001 C CNN
F 3 "" H 4700 3700 50  0000 C CNN
	1    4700 3700
	-1   0    0    1   
$EndComp
$Comp
L GhostSensorboard-rescue:R-RESCUE-GhostSensorboard R17
U 1 1 59438577
P 4250 3700
F 0 "R17" V 4330 3700 50  0000 C CNN
F 1 "330" V 4250 3700 50  0000 C CNN
F 2 "Resistors_SMD:R_0402" V 4180 3700 50  0001 C CNN
F 3 "" H 4250 3700 50  0000 C CNN
	1    4250 3700
	0    1    1    0   
$EndComp
Text GLabel 5000 3700 2    39   Input ~ 0
LED
$Comp
L GhostSensorboard-rescue:+3V3-RESCUE-GhostSensorboard #PWR029
U 1 1 59438581
P 3850 3700
F 0 "#PWR029" H 3850 3550 50  0001 C CNN
F 1 "+3V3" H 3850 3840 50  0000 C CNN
F 2 "" H 3850 3700 50  0000 C CNN
F 3 "" H 3850 3700 50  0000 C CNN
	1    3850 3700
	0    -1   -1   0   
$EndComp
$Comp
L GhostSensorboard-rescue:LED-RESCUE-GhostSensorboard D4
U 1 1 59438587
P 4700 4000
F 0 "D4" H 4700 4100 50  0000 C CNN
F 1 "LED" H 4700 3900 50  0000 C CNN
F 2 "LEDs:LED_0603" H 4700 4000 50  0001 C CNN
F 3 "" H 4700 4000 50  0000 C CNN
	1    4700 4000
	-1   0    0    1   
$EndComp
$Comp
L GhostSensorboard-rescue:R-RESCUE-GhostSensorboard R18
U 1 1 5943858D
P 4250 4000
F 0 "R18" V 4330 4000 50  0000 C CNN
F 1 "330" V 4250 4000 50  0000 C CNN
F 2 "Resistors_SMD:R_0402" V 4180 4000 50  0001 C CNN
F 3 "" H 4250 4000 50  0000 C CNN
	1    4250 4000
	0    1    1    0   
$EndComp
Text GLabel 5000 4000 2    39   Input ~ 0
LED
$Comp
L GhostSensorboard-rescue:+3V3-RESCUE-GhostSensorboard #PWR030
U 1 1 59438597
P 3850 4000
F 0 "#PWR030" H 3850 3850 50  0001 C CNN
F 1 "+3V3" H 3850 4140 50  0000 C CNN
F 2 "" H 3850 4000 50  0000 C CNN
F 3 "" H 3850 4000 50  0000 C CNN
	1    3850 4000
	0    -1   -1   0   
$EndComp
$Comp
L GhostSensorboard-rescue:+5V-RESCUE-GhostSensorboard #PWR031
U 1 1 5943A27A
P 10650 3500
F 0 "#PWR031" H 10650 3350 50  0001 C CNN
F 1 "+5V" H 10650 3640 50  0000 C CNN
F 2 "" H 10650 3500 50  0000 C CNN
F 3 "" H 10650 3500 50  0000 C CNN
	1    10650 3500
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:+BATT-RESCUE-GhostSensorboard #PWR032
U 1 1 5943B11C
P 9650 3500
F 0 "#PWR032" H 9650 3350 50  0001 C CNN
F 1 "+BATT" V 9665 3627 50  0000 L CNN
F 2 "" H 9650 3500 50  0001 C CNN
F 3 "" H 9650 3500 50  0001 C CNN
	1    9650 3500
	0    -1   -1   0   
$EndComp
Text GLabel 9650 3600 0    39   Input ~ 0
ENABLE5V
Text GLabel 7850 2250 2    39   Input ~ 0
ENABLE5V
$Comp
L GhostSensorboard-rescue:C_Small-RESCUE-GhostSensorboard C3
U 1 1 5943F197
P 10500 3700
F 0 "C3" H 10592 3746 50  0000 L CNN
F 1 "2.2uF-10uF" H 10500 3600 50  0000 L CNN
F 2 "Capacitors_SMD:C_0402" H 10500 3700 50  0001 C CNN
F 3 "" H 10500 3700 50  0001 C CNN
	1    10500 3700
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:GND-RESCUE-GhostSensorboard #PWR033
U 1 1 5943F4BE
P 10050 4000
F 0 "#PWR033" H 10050 3750 50  0001 C CNN
F 1 "GND" H 10050 3850 50  0000 C CNN
F 2 "" H 10050 4000 50  0000 C CNN
F 3 "" H 10050 4000 50  0000 C CNN
	1    10050 4000
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:SW_SPDT-RESCUE-GhostSensorboard SW2
U 1 1 59440DB8
P 4200 5300
F 0 "SW2" H 4200 5585 50  0000 C CNN
F 1 "SW_SPDT" H 4200 5494 50  0000 C CNN
F 2 "NorBotKiCadFootprints:MFP106D" H 4200 5300 50  0001 C CNN
F 3 "" H 4200 5300 50  0001 C CNN
	1    4200 5300
	1    0    0    -1  
$EndComp
Text Notes 3800 4900 0    60   ~ 0
Power ON/OFF\nMFP106D, max 6A\nFarnell no: 807-527
NoConn ~ 4400 5400
$Comp
L GhostSensorboard-rescue:Battery_Cell-RESCUE-GhostSensorboard BT1
U 1 1 59441704
P 3550 5550
F 0 "BT1" H 3668 5646 50  0000 L CNN
F 1 "Battery_Cell" H 3668 5555 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" V 3550 5610 50  0001 C CNN
F 3 "" V 3550 5610 50  0001 C CNN
	1    3550 5550
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:GND-RESCUE-GhostSensorboard #PWR034
U 1 1 59441FE6
P 3550 5800
F 0 "#PWR034" H 3550 5550 50  0001 C CNN
F 1 "GND" H 3555 5627 50  0000 C CNN
F 2 "" H 3550 5800 50  0001 C CNN
F 3 "" H 3550 5800 50  0001 C CNN
	1    3550 5800
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:+BATT-RESCUE-GhostSensorboard #PWR035
U 1 1 59443211
P 4800 5200
F 0 "#PWR035" H 4800 5050 50  0001 C CNN
F 1 "+BATT" V 4815 5328 50  0000 L CNN
F 2 "" H 4800 5200 50  0001 C CNN
F 3 "" H 4800 5200 50  0001 C CNN
	1    4800 5200
	0    1    1    0   
$EndComp
$Comp
L NorBot:NeoPixelNano U6
U 1 1 59452459
P 5100 2300
F 0 "U6" H 5100 2647 60  0000 C CNN
F 1 "NeoPixelNano" H 5100 2541 60  0000 C CNN
F 2 "NorBotKiCadFootprints:NeoPixelNano" H 5100 2300 60  0001 C CNN
F 3 "" H 5100 2300 60  0001 C CNN
	1    5100 2300
	1    0    0    -1  
$EndComp
$Comp
L NorBot:NeoPixelNano U9
U 1 1 59452694
P 6000 2300
F 0 "U9" H 6000 2647 60  0000 C CNN
F 1 "NeoPixelNano" H 6000 2541 60  0000 C CNN
F 2 "NorBotKiCadFootprints:NeoPixelNano" H 6000 2300 60  0001 C CNN
F 3 "" H 6000 2300 60  0001 C CNN
	1    6000 2300
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:+5V-RESCUE-GhostSensorboard #PWR036
U 1 1 59455BAA
P 4600 2050
F 0 "#PWR036" H 4600 1900 50  0001 C CNN
F 1 "+5V" H 4600 2190 50  0000 C CNN
F 2 "" H 4600 2050 50  0000 C CNN
F 3 "" H 4600 2050 50  0000 C CNN
	1    4600 2050
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:+5V-RESCUE-GhostSensorboard #PWR037
U 1 1 59455F9D
P 5600 2050
F 0 "#PWR037" H 5600 1900 50  0001 C CNN
F 1 "+5V" H 5600 2190 50  0000 C CNN
F 2 "" H 5600 2050 50  0000 C CNN
F 3 "" H 5600 2050 50  0000 C CNN
	1    5600 2050
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:C_Small-RESCUE-GhostSensorboard C4
U 1 1 5945628D
P 4250 2300
F 0 "C4" H 4050 2200 50  0000 L CNN
F 1 "0.1uF" H 3950 2300 50  0000 L CNN
F 2 "Capacitors_SMD:C_0402" H 4250 2300 50  0001 C CNN
F 3 "" H 4250 2300 50  0001 C CNN
	1    4250 2300
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:GND-RESCUE-GhostSensorboard #PWR038
U 1 1 594568A6
P 5500 2450
F 0 "#PWR038" H 5500 2200 50  0001 C CNN
F 1 "GND" H 5500 2300 50  0000 C CNN
F 2 "" H 5500 2450 50  0000 C CNN
F 3 "" H 5500 2450 50  0000 C CNN
	1    5500 2450
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:GND-RESCUE-GhostSensorboard #PWR039
U 1 1 59456B48
P 4250 2450
F 0 "#PWR039" H 4250 2200 50  0001 C CNN
F 1 "GND" H 4250 2300 50  0000 C CNN
F 2 "" H 4250 2450 50  0000 C CNN
F 3 "" H 4250 2450 50  0000 C CNN
	1    4250 2450
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:GND-RESCUE-GhostSensorboard #PWR040
U 1 1 59456BB9
P 6400 2450
F 0 "#PWR040" H 6400 2200 50  0001 C CNN
F 1 "GND" H 6400 2300 50  0000 C CNN
F 2 "" H 6400 2450 50  0000 C CNN
F 3 "" H 6400 2450 50  0000 C CNN
	1    6400 2450
	1    0    0    -1  
$EndComp
NoConn ~ 6350 2200
Text GLabel 7850 1850 2    39   Input ~ 0
NEOPIXEL
Text GLabel 4700 2350 0    39   Input ~ 0
NEOPIXEL
Text Notes 4600 1800 0    60   ~ 0
NeoPixel Nano RGB LEDs\nAdafruit prod no: 3484
$Comp
L GhostSensorboard-rescue:MIC5219-5.0-RESCUE-GhostSensorboard U14
U 1 1 5945A2A2
P 10050 3600
F 0 "U14" H 10050 3942 50  0000 C CNN
F 1 "MIC5219-5.0" H 10050 3851 50  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23-5" H 10050 3925 50  0001 C CNN
F 3 "" H 10050 3600 50  0001 C CNN
	1    10050 3600
	1    0    0    -1  
$EndComp
NoConn ~ 10350 3600
Text Notes 9600 3200 0    60   ~ 0
MIC5219 5V regulator\nFarnell no: ???-????
Text GLabel 1850 900  2    39   Input ~ 0
SDA
NoConn ~ 7650 1650
NoConn ~ 7650 1750
$Comp
L NorBot:TSOP752-TSOP754 U4
U 1 1 5946B0A1
P 4900 7100
F 0 "U4" H 5150 6750 60  0000 C CNN
F 1 "TSOP752-TSOP754" H 4925 7381 60  0000 C CNN
F 2 "NorBotKiCadFootprints:TSOP75x" H 4850 7250 60  0001 C CNN
F 3 "" H 4850 7250 60  0001 C CNN
	1    4900 7100
	1    0    0    -1  
$EndComp
$Comp
L GhostSensorboard-rescue:PWR_FLAG-RESCUE-GhostSensorboard #FLG041
U 1 1 594B26A8
P 9150 1550
F 0 "#FLG041" H 9150 1645 50  0001 C CNN
F 1 "PWR_FLAG" H 9150 1730 50  0000 C CNN
F 2 "" H 9150 1550 50  0000 C CNN
F 3 "" H 9150 1550 50  0000 C CNN
	1    9150 1550
	1    0    0    -1  
$EndComp
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
Wire Wire Line
	1250 6700 1100 6700
Wire Wire Line
	1100 6800 1750 6800
Wire Wire Line
	1100 6900 1150 6900
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
Wire Wire Line
	6150 3500 6300 3500
Wire Wire Line
	7000 3500 7000 3700
Wire Wire Line
	3500 6950 3500 7000
Wire Wire Line
	3900 7000 4050 7000
Connection ~ 4050 7000
Wire Wire Line
	5550 7000 5400 7000
Wire Wire Line
	3500 7000 3600 7000
Wire Wire Line
	5000 3100 4850 3100
Wire Wire Line
	4550 3100 4400 3100
Wire Wire Line
	4100 3100 3850 3100
Wire Wire Line
	6450 3700 6300 3700
Wire Wire Line
	6300 3700 6300 3500
Connection ~ 6300 3500
Wire Wire Line
	7000 3700 6750 3700
Wire Wire Line
	7000 3500 6750 3500
Wire Wire Line
	5850 3500 5750 3500
Wire Wire Line
	4450 7200 4450 7300
Connection ~ 4450 7300
Wire Wire Line
	4050 7300 4450 7300
Wire Wire Line
	1150 7000 1150 6900
Connection ~ 1150 6900
Wire Wire Line
	4050 6950 4050 7000
Wire Wire Line
	1850 900  1650 900 
Wire Wire Line
	1650 1050 1850 1050
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
Wire Wire Line
	7850 2750 7650 2750
Wire Notes Line
	8900 4200 7150 4200
Wire Notes Line
	7150 4200 7150 550 
Wire Wire Line
	7850 2550 7650 2550
Wire Wire Line
	7650 1950 7850 1950
Wire Wire Line
	7850 2050 7650 2050
Wire Wire Line
	7650 2150 7850 2150
Wire Wire Line
	7850 2850 7650 2850
Wire Wire Line
	7650 2650 7850 2650
Wire Wire Line
	7650 2950 7850 2950
Wire Wire Line
	7850 2350 7650 2350
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
	9550 1550 9700 1550
Wire Wire Line
	9700 1650 9550 1650
Wire Wire Line
	9100 1750 9150 1750
Wire Wire Line
	10450 1550 10600 1550
Wire Wire Line
	10600 1550 10600 1450
Wire Wire Line
	10850 1550 10850 1350
Connection ~ 10600 1550
Wire Wire Line
	10550 1650 10450 1650
Wire Wire Line
	10450 1750 10550 1750
Wire Wire Line
	10550 1850 10450 1850
Wire Wire Line
	10450 1950 10550 1950
Wire Wire Line
	10450 2050 10550 2050
Wire Wire Line
	10550 2150 10450 2150
Wire Wire Line
	10450 2250 10550 2250
Wire Wire Line
	10550 2350 10450 2350
Wire Wire Line
	10450 2450 10600 2450
Wire Wire Line
	10600 2450 10600 2500
Wire Wire Line
	9700 2850 9550 2850
Wire Wire Line
	9550 2750 9700 2750
Wire Wire Line
	9700 2650 9550 2650
Wire Wire Line
	9550 2550 9700 2550
Wire Wire Line
	9700 2450 9550 2450
Wire Wire Line
	9550 2350 9700 2350
Wire Wire Line
	9700 2250 9550 2250
Wire Wire Line
	9550 2150 9700 2150
Wire Wire Line
	9700 2050 9550 2050
Wire Wire Line
	9550 1950 9700 1950
Wire Wire Line
	9700 1850 9550 1850
Wire Wire Line
	5000 3400 4850 3400
Wire Wire Line
	4550 3400 4400 3400
Wire Wire Line
	4100 3400 3850 3400
Wire Wire Line
	5000 3700 4850 3700
Wire Wire Line
	4550 3700 4400 3700
Wire Wire Line
	4100 3700 3850 3700
Wire Wire Line
	5000 4000 4850 4000
Wire Wire Line
	4550 4000 4400 4000
Wire Wire Line
	4100 4000 3850 4000
Wire Wire Line
	7650 2250 7850 2250
Wire Wire Line
	9650 3500 9750 3500
Wire Wire Line
	10350 3500 10500 3500
Wire Wire Line
	10050 3900 10050 3950
Wire Wire Line
	10500 3600 10500 3500
Connection ~ 10500 3500
Wire Wire Line
	10500 3800 10500 3950
Wire Wire Line
	10500 3950 10050 3950
Connection ~ 10050 3950
Wire Wire Line
	3550 5350 3550 5300
Wire Wire Line
	3550 5300 4000 5300
Wire Wire Line
	3550 5800 3550 5650
Wire Wire Line
	4400 5200 4600 5200
Wire Notes Line
	5300 4050 5300 2800
Wire Wire Line
	4250 2200 4600 2200
Wire Wire Line
	4600 2200 4600 2050
Connection ~ 4600 2200
Wire Wire Line
	4250 2450 4250 2400
Wire Wire Line
	5450 2200 5550 2200
Wire Wire Line
	5550 2200 5550 2350
Wire Wire Line
	5550 2350 5650 2350
Wire Wire Line
	5500 2450 5500 2350
Wire Wire Line
	5500 2350 5450 2350
Wire Wire Line
	5650 2200 5600 2200
Wire Wire Line
	5600 2200 5600 2050
Wire Wire Line
	6350 2350 6400 2350
Wire Wire Line
	6400 2350 6400 2450
Wire Wire Line
	7850 1850 7650 1850
Wire Wire Line
	4750 2350 4700 2350
Wire Wire Line
	9750 3600 9650 3600
Wire Wire Line
	9150 1550 9150 1750
Connection ~ 9150 1750
$Comp
L GhostSensorboard-rescue:PWR_FLAG-RESCUE-GhostSensorboard #FLG042
U 1 1 594B371F
P 4600 5150
F 0 "#FLG042" H 4600 5245 50  0001 C CNN
F 1 "PWR_FLAG" H 4600 5330 50  0000 C CNN
F 2 "" H 4600 5150 50  0000 C CNN
F 3 "" H 4600 5150 50  0000 C CNN
	1    4600 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 5150 4600 5200
Connection ~ 4600 5200
Text GLabel 7600 3050 0    39   Input ~ 0
I34
Text GLabel 7600 3150 0    39   Input ~ 0
I36
Text GLabel 7600 3250 0    39   Input ~ 0
I39
Text GLabel 7600 3350 0    39   Input ~ 0
EN
NoConn ~ 7600 3050
NoConn ~ 7600 3150
NoConn ~ 7600 3250
NoConn ~ 7600 3350
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
	6300 3500 6350 3500
Wire Wire Line
	4450 7300 4450 7400
Wire Wire Line
	1150 6900 1250 6900
Wire Wire Line
	7800 5500 7900 5500
Wire Wire Line
	10600 1550 10850 1550
Wire Wire Line
	10500 3500 10650 3500
Wire Wire Line
	10050 3950 10050 4000
Wire Wire Line
	4600 2200 4750 2200
Wire Wire Line
	9150 1750 9700 1750
Wire Wire Line
	4600 5200 4800 5200
$EndSCHEMATC
