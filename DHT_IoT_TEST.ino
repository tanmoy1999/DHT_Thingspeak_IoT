#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;
#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor
#define DHTTYPE DHT11   // DHT 11
#define dht_dpin 0
DHT dht(dht_dpin, DHTTYPE);
 
const char* ssid = "D-Link_DIR-600M"; //Your Network SSID
const char* password = "alliswell"; //Your Network Password
 
//int val;
//int LDRpin = A0; //LDR Pin Connected at A0 Pin

WiFiClient client;
 
unsigned long myChannelNumber = ******; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "************"; //Your Write API Key
 
void setup()
{
    dht.begin();
    Serial.begin(9600);
    Serial.println("temperature\n\n");
    delay(700);
    //Serial.begin(9600);
    //delay();
    // Connect to WiFi network
    WiFi.begin(ssid, password);
    ThingSpeak.begin(client);
}
 
void loop()
{
    //val = analogRead(LDRpin); //Read Analog values and Store in val variable
    //Serial.println(val); //Print on Serial Monitor
    //delay(100);
    float t = dht.readTemperature();
    Serial.print("temperature = ");
    Serial.print(t); 
    Serial.println("C  ");
    ThingSpeak.writeField(myChannelNumber, 1,t, myWriteAPIKey); //Update in ThingSpeak
    delay(60000);
}
