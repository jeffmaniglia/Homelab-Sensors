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
	sprintf(tMsg,"%f",0); // clear msg char array with an array of 0s (0.0000000)
	sprintf(tMsg,"%f",t); // write t to msg char array for reporting over MQTT

	sprintf(hMsg,"%f",0); // clear msg char array with an array of 0s (0.0000000)
	sprintf(hMsg,"%f",h); // write h to msg char array for reporting over MQTT

	sprintf(indMsg,"%f",0); // clear msg char array with an array of 0s (0.0000000)
	sprintf(indMsg,"%f",ind); // write ind to msg char array for reporting over MQTT
}
