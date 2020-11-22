#ifndef CAPMOISTURE_H
#define CAPMOISTURE_H

#include <Arduino.h>
#include <Adafruit_ADS1015.h>

#define MSGLEN 50

class capMoisture {
	private:
		// Private objects:
		Adafruit_ADS1115* adc; // Object representing analog to digital converter - must be set to default gain
		uint8_t adcIn; // Analog input pin that the moisture sensor is utilizing
		
		// Private methods:
	public:
		// Public objects:
		float val;
		char msg[MSGLEN];
		//Public Methods:
		capMoisture(Adafruit_ADS1115* _adc,uint8_t adcIn); // Constructor
		void read();
};


#endif