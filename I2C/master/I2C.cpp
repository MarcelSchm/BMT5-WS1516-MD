#include "I2C.h"
#include <Wire.h>
#include <arduino.h>

I2C::I2C(){
  Wire.begin();
  this->posX=posX;
  this->posY=posY;
  this->startFrame=0;
  }
  
I2C::I2C(unsigned char deviceAddress){
  
  Wire.begin(deviceAddress);
//  Wire.onRequest(I2C.sendXY()); //register request event from master
//  Wire.onReceive(I2C.receiveXY()); //register whenever data is received
  this->posX=posX;
  this->posY=posY;
  this->startFrame=0;
  myAddress=deviceAddress;
  
}

I2C::~I2C(){
  }

void I2C::receiveXY(){//master
   Wire.requestFrom(8, 6);    // request 6 bytes from slave device #8

  while(Wire.available())    // slave may send less than requested
  { 
    char c = Wire.read(); // receive a byte as character
    Serial.print(c);         // print the character
  }

  delay(500);
  
}

void I2C::sendXY(int posX, int posY){//master
    Wire.beginTransmission(8);                             
  Wire.write('@');            
  Wire.write(posX);
  Wire.write(posY);  
  Wire.endTransmission(); 
  }
  
int I2C::getX(){
  return posX;
  }
  
int I2C::getY(){
  return posY;
  }
  



