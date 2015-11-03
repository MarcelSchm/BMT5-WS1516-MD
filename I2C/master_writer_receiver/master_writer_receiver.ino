#include <Wire.h>

byte data[4];

void setup(){
  Wire.begin(); // join i2c bus (address optional for master)
  Serial.begin(9600);
}

int posX1=42;//transmit
int posY1=64;//transmit
int posX2;//receive
int posY2;//receive

void loop(){
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write("@");        // sends  bytes
  Wire.write(highByte(posX1));              // sends one byte  from Xposition integer 
   Wire.write(lowByte(posX1));              // sends one byte  from Xposition integer 
     Wire.write(highByte(posY1));              // sends one byte from Yposition integer  
       Wire.write(lowByte(posY1));              // sends one byte  from Yposition integer 
  Wire.endTransmission();    // stop transmitting
  
  delay(500);
  
  
    Wire.requestFrom(8, 5);    // request 5 bytes from slave device #8
while(4 < Wire.available()){  // loop through all but the XY position
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);       
    if( '@' == c) {  //if startframe is "@"
    int i=0;
  data[i++]= Wire.read();    // receive X1byte as an integer
    data[i++]= Wire.read();    // receive X2byte as an integer
      data[i++]= Wire.read();    // receive Y1byte as an integer
        data[i++]= Wire.read();    // receive Y2byte as an integer
  posX2=(data[0] << 8) | data[1];
  posY2=(data[2] << 8) | data[3];
  Serial.print(posX2);         // print the integer
  Serial.println(posY2);         // print the integer
   }
    else Serial.println("missing startframe");
  }
    
  // BT send Code hier? 
  delay(500);
}

