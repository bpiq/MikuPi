#ifndef _TWOWIRE_H_
#define _TWOWIRE_H_

#include "MikuTypes.h"

#define	ERROR_I2C_OPEN		1
#define	ERROR_I2C_SETUP		2
#define	ERROR_I2C_READ		4
#define	ERROR_I2C_WRITE		8

#define BUFFER_LENGTH 32

class TwoWire
{
  private:
    static uint8 rxBuffer[];
    static uint8 rxBufferIndex;
    static uint8 rxBufferLength;
    int I2cDevHandle;
    int	I2cError;
  public:
    TwoWire();
    void begin();
    void beginTransmission(int);
    void endTransmission(void);
    void requestFrom(int, int);
    int available(void);
    int read(void);
    void write(uint8);
    void write(uint8,uint8);
    void write(uint8*,int);
};

extern TwoWire Wire;

#endif
