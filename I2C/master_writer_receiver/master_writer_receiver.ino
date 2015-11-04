#include <Wire.h>
#include "master_to_slave.h"

masterToSlave *Kommunikation;


void setup(){
Kommunikation = new masterToSlave;
}

void loop(){
Kommunikation->sendXY(42,47);
Kommunikation->sendXY(5,64);
  delay(500);
  
  Kommunikation->receiveXY();
  Serial.println(Kommunikation->getX());
  delay(100);
}

