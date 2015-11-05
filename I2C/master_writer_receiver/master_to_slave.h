#ifndef MASTER_TO_SLAVE_H
#define MASTER_TO_SLAVE_H
#ifndef WIRE_H
#define WIRE_H
#endif

#define DEBUG // comment out for non Debug Run(no Serial.prints)

//A4(SDA),A5(SCL) on Arduino nano

class masterToSlave {
public:
masterToSlave();//constructor
~masterToSlave(); //destructor
void sendXY(int posX, int posY); // send data to slave
void receiveXY();// get data from slave(in Debug mode: serial.print position)
int getX(); //get x Position
int getY(); //get Y Position

private:
  int posX;
  int posY;
int data[];
  char startFrame;

};

  #endif /*MASTER_TO_SLAVE_H*/
