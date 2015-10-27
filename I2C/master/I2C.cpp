#include "I2C.h"
#include <Wire.h>

I2C::I2C(bool master, unsigned char addressNumber){
if(1==master){
  Wire.begin();
  }
  else {
  Wire.begin(addressNumber);
  }
  this->posX=0;
  this->posY=0;
  this->startFrame=0;
  
}

I2C::~I2C(){
  
  
  }

void I2C::receiveXY(){
  
  
  
  
  
  
  
  }




