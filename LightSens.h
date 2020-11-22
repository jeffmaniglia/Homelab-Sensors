#ifndef LIGHTSENS_H
#define LIGHTSENS_H

#include <Arduino.h>
#include <Adafruit_ADS1015.h>

#define MSGLEN 50

// This class utilizes any standard photoresistor and a 10k resistor to measure light input
// +5V (or digital high) ---- Photoresistor ---- 10k Resistor ---- Ground
// 											  |---- Analog input on ADS1115
// If you measure the true resistance of 10k resistor, substitute into Rk value
class LightSens {
	private:
	// objects
	float Rk = 10000; // (Ohms) resistance of voltage divider resistor
	float V = 3.3; // (V) supply voltage through photoresistor and voltage divider
	uint8_t nrgz; // pin use to energize the photoresistor and voltage divider
	Adafruit_ADS1115* adc; // Object representing analog to digital converter - must be set to default gain
	uint8_t adcIn; // Analog input pin that the moisture sensor is utilizing
	
	// methods
	
	public:
	// objects
	float val; // (Ohms) output value (photoresistor resistance)
	char msg[MSGLEN]; // (Ohms) output value in char array (photoresistor resistance)
	// methods
	LightSens(Adafruit_ADS1115* _adc,uint8_t _adcIn,uint8_t _nrgz);
	void setup();
	void read();
};

#endif