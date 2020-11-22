#include <capMoisture.h>
#include <Adafruit_ADS1015.h>

capMoisture::capMoisture(Adafruit_ADS1115* _adc,uint8_t _adcIn) {
	adcIn = _adcIn;
	adc = _adc;
};

void capMoisture::read() {
	int16_t raw = adc->readADC_SingleEnded(adcIn);
	val = raw*0.0001875;
	float val2 = val;
	sprintf(msg,"%f",val2); // write val to msg char array for reporting over MQTT
}

