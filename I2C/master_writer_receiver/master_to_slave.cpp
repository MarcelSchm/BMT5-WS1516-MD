#include "master_to_slave.h"
#include <Wire.h>
#include "Arduino.h"




masterToSlave::masterToSlave(){
   Wire.begin(); // join i2c bus (address optional for master)
  this->posX=posX;
  this->posY=posY;
  this->startFrame=0;
  #ifdef DEBUG
    Serial.begin(9600);
    #endif
    
  }
 
masterToSlave::~masterToSlave(){ 
   }
   
void masterToSlave::sendXY(int posX, int posY){
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write("@");        // sends  bytes
  Wire.write(highByte(posX));              // sends one byte  from Xposition integer 
   Wire.write(lowByte(posX));              // sends one byte  from Xposition integer 
     Wire.write(highByte(posY));              // sends one byte from Yposition integer  
       Wire.write(lowByte(posY));              // sends one byte  from Yposition integer 
  Wire.endTransmission();    // stop transmitting
  }
  
void masterToSlave::receiveXY(){
 Wire.requestFrom(8, 5);    // request 5 bytes from slave device #8
while(4 < Wire.available()){  // loop through all but the XY position
    char c = Wire.read(); // receive byte as a character
    #ifdef DEBUG
    Serial.print(c); 
#endif    
    if( '@' == c) {  //if startframe is "@"
    int i=0;
  data[i++]= Wire.read();    // receive X1byte as an integer
    data[i++]= Wire.read();    // receive X2byte as an integer
      data[i++]= Wire.read();    // receive Y1byte as an integer
        data[i++]= Wire.read();    // receive Y2byte as an integer
  posX=(data[0] << 8) | data[1];
  posY=(data[2] << 8) | data[3];
  #ifdef DEBUG
  Serial.print(posX);         // print the integer
  Serial.println(posY);         // print the integer
  #endif
   }
    else
    #ifdef DEBUG
    Serial.println("missing startframe");
    #endif
  ;}
 }

int masterToSlave::getX(){
 return posX;
} 
 
int masterToSlave::getY(){
 return posY;
}  

