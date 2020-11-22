#include <LightSens.h>
#include <Arduino.h>
#include <Adafruit_ADS1015.h>



LightSens::LightSens(Adafruit_ADS1115* _adc,uint8_t _adcIn,uint8_t _nrgz) {
	adc = _adc;
	adcIn = _adcIn;
	nrgz = _nrgz;	
};
void LightSens::setup() {
	pinMode(nrgz,OUTPUT);
};
void LightSens::read() {
	digitalWrite(nrgz,HIGH); // energize voltage divider
	delay(250);  // delay for a bit 
	int16_t raw = adc->readADC_SingleEnded(adcIn);  // Take analog reading through ADC
	Serial.print("Raw ADC = ");Serial.println(raw);
	float volts = raw*0.0001875; // Convert ADC reading to analog voltage
	delay(250); // delay for a bit
	digitalWrite(nrgz,LOW); // de-energize voltage divider
	Serial.print("Volts = ");Serial.println(volts); // Print voltage to serial
	float val = ((V*Rk)/volts)-Rk; //(ohms) resistance of photoresistor
	Serial.print("Resistance = ");Serial.println(val); // Print voltage to serial
	float val2 = val;
	sprintf(msg,"%f",val2); // write val to msg char array for reporting over MQTT
};

