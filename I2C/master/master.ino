#include <Wire.h>
#include "I2C.h"

#define XPos 120
#define YPos 45

I2C myConnection(44); 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 myConnection.receiveXY();
 myConnection.sendXY(24,42);
 
 
 
//  Wire.beginTransmission(44);                             
//  Wire.write('@');            
//  Wire.write(XPos);
//  Wire.write(YPos);  
//  Wire.endTransmission();     

}
