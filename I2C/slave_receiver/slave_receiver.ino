#include <Wire.h>
#include <arduino.h>

int data[4];
int posX;
int posY;

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
  if (5 == howMany){  //are there as many bytes as expected=
  while(4 < Wire.available()){  // loop through all but the XY position
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);       
    if( '@' == c) {  //if startframe is "@"
    int i=0;
  data[i++]= Wire.read();    // receive X1byte as an integer
    data[i++]= Wire.read();    // receive X2byte as an integer
      data[i++]= Wire.read();    // receive Y1byte as an integer
        data[i++]= Wire.read();    // receive Y2byte as an integer
  posX=(data[0] << 8) | data[1];
  posY=(data[2] << 8) | data[3];
  Serial.print(posX);         // print the integer
  Serial.println(posY);         // print the integer
    }
    else Serial.println("missing startframe");
  }
    }
  else Serial.println("Error, Datengroesse anders als in ID3.3 festgelegt");
  // BT send Code hier? 
}

void requestEvent(){ // respond with message of 6 bytes as expected by master
// BT receive code hier?
  Wire.write("@");//write startframe
  Wire.write(posX >> 8); //write X1position as byte
  Wire.write(posX & 0xFF); //write X2position as byte
   Wire.write(posY >> 8); //write Y1position as byte
  Wire.write(posY & 0xFF); //write Y2position as byte
}
