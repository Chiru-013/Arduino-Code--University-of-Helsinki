#include <LiquidCrystal.h>
#include <SPI.h>
#include <DHT.h> 
#include <LiquidCrystal.h>

 #define DHTPIN 9 // The data pin of DHT11/DHT22 should be connected to the digtal pin 9 of Arduino.   
 #define DHTTYPE DHT22
 DHT dht ( DHTPIN, DHTTYPE ) ;

int sensorIn = A0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  // Set the default voltage of the reference voltage
  analogReference(DEFAULT);
   dht.begin (  ) ;   
}


void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(sensorIn);
  float hum = dht.readHumidity ( ) ;  
  float Temp = dht.readTemperature ( ) ; 

  float uncomp_conc=(sensorValue-400)*2000.0/1600.0;
  float comp_conc = (uncomp_conc*(0.0102*(Temp+273) + 0.76212))-1000;
  Serial.print(uncomp_conc);
  Serial.print(",");
  Serial.println(comp_conc);
}
