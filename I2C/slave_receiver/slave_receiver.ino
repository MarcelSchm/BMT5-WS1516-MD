#include <Wire.h>

void setup()
{
  Wire.begin(44);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
   Wire.onRequest(requestEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop()
{
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  while(2 < Wire.available()) // loop through all but the last
  {
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  int x = Wire.read();    // receive byte as an integer
  Serial.print(x);         // print the integer
    int y = Wire.read();    // receive byte as an integer
  Serial.println(y);         // print the integer
}
void requestEvent()
{
  Wire.write("@"); // respond with message of 6 bytes
                       // as expected by master
  Wire.write(50);
  Wire.write(50);
}
