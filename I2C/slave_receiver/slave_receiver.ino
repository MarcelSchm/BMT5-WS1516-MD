#include <Wire.h>
#include <arduino.h>

#define DEBUG // comment out for non Debug Run(no Serial.prints)

byte data[5];
int ourX=64;//transmit
int ourY=7;//transmit
int enemyX=1;//receive
int enemyY=2;//receive


void setup(){
  
  Wire.begin(8);                // join i2c bus with address #8(ID3.10)
  Wire.onReceive(receiveEvent); // register receiving message from master
   Wire.onRequest(requestEvent); // register request from master
   #ifdef DEBUG
  Serial.begin(9600);           // start serial for output
  #endif
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
    #ifdef DEBUG
    Serial.print(c);       
    #endif
    if( '@' == c) {  //if startframe is "@"
    int i=1;// data[0] reserved for startframe
  data[i++]= Wire.read();    // receive X1byte as an integer
    data[i++]= Wire.read();    // receive X2byte as an integer
      data[i++]= Wire.read();    // receive Y1byte as an integer
        data[i++]= Wire.read();    // receive Y2byte as an integer
  enemyX=(data[1] << 8) | data[2];
  enemyY=(data[3] << 8) | data[4];
  #ifdef DEBUG
  Serial.print(enemyX);         // print the integer
  Serial.println(enemyY);         // print the integer
  #endif
    }
    else 
    #ifdef DEBUG
    Serial.println("missing startframe");
    #endif
  ;}
    }
  else 
  #ifdef DEBUG
  Serial.println("Error, data not as expected (determinated in ID3.3)");
  #endif
  // BT send Code here? 
;}

void requestEvent(){ // respond with message of 5 bytes as expected by master
// BT receive code here?
int i=0;
data[i++]= '@';
data[i++]= highByte(ourX);
data[i++]= lowByte(ourX);
data[i++]= highByte(ourY);
data[i++]= lowByte(ourY);
  Wire.write(data, 5);//necessary to write everything as data stream
  #ifdef DEBUG
    Serial.println("Transmitted");
    #endif 
}
