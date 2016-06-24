#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>

/*
 *Wire.cpp:
 *
 *	Welcome to MikuQ.com! MikuDuino for BananaPi 
 *	
 *     by MikuQ(i@mikuq.com)
 *	
 * https://github.com/bpiq/MikuPi
 *
 */

#include "MikuPi.h"
#include "Wire.h"

uint8 TwoWire::rxBuffer[BUFFER_LENGTH];
uint8 TwoWire::rxBufferIndex = 0;
uint8 TwoWire::rxBufferLength = 0;

TwoWire::TwoWire()
{
}

void TwoWire::begin()
{
  I2cError = 0;
  if ((I2cDevHandle = open(i2cDevice, O_RDWR)) < 0)  I2cError |= ERROR_I2C_OPEN;
}

void TwoWire::requestFrom(int address, int quantity)
{
  I2cError = 0;
    if (ioctl(I2cDevHandle, I2C_SLAVE,address) < 0) I2cError |= ERROR_I2C_SETUP;					
  
  if(!I2cError)
  {
    if (::read(I2cDevHandle, rxBuffer,quantity) != quantity) I2cError |= ERROR_I2C_READ;	
    else
    {
      rxBufferIndex = 0;
      rxBufferLength = quantity;
    }	
  }
}

void TwoWire::beginTransmission(int address)
{
  I2cError = 0;
  if (ioctl(I2cDevHandle, I2C_SLAVE,address) < 0) I2cError |= ERROR_I2C_SETUP;					
}

void TwoWire::endTransmission()
{
  //close(I2cDevHandle);
}

void TwoWire::write(uint8 cmd)
{
  if(!I2cError)
  {
    if((::write(I2cDevHandle, &cmd, 1)) != 1) 	I2cError |= ERROR_I2C_WRITE;	
  }
}

void TwoWire::write(uint8 reg, uint8 dat)
{
  uint8 buf[2];
  buf[0]=reg;
  buf[1]=dat;
  if(!I2cError)
  {
    if((::write(I2cDevHandle, buf, 2)) != 2) 	I2cError |= ERROR_I2C_WRITE;	
  }
}

void TwoWire::write(uint8* dat, int length)
{
  if(!I2cError)
  {
    //write(int handle, void *buf, int nbyte);
    if((::write(I2cDevHandle, dat, length)) != length) 	I2cError |= ERROR_I2C_WRITE;	
  }
}

int TwoWire::available(void)
{
  return rxBufferLength - rxBufferIndex;
}

int TwoWire::read(void)
{
  int value = -1;
  
  if(rxBufferIndex < rxBufferLength){
    value = rxBuffer[rxBufferIndex];
    ++rxBufferIndex;
  }

  return value;
}

TwoWire Wire = TwoWire();

