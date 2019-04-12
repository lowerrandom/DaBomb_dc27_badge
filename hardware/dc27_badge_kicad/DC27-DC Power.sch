EESchema Schematic File Version 4
LIBS:DC27-badge-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 8
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 950  850  0    79   ~ 16
LiPo Charging and USB Power\n
Text Notes 7350 7500 0    50   ~ 0
DC 27 Badge - Team Ides - John Adams / Bill Paul
$Comp
L Device:Battery BT401
U 1 1 5C4652F9
P 5500 3500
F 0 "BT401" H 5600 3500 50  0000 L CNN
F 1 "Battery" H 5600 3400 50  0000 L CNN
F 2 "Connector_JST:JST_PH_S2B-PH-SM4-TB_1x02-1MP_P2.00mm_Horizontal" V 5500 3560 50  0001 C CNN
F 3 "~" V 5500 3560 50  0001 C CNN
	1    5500 3500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0408
U 1 1 5C4653C6
P 5500 4550
F 0 "#PWR0408" H 5500 4300 50  0001 C CNN
F 1 "GND" H 5505 4377 50  0000 C CNN
F 2 "" H 5500 4550 50  0001 C CNN
F 3 "" H 5500 4550 50  0001 C CNN
	1    5500 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 3150 5500 3300
$Comp
L Switch:SW_SPDT SW401
U 1 1 5C4727E9
P 5950 3250
F 0 "SW401" H 5950 2925 50  0000 C CNN
F 1 "POWER ON" H 5950 3016 50  0000 C CNN
F 2 "Button_Switch_SMD:SW_SPDT_PCM12" H 5950 3250 50  0001 C CNN
F 3 "" H 5950 3250 50  0001 C CNN
	1    5950 3250
	-1   0    0    1   
$EndComp
Wire Wire Line
	5500 3150 5750 3150
Connection ~ 5500 3150
NoConn ~ 5750 3350
$Comp
L Regulator_Linear:LM1117-3.3 U402
U 1 1 5C473022
P 8600 3250
F 0 "U402" H 8600 3492 50  0000 C CNN
F 1 "LM1117-3.3" H 8600 3401 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223" H 8600 3250 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm1117.pdf" H 8600 3250 50  0001 C CNN
	1    8600 3250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C401
U 1 1 5C473125
P 7550 3550
F 0 "C401" H 7665 3596 50  0000 L CNN
F 1 "10uF" H 7665 3505 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 7588 3400 50  0001 C CNN
F 3 "~" H 7550 3550 50  0001 C CNN
	1    7550 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:C C402
U 1 1 5C47316D
P 7900 3550
F 0 "C402" H 8015 3596 50  0000 L CNN
F 1 "10uF" H 8015 3505 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 7938 3400 50  0001 C CNN
F 3 "~" H 7900 3550 50  0001 C CNN
	1    7900 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:C C403
U 1 1 5C473192
P 9200 3550
F 0 "C403" H 9315 3596 50  0000 L CNN
F 1 "10uF" H 9315 3505 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 9238 3400 50  0001 C CNN
F 3 "~" H 9200 3550 50  0001 C CNN
	1    9200 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:C C404
U 1 1 5C4731CA
P 9550 3550
F 0 "C404" H 9665 3596 50  0000 L CNN
F 1 "10uF" H 9665 3505 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 9588 3400 50  0001 C CNN
F 3 "~" H 9550 3550 50  0001 C CNN
	1    9550 3550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0403
U 1 1 5C473246
P 8600 3900
F 0 "#PWR0403" H 8600 3650 50  0001 C CNN
F 1 "GND" H 8605 3727 50  0000 C CNN
F 2 "" H 8600 3900 50  0001 C CNN
F 3 "" H 8600 3900 50  0001 C CNN
	1    8600 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 3700 7550 3800
Wire Wire Line
	7550 3800 7900 3800
Wire Wire Line
	9550 3800 9550 3700
Wire Wire Line
	9200 3700 9200 3800
Connection ~ 9200 3800
Wire Wire Line
	9200 3800 9550 3800
Connection ~ 8600 3800
Wire Wire Line
	8600 3800 9200 3800
Wire Wire Line
	8600 3800 8600 3900
Wire Wire Line
	7900 3700 7900 3800
Connection ~ 7900 3800
Wire Wire Line
	7900 3800 8600 3800
Wire Wire Line
	8600 3550 8600 3800
Wire Wire Line
	8300 3250 7900 3250
Wire Wire Line
	7550 3250 7550 3400
Wire Wire Line
	7900 3400 7900 3250
Connection ~ 7900 3250
Wire Wire Line
	7900 3250 7550 3250
Wire Wire Line
	9200 3400 9200 3250
Wire Wire Line
	9200 3250 8900 3250
Wire Wire Line
	9550 3400 9550 3250
Wire Wire Line
	9550 3250 9200 3250
Connection ~ 9200 3250
Connection ~ 7550 3250
$Comp
L DC27-badge-cache:+3.3V #PWR0402
U 1 1 5C475E90
P 9950 3150
F 0 "#PWR0402" H 9950 3000 50  0001 C CNN
F 1 "+3.3V" H 9965 3323 50  0000 C CNN
F 2 "" H 9950 3150 50  0001 C CNN
F 3 "" H 9950 3150 50  0001 C CNN
	1    9950 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	9550 3250 9750 3250
Wire Wire Line
	9950 3250 9950 3150
Connection ~ 9550 3250
Text Notes 8050 2900 0    50   ~ 0
3.3v 800mA LDO\nPackage SOT-223\nMax current 1500mA, typ 1200mA
Text GLabel 1500 3150 0    50   Input ~ 0
VBUS
$Comp
L Device:C C405
U 1 1 5C47B6A1
P 2950 4000
F 0 "C405" H 2650 4050 50  0000 L CNN
F 1 "10uF" H 2650 3950 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 2988 3850 50  0001 C CNN
F 3 "~" H 2950 4000 50  0001 C CNN
	1    2950 4000
	1    0    0    -1  
$EndComp
Text Notes 1550 3000 0    50   ~ 0
VBUS is from USB\n
$Comp
L Device:R R403
U 1 1 5C47DC16
P 4050 4300
F 0 "R403" H 4120 4346 50  0000 L CNN
F 1 "2.0k" H 4120 4255 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3980 4300 50  0001 C CNN
F 3 "~" H 4050 4300 50  0001 C CNN
	1    4050 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 3950 4050 4150
Wire Wire Line
	2950 3150 2950 3250
$Comp
L power:GND #PWR0405
U 1 1 5C47EFA4
P 4250 4700
F 0 "#PWR0405" H 4250 4450 50  0001 C CNN
F 1 "GND" H 4255 4527 50  0000 C CNN
F 2 "" H 4250 4700 50  0001 C CNN
F 3 "" H 4250 4700 50  0001 C CNN
	1    4250 4700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0404
U 1 1 5C47EFC9
P 2950 4300
F 0 "#PWR0404" H 2950 4050 50  0001 C CNN
F 1 "GND" H 2955 4127 50  0000 C CNN
F 2 "" H 2950 4300 50  0001 C CNN
F 3 "" H 2950 4300 50  0001 C CNN
	1    2950 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 4150 2950 4300
Wire Wire Line
	4050 4600 4050 4450
$Comp
L power:GND #PWR0406
U 1 1 5C483235
P 3250 4300
F 0 "#PWR0406" H 3250 4050 50  0001 C CNN
F 1 "GND" H 3255 4127 50  0000 C CNN
F 2 "" H 3250 4300 50  0001 C CNN
F 3 "" H 3250 4300 50  0001 C CNN
	1    3250 4300
	1    0    0    -1  
$EndComp
$Comp
L Device:C C406
U 1 1 5C48403A
P 5000 3700
F 0 "C406" H 5100 3850 50  0000 L CNN
F 1 "10uF" H 5100 3750 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5038 3550 50  0001 C CNN
F 3 "~" H 5000 3700 50  0001 C CNN
	1    5000 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 3550 5000 3150
$Comp
L power:GND #PWR0407
U 1 1 5C484C61
P 5000 4000
F 0 "#PWR0407" H 5000 3750 50  0001 C CNN
F 1 "GND" H 5005 3827 50  0000 C CNN
F 2 "" H 5000 4000 50  0001 C CNN
F 3 "" H 5000 4000 50  0001 C CNN
	1    5000 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 3850 5000 4000
Text Notes 5600 3850 0    50   ~ 0
JST-PH MALE connector here \nPIN 1 (LEFT) HOT \n
$Comp
L Connector:TestPoint TP402
U 1 1 5C48922D
P 9750 2650
F 0 "TP402" H 9808 2770 50  0000 L CNN
F 1 "3.3V TEST" H 9808 2679 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D2.0mm" H 9950 2650 50  0001 C CNN
F 3 "~" H 9950 2650 50  0001 C CNN
	1    9750 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	9750 2650 9750 3250
$Comp
L Connector:TestPoint TP401
U 1 1 5C48A027
P 5300 2600
F 0 "TP401" H 5358 2720 50  0000 L CNN
F 1 "VBATT" H 5358 2629 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D2.0mm" H 5500 2600 50  0001 C CNN
F 3 "~" H 5500 2600 50  0001 C CNN
	1    5300 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 2600 5300 3150
Connection ~ 5300 3150
Wire Wire Line
	5300 3150 5500 3150
$Comp
L power:GND #PWR0401
U 1 1 5C48BBBD
P 10400 2800
F 0 "#PWR0401" H 10400 2550 50  0001 C CNN
F 1 "GND" H 10405 2627 50  0000 C CNN
F 2 "" H 10400 2800 50  0001 C CNN
F 3 "" H 10400 2800 50  0001 C CNN
	1    10400 2800
	1    0    0    -1  
$EndComp
$Comp
L Connector:TestPoint TP403
U 1 1 5C48BC78
P 10400 2650
F 0 "TP403" H 10458 2770 50  0000 L CNN
F 1 "GND" H 10458 2679 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D2.0mm" H 10600 2650 50  0001 C CNN
F 3 "~" H 10600 2650 50  0001 C CNN
	1    10400 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	10400 2650 10400 2800
Connection ~ 9750 3250
Wire Wire Line
	9750 3250 9950 3250
$Comp
L Device:LED D402
U 1 1 5C48E99E
P 2700 2100
F 0 "D402" V 2650 1950 50  0000 R CNN
F 1 "CHARGING (ORANGE)" V 2550 1950 50  0000 R CNN
F 2 "Diode_SMD:D_0603_1608Metric" H 2700 2100 50  0001 C CNN
F 3 "~" H 2700 2100 50  0001 C CNN
	1    2700 2100
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D401
U 1 1 5C48E9FA
P 2350 2100
F 0 "D401" V 2300 2350 50  0000 L CNN
F 1 "CHARGED" V 2200 2200 50  0000 L CNN
F 2 "Diode_SMD:D_0603_1608Metric" H 2350 2100 50  0001 C CNN
F 3 "~" H 2350 2100 50  0001 C CNN
	1    2350 2100
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R402
U 1 1 5C493FF5
P 2700 2650
F 0 "R402" H 2770 2696 50  0000 L CNN
F 1 "1K" H 2770 2605 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2630 2650 50  0001 C CNN
F 3 "~" H 2700 2650 50  0001 C CNN
	1    2700 2650
	1    0    0    -1  
$EndComp
$Comp
L Device:R R401
U 1 1 5C494042
P 2350 2650
F 0 "R401" H 2420 2696 50  0000 L CNN
F 1 "1K" H 2420 2605 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2280 2650 50  0001 C CNN
F 3 "~" H 2350 2650 50  0001 C CNN
	1    2350 2650
	1    0    0    -1  
$EndComp
Text Notes 3600 2650 0    50   ~ 0
1A Lipo Charger
$Comp
L power:PWR_FLAG #FLG0401
U 1 1 5C4C9793
P 6800 3000
F 0 "#FLG0401" H 6800 3075 50  0001 C CNN
F 1 "PWR_FLAG" H 6800 3174 50  0000 C CNN
F 2 "" H 6800 3000 50  0001 C CNN
F 3 "~" H 6800 3000 50  0001 C CNN
	1    6800 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 3000 6800 3250
Wire Wire Line
	1500 3150 2950 3150
Wire Wire Line
	5500 3700 5500 4550
$Comp
L DC27-badge:MCP73833 U401
U 1 1 5CB707A0
P 3850 3450
AR Path="/5CB707A0" Ref="U401"  Part="1" 
AR Path="/5BA3F217/5CB707A0" Ref="U401"  Part="1" 
F 0 "U401" H 3875 3975 50  0000 C CNN
F 1 "MCP73833" H 3875 3884 50  0000 C CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 3900 2850 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22005b.pdf" H 3800 3500 50  0001 C CNN
	1    3850 3450
	1    0    0    -1  
$EndComp
Connection ~ 2950 3150
Connection ~ 2950 3250
Wire Wire Line
	2950 3250 2950 3850
Wire Wire Line
	2950 3250 3450 3250
Wire Wire Line
	3450 3800 3250 3800
Wire Wire Line
	3250 3800 3250 4300
Wire Wire Line
	4300 3150 4500 3150
Wire Wire Line
	4300 3250 4500 3250
Wire Wire Line
	4500 3250 4500 3150
Connection ~ 4500 3150
Wire Wire Line
	2700 2250 2700 2500
Wire Wire Line
	2350 2250 2350 2500
$Comp
L Device:LED D403
U 1 1 5CBB2269
P 4700 2100
F 0 "D403" V 4738 1983 50  0000 R CNN
F 1 "PWR GOOD" V 4647 1983 50  0000 R CNN
F 2 "Diode_SMD:D_0603_1608Metric" H 4700 2100 50  0001 C CNN
F 3 "~" H 4700 2100 50  0001 C CNN
	1    4700 2100
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R405
U 1 1 5CBB2273
P 4700 2650
F 0 "R405" H 4770 2696 50  0000 L CNN
F 1 "1K" H 4770 2605 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4630 2650 50  0001 C CNN
F 3 "~" H 4700 2650 50  0001 C CNN
	1    4700 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 2250 4700 2500
Wire Wire Line
	4300 3650 4700 3650
Wire Wire Line
	4700 2800 4700 3650
Text GLabel 2350 1750 1    50   Input ~ 0
VBUS
Text GLabel 2700 1750 1    50   Input ~ 0
VBUS
Text GLabel 4700 1750 1    50   Input ~ 0
VBUS
Wire Wire Line
	4700 1750 4700 1950
Wire Wire Line
	2700 1950 2700 1750
Wire Wire Line
	2350 1750 2350 1950
Wire Wire Line
	2700 3400 3450 3400
Wire Wire Line
	2700 2800 2700 3400
Wire Wire Line
	3450 3500 2350 3500
Wire Wire Line
	2350 2800 2350 3500
Text Notes 3200 5450 0    50   ~ 0
10K = 100mA\n5.0K = 200mA\n2.0K = 500mA\n1.0K = 1000mA\n\nREMOVE R404 or R403 TO SET CHARGER TO 500mA. \nWITH BOTH RESISTORS CHARGING IS 1000mA
$Comp
L Device:R R406
U 1 1 5CBBCF12
P 4800 4600
F 0 "R406" H 4870 4646 50  0000 L CNN
F 1 "10K" H 4870 4555 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4730 4600 50  0001 C CNN
F 3 "~" H 4800 4600 50  0001 C CNN
	1    4800 4600
	1    0    0    -1  
$EndComp
Connection ~ 5000 3150
Wire Wire Line
	5000 3150 5300 3150
Wire Wire Line
	4500 3150 5000 3150
Wire Wire Line
	4300 3450 4800 3450
Wire Wire Line
	4800 3450 4800 4450
$Comp
L power:GND #PWR0115
U 1 1 5CBC4D3E
P 4800 4900
F 0 "#PWR0115" H 4800 4650 50  0001 C CNN
F 1 "GND" H 4805 4727 50  0000 C CNN
F 2 "" H 4800 4900 50  0001 C CNN
F 3 "" H 4800 4900 50  0001 C CNN
	1    4800 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 4750 4800 4900
Wire Wire Line
	4050 4600 4250 4600
Wire Wire Line
	4250 4600 4250 4700
$Comp
L Device:R R404
U 1 1 5CBF21F6
P 4450 4300
F 0 "R404" H 4520 4346 50  0000 L CNN
F 1 "2.0k" H 4520 4255 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4380 4300 50  0001 C CNN
F 3 "~" H 4450 4300 50  0001 C CNN
	1    4450 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 3800 4450 3950
Wire Wire Line
	4300 3800 4450 3800
Wire Wire Line
	4450 4450 4450 4600
Wire Wire Line
	4450 4600 4250 4600
Connection ~ 4250 4600
Wire Wire Line
	4050 3950 4450 3950
Connection ~ 4450 3950
Wire Wire Line
	4450 3950 4450 4150
Wire Wire Line
	6150 3250 6800 3250
Connection ~ 6800 3250
Wire Wire Line
	6800 3250 7550 3250
Wire Wire Line
	2950 3150 3450 3150
$EndSCHEMATC
