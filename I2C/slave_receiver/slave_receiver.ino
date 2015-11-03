#include <Wire.h>
#include <arduino.h>

byte data[5];
int posX1=64;//transmit
int posY1=7;//transmit
int posX2=1;//receive
int posY2=2;//receive


void setup(){
  
  Wire.begin(8);                // join i2c bus with address #8(ID3.10)
  Wire.onReceive(receiveEvent); // register receiving message from master
   Wire.onRequest(requestEvent); // register request from master
  Serial.begin(9600);           // start serial for output
}

void loop(){
  
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany){
  if (5 == howMany){  //are there as many bytes as expected
  while(4 < Wire.available()){  // loop through all but the XY position
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);       
    if( '@' == c) {  //if startframe is "@"
    int i=1;// data[0] reserved for startframe
  data[i++]= Wire.read();    // receive X1byte as an integer
    data[i++]= Wire.read();    // receive X2byte as an integer
      data[i++]= Wire.read();    // receive Y1byte as an integer
        data[i++]= Wire.read();    // receive Y2byte as an integer
  posX2=(data[1] << 8) | data[2];
  posY2=(data[3] << 8) | data[4];
  Serial.print(posX2);         // print the integer
  Serial.println(posY2);         // print the integer
    }
    else Serial.println("missing startframe");
  }
    }
  else Serial.println("Error, Datengroesse anders als in ID3.3 festgelegt");
  // BT send Code here? 
}

void requestEvent(){ // respond with message of 5 bytes as expected by master
// BT receive code here?
int i=0;
data[i++]= '@';
data[i++]= highByte(posX1);
data[i++]= lowByte(posX1);
data[i++]= highByte(posY1);
data[i++]= lowByte(posY1);
  Wire.write(data, 5);//necessary to write everything as data stream
  //Wire.write(byte(posX1 >> 8)); //write X1position as byte
//  Wire.write(byte(posX1 & 0xFF)); //write X2position as byte
//  Wire.write(byte(posY1 >> 8)); //write Y1position as byte
//  Wire.write(byte(posY1 & 0xFF)); //write Y2position as byte
    Serial.print("Transmitted");
  
}
