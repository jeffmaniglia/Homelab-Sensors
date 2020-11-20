#include <capMoisture.h>
#include <Adafruit_ADS1015.h>

capMoisture::capMoisture(Adafruit_ADS1115* _adc,uint8_t _adcIn) {
	adcIn = _adcIn;
	adc = _adc;
};

void capMoisture::read() {
	uint16_t raw = adc->readADC_SingleEnded(adcIn);
	val = raw*0.0001875;
	
	sprintf(msg,"%f",0); // clear msg char array with an array of 0s (0.0000000)
	sprintf(msg,"%f",val); // write val to msg char array for reporting over MQTT
}

