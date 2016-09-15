#ifndef _TWOWIRE_H_
#define _TWOWIRE_H_

#include "MikuTypes.h"

#define	ERROR_I2C_OPEN		1
#define	ERROR_I2C_SETUP		2
#define	ERROR_I2C_READ		4
#define	ERROR_I2C_WRITE		8

#define BUFFER_LENGTH 2000

class TwoWire
{
  private:
    static uint8_t rxBuffer[];
    static uint8_t rxBufferIndex;
    static uint8_t rxBufferLength;

    static uint8_t txAddress;
    static uint8_t txBuffer[];
    static uint16_t txBufferIndex;
    static uint16_t txBufferLength;

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
    void write(uint8_t);
    void write(uint8_t,uint8_t);
    void write(uint8_t*,int);
};

extern TwoWire Wire;

#endif
