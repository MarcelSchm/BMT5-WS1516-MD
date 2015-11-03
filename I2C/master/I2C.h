#ifndef I2C_H
#define I2C_H

//A4(SDA),A5(SCL) on Arduino nano

class I2C{

public:
I2C(); // constructor for master
I2C(unsigned char deviceAddress); // constructor for slave
~I2C();
  void receiveXY(); //being a master
  void sendXY(int posX, int posY); //being a master
  int getX();
  int getY();
private:
  int posX;
  int posY;
  int data[];
  char startFrame;
  unsigned char myAddress; //deviceAddress for this instance
};

#endif /* I2C_H */
