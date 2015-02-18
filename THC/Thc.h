/*
Thc.h , Library for temperature and humidity control.
Created by Ndeto N. Martin 28/1/2015
*/

#ifndef Thc_h
#define Thc_h

#include "Arduino.h"

class Thc
{
public:
	Thc(int fanin, int fanout,int heater,int humidifier,int err);
	
	void GodsCommand(float hum,float temp);
	
private:
	int _fanin;
	int _fanout;
	int _heater;
	int _humidifier;
	float _hum;
	float _temp;
	int _err;
};

#endif