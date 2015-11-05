#include <Wire.h>
#include <arduino.h>

#define DEBUG // comment out for non Debug Run(no Serial.prints)

byte dataPuffer[5]; // needed as a storage to merge transmittet-bytes to integer position(I2C)


struct my_struct {
  int ourX;//receive
  int ourY;//receive(I2C)
  int enemyX;//transmit
  int enemyY;//transmit(I2C)
}  positions ;




void setup(){
  
  Wire.begin(8);                // join i2c bus with address #8(ID3.10)
  Wire.onReceive(receiveEvent); // register receiving message from master
   Wire.onRequest(requestEvent); // register request from master
   #ifdef DEBUG
  Serial.begin(9600);           // start serial for output
  #endif

}

void loop(){
  positions.enemyY=19;// testing
  positions.enemyX=17;// testing
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
  dataPuffer[i++]= Wire.read();    // receive X1byte as an integer
    dataPuffer[i++]= Wire.read();    // receive X2byte as an integer
      dataPuffer[i++]= Wire.read();    // receive Y1byte as an integer
        dataPuffer[i++]= Wire.read();    // receive Y2byte as an integer
  positions.ourX=(dataPuffer[1] << 8) | dataPuffer[2];
  positions.ourY=(dataPuffer[3] << 8) | dataPuffer[4];
  #ifdef DEBUG
  Serial.print(positions.ourX);         // print the integer
  Serial.println(positions.ourY);         // print the integer
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
dataPuffer[i++]= '@';
dataPuffer[i++]= highByte(positions.enemyX);
dataPuffer[i++]= lowByte(positions.enemyX);
dataPuffer[i++]= highByte(positions.enemyY);
dataPuffer[i++]= lowByte(positions.enemyY);
  Wire.write(dataPuffer, 5);//necessary to write everything as data stream
  #ifdef DEBUG
    Serial.println("Transmitted"); 
    #endif 
}
