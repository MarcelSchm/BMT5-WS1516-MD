#ifndef I2C_H
#define I2C_H

//A4,A5
class I2C{
private: 

public:
I2C();
I2C(unsigned char addressNumber);//master=1,slave=0, adressNumber=device address
~I2C();
  void receiveXY();
  void sendXY(int posX, int posY);
  int getX();
  int getY();
private:
  int posX;
  int posY;
  int data[];
  char startFrame;
//  unsigned char addressNumber;
};

#endif /* I2C_H */
