#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
Wire.begin(8);//adress #8
Wire.onReceive(get_data);//register position data from master
Wire.onRequest(send_data);// send position to master
Serial.begin(9600); //115200 baud for bluetooth connection
}

void loop() {
  // put your main code here, to run repeatedly:

}

void get_data(int numBytes){//number of Bytes to get from master
  if(numBytes<=Wire.available()){//if number of Bytes is equal or less
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
    }
  int x = Wire.read();    // receive byte as an integer
  Serial.println(x);         // print the integer
}

void send_data(){
  Wire.write("@");
  Wire.write(x);
  Wire.write(y);
