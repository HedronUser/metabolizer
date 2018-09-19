/*************************************************************
  This is a DEMO. You can use it only for development and testing.
  You should open Setting.h and modify General options.

  If you would like to add these features to your product,
  please contact Blynk for Businesses:

                   http://www.blynk.io/

 *************************************************************/
#include "max6675.h"


//PINS FOR THERMO
int thermoDO = 12;
int thermoCS = 13;
int thermoCLK = 14;

float Celsius = 0.00;
float Fahrenheit = 0.00;

//initialize the thermocouple chip MAX6675
MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

//#define USE_SPARKFUN_BLYNK_BOARD    // Uncomment the board you are using
//#define USE_NODE_MCU_BOARD        // Comment out the boards you are not using
//#define USE_WITTY_CLOUD_BOARD
#define USE_CUSTOM_BOARD          // For all other ESP8266-based boards -
                                    // see "Custom board configuration" in Settings.h

#define APP_DEBUG        // Comment this out to disable debug prints

#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp8266.h>
#include "BlynkProvisioning.h"
#include <TimeLib.h>
#include <WidgetRTC.h>


BlynkTimer timer;         //Timer object used for real-time clock

//////BLYNK VARIABLES

#define TEMPERATURE_CELSIUS_PIN V1
#define TEMPERATURE_FAHRENHEIT_PIN V2

WidgetRTC rtc;            //used for real time clock display


BLYNK_CONNECTED() {
  Serial.print("Blynk Connected at: ");
  digitalClockDisplay();
  rtc.begin();  // Synchronize time on connection
  
  setSyncInterval(180); // RTC Sync interval in seconds, 180=3min this can change to a reasonable value after running once
  
  timer.setInterval(1000, tempReadout);  //10 seconds
  Serial.println("Blynk connected run");

}


void digitalClockDisplay(void){
  // digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.print(" ");
  Serial.print(day());
  Serial.print(".");
  Serial.print(month());
  Serial.print(".");
  Serial.print(year());
  Serial.println();
}

void printDigits(int digits){
  // utility for digitalClockDisplay() which prints preceding colon and leading 0
  
  Serial.print(":");
  if (digits < 10){
    Serial.print('0');
    Serial.print(digits);
  }
  else{
    Serial.print(digits);
  }
}

void setup() {
  delay(500);
  Serial.begin(115200);
  Serial.println("MAX6675 test with provisioning");
  // wait for MAX chip to stabilize
  delay(500);
  
  BlynkProvisioning.begin();

}

void loop() {
  // This handles the network and cloud connection
  BlynkProvisioning.run();
  timer.run();              //Initiates BlynkTimer, timer is necessary for manual variable updating.
  //tempReadout();
}

void tempReadout(){
    // basic readout test, just print the current temp
  
   //Serial.print("C = "); 
   Celsius = thermocouple.readCelsius();
   //Serial.println(thermocouple.readCelsius());
   //Serial.print("F = ");
   Fahrenheit = thermocouple.readFahrenheit();
   //Serial.println(thermocouple.readFahrenheit());
   
   Blynk.virtualWrite(TEMPERATURE_CELSIUS_PIN, Celsius);
   Blynk.virtualWrite(TEMPERATURE_FAHRENHEIT_PIN, Fahrenheit);

}

//
//BLYNK_READ(TEMPERATURE_CELSIUS_PIN){
//     Blynk.virtualWrite(TEMPERATURE_CELSIUS_PIN, Celsius);
//}
//
//BLYNK_READ(TEMPERATURE_FAHRENHEIT_PIN){
//     Blynk.virtualWrite(TEMPERATURE_FAHRENHEIT_PIN, Fahrenheit);
//}
//


BLYNK_APP_CONNECTED() {
  Serial.print("App Connected at: ");
  digitalClockDisplay();
}

BLYNK_APP_DISCONNECTED() { // This is called when Smartphone App is closed
  Serial.print("App Disconnected at: ");
  digitalClockDisplay();

}


