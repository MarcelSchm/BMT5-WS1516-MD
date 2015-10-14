//einfaches Bluetooth programm, dass über Serial 1 oder 0 einliest und danach LED13 ein oder ausschaltet

#define ledpin 13 // led on D13 will show blink on / off
int BluetoothData; // the data given from Computer

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial.println("Bluetooth On please press 1 or 0 blink LED ..");
  pinMode(ledpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   if (Serial1.available()){
BluetoothData=Serial1.read();
   if(BluetoothData=='1'){   // if number 1 pressed ....
   digitalWrite(ledpin,HIGH);
   Serial.println("LED  On D13 ON ! ");
   }
  if (BluetoothData=='0'){// if number 0 pressed ....
  digitalWrite(ledpin,LOW);
   Serial.println("LED  On D13 Off ! ");
  }
}
delay(100);// prepare for next data ...
}

