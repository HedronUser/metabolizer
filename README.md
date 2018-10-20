# metabolizer
esp device node - communicates to Blynk and reads sensors and actuates pumps

# Hardware
LoLin ESP8266 device
Max 6675 Thermocouple module
breadboard leads
iOS or android mobile device

# Software
Blynk App (on mobile device)


# Our Goals

Goal 1: Read value from K sensor and display on Blink dashboard - 4 water temp or Tk sensors
	- setup local blink server on raspberry pi 
	- setup local wifi network to br

Goal 2: When the board goes above 80 degrees  fahrenheit the relay is switched on for the pump peristaltic

Goal 3: Precisely control needle valves - gate with stepper or servo

Goal 4: Pressure Reading

Goal 5: Voltage of battery bank - 12V

Goal 6: Power reading 

# Data we want to collect:

Measure weight of keg

Measure dry weight of biomass

Measure power produced by generator

Measure dry post-combust weight
heat and temperature of water condensed
amount of water condensed

# Project Log

09-16-2018 Metabolizer

11:20am start working 

12:57pm finished serial input

3:44pm working version of Blynk app that reports temperature

10-xx-2018 Test out Blynk app with live Metabolizer data

10-18-2018 First draft of documentation

