#include <Wire.h>

#define XPos 120
#define YPos 45
void setup() {
  // put your setup code here, to run once:
Wire.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(44);                             
  Wire.write('@');            
  Wire.write(XPos);
  Wire.write(YPos);  
  Wire.endTransmission();     

}
