//Code to display CO2 concentration value on LCD
#include <LiquidCrystal.h>
#include <SPI.h>
#include <DHT.h> 
#include <LiquidCrystal.h>

 #define DHTPIN 9 // The data pin of DHT11/DHT22 should be connected to the digtal pin 9 of Arduino.   
 #define DHTTYPE DHT22
 DHT dht ( DHTPIN, DHTTYPE ) ;
//#include <Adafruit_SSD1306.h>

const int rs = 12, en = 11, d4 = 6, d5 = 5, d6 = 4, d7 = 3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int sensorIn = A0;


void setup() {
  
  lcd.begin(16, 2);  // set up the LCD's number of columns and rows:
  lcd.print("CO2 Conc.");  // Print a text to the LCD.
  Serial.begin(38400);
  // Set the default voltage of the reference voltage
  analogReference(DEFAULT);
   dht.begin (  ) ;   
}

void loop() {

  int sensorValue = analogRead(sensorIn);
  // The analog signal is converted to a voltage
  //float voltage = sensorValue*(4000/1024.0);
  lcd.setCursor(0, 1);  // set the cursor to column 0, line 1
  float hum = dht.readHumidity ( ) ;  
  float Temp = dht.readTemperature ( ) ; 
  
  if(sensorValue == 0)
  {
    Serial.println("Fault");
  }
  else if(sensorValue < 400)
  {
    Serial.println("preheating");
  }
  else
  {

    float uncomp_conc=(sensorValue-400)*2000.0/1600.0;
    float comp_conc = uncomp_conc*(0.0102*Temp + 0.76212);
    //Print Voltage
    Serial.print("voltage: ");
    Serial.print(sensorValue);
    Serial.println("mv");
    //Print CO2 concentration
    Serial.print("CO2 Concentration: ");
    //Serial.print(concentration);
    Serial.print(comp_conc);
    Serial.print(uncomp_conc;
    Serial.println("ppm");
  //   //Serial.println("ppm");
  lcd.print(uncomp_conc,2);
  lcd.print(" ppm"); 
  Serial.println(" ");

  }
  //Serial.println(sensorValue);
  delay(2000);
  
  
  
}
