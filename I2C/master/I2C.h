#ifndef I2C_H
#define I2C_H


class I2C{
private: 

public:
I2C(bool master, unsigned char addressNumber);//master=1,slave=0, adress=device adress
~I2C();
  void receiveXY();
  void send(int, int);
  int getX();
  int getY();
private:
  int posX;
  int posY;
  int data[];
  char startFrame;

};

#endif /* I2C_H */
