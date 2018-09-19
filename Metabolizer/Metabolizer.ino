#include <max6675.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
//#include <ESP_Adafruit_SSD1306.h>

//#define OLED_RESET 4

int ktcSO = 12;
int ktcCS = 13;
int ktcCLK = 14;

MAX6675 ktc(ktcCLK, ktcCS, ktcSO);
//Adafruit_SSD1306 display(OLED_RESET);
  
void setup() {
  Serial.begin(9600);
  //delay(500);
  //display.begin(SSD1306_SWITCHCAPVCC, 0x78>>1);
  //display.display();
  delay(2000);
  //display.clearDisplay();
}

void loop() {
  // basic readout test
//  
//  display.setTextSize(2);
//  display.setTextColor(WHITE);
//  display.setCursor(52,10);
//  display.print((char)223); 
//  display.print("C = "); 
//  display.print(ktc.readCelsius());
//  display.print((char)223); 
//  display.print("\t F = ");
//  display.setCursor(52,30);
//  display.println(ktc.readFahrenheit());

  float DC = ktc.readCelsius();
  // Read temperature as Celsius
  float DF = ktc.readFahrenheit();
  
   Serial.print("C = "); 
   Serial.print(ktc.readCelsius());
   Serial.print("\t F = ");
   Serial.println(ktc.readFahrenheit());
// 

 delay(1000);
 //displayData();
}
//
//void displayData(){
//  display.setTextSize(1);
//  display.setCursor(5,1);
//  display.println("14CORE|THERMOCOUPLE");
//  display.setTextSize(2);
//  display.setTextColor(WHITE);
//  display.setCursor(18,20);
//  display.print((char)248); 
//  display.print("C:"); 
//  display.print(ktc.readCelsius());
//  
//    
//  display.setCursor(18,40);
//  display.print((char)248); 
//  display.print("F:");
//  display.println(ktc.readFahrenheit());
//  display.display();
//  display.clearDisplay();
//}
