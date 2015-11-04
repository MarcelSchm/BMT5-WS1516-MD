#include <Wire.h>
#include "master_to_slave.h"

// if no serial.print wanted, comment DEBUG in "master_to_slave.h" out

masterToSlave *Kommunikation;


void setup(){
Kommunikation = new masterToSlave;
}

void loop(){
Kommunikation->sendXY(42,47);// example position
Kommunikation->sendXY(5,64);// example position
  delay(500);
  
  Kommunikation->receiveXY();//get position from other vehicle. You can see the position as serial print...
  Serial.println(Kommunikation->getX());// or use this member function to get position
  delay(100);
}

