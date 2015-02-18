
#include <Thc.h>
#include "DHT.h"

#define DHTPIN 12     // what pin we're connected to

#define DHTTYPE DHT11   // DHT 11

//Initialize DHT sensor for normal 16mhz Arduino
DHT dht(DHTPIN, DHTTYPE);

Thc Thc(2,3,4,5,13); //This bracket will contain the pin numbers we are to use,It is meant to initialize them to output/input mode
//Thc Thc(Fan In,Fan Out, Heater,Humidifier)

int err =13;
void setup()
{

Serial.begin(9600); 
dht.begin();
}
void loop()
{
  
delay(2000);

float TEMP = dht.readTemperature();


  
float HUM = dht.readHumidity();

  
  
Thc.GodsCommand(HUM,TEMP);

}
