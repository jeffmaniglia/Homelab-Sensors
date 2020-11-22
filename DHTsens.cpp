#include "DHTsens.h"
#include <Arduino.h>
#include "DHT.h"

DHTsens::DHTsens(uint8_t pin,uint8_t type,bool _Tunit) {
  Tunit = _Tunit;
  dht = new DHT(pin,type);
}

void DHTsens::setup() {  
  dht->begin();
}

void DHTsens::read() {
	
	h = dht->readHumidity();

	switch(Tunit) {
	case false: // take all readings in Fahrenheit
		t = dht->readTemperature(true);
		ind = dht->computeHeatIndex(t,h);
		break;
	case true: // take all readings in Celsius
		t = dht->readTemperature();
		ind = dht->computeHeatIndex(t,h,false);
		break;
	}
	
	// Write MQTT msg outputs for all variables
	float t2 = t;
	sprintf(tMsg,"%f",t2); // write t to msg char array for reporting over MQTT
	float h2 = h;
	sprintf(hMsg,"%f",h2); // write h to msg char array for reporting over MQTT
	float ind2 = ind;
	sprintf(indMsg,"%f",ind2); // write ind to msg char array for reporting over MQTT
}
