#include "Arduino.h"
#include "Thc.h"



Thc::Thc(int fanin, int fanout,int heater,int humidifier,int err) 
{

pinMode(fanin, OUTPUT);
_fanin = fanin;
pinMode(fanout, OUTPUT);
_fanout = fanout;
pinMode(heater, OUTPUT);
_heater = heater;
pinMode(humidifier,OUTPUT);
_humidifier = humidifier; 
pinMode(err,OUTPUT);
_err = err;

}

void Thc::GodsCommand(float HUM, float TEMP)
{

//The variables _hum and _temp are to be stored in order to compare the incoming HUM and TEMP Variables

_hum = HUM;
_temp = TEMP;


//GodsCommand Code Here

if (isnan(_temp)) {
    Serial.println("Failed to read from DHT sensor!");
    digitalWrite(_err,HIGH);
    digitalWrite(_fanin,LOW); //Switch Off Fan
	digitalWrite(_humidifier,LOW); //Switch Off Humidifier
    return;
  }else
  {
  digitalWrite(_err,LOW);
  }
  
  
  if (isnan(_hum)) {
    Serial.println("Failed to read from DHT sensor!");
    digitalWrite(_err,HIGH);
	digitalWrite(_humidifier,LOW); //Switch Off Humidifier
    return;
  }else
  {
  digitalWrite(_err,LOW);
  }


    if (TEMP>=(double)33) {
  digitalWrite(_fanin,HIGH); //Switch On Fan
  }else{
  digitalWrite(_fanin,LOW); //Switch Off Fan
  }
  
      if (HUM<(double)42) {
  digitalWrite(_humidifier,HIGH); //Switch On Humidifier
  }else{
  digitalWrite(_humidifier,LOW); //Switch Off Humidifier
  }
  
  Serial.print("Temperature: ");
  Serial.print(TEMP);
  Serial.println("*C\t");
  Serial.print("Humidity: "); 
  Serial.print(HUM);
  Serial.print(" %\t");
  Serial.println(" \n");
  
}
