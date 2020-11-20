#ifndef DHTSENS_H
#define DHTSENS_H

#include "DHT.h"
#include <Arduino.h>

#define MSGLEN

class DHTsens
{
  private:
  uint8_t Tunit = false; // Selection of Tunit, default is Fahrenheit (false) Celsius is true
  DHT *dht;
  
  public:
  // Variables
  float h; // Humidity reading
  float t; // Temperature reading (C or F depending on setting)
  float ind; // Heat Index (C or F depending on setting)
  char hMsg[MSGLEN]; // Humidity reading output for MQTT
  char tMsg[MSGLEN]; // Temperature reading (C or F depending on setting) output for MQTT
  char indMsg[MSGLEN]; // Heat Index (C or F depending on setting) output for MQTT
  // Methods
  DHTsens(uint8_t pin,uint8_t type,bool _Tunit);
  void setup();
  void read();
};

#endif
