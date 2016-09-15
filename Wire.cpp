#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <string.h>

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

#include "MikuDuino.h"
#include "Wire.h"

uint8_t TwoWire::rxBuffer[BUFFER_LENGTH];
uint8_t TwoWire::rxBufferIndex = 0;
uint8_t TwoWire::rxBufferLength = 0;

uint8_t TwoWire::txAddress = 0;
uint8_t TwoWire::txBuffer[BUFFER_LENGTH];
uint16_t TwoWire::txBufferIndex = 0;
uint16_t TwoWire::txBufferLength = 0;

TwoWire::TwoWire()
{
}

void TwoWire::begin()
{
  rxBufferIndex = 0;
  rxBufferLength = 0;

  txBufferIndex = 0;
  txBufferLength = 0;

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
  txAddress = address;
  txBufferIndex = 0;
  txBufferLength = 0;	
			
}

void TwoWire::endTransmission()
{
  I2cError = 0;
  if (ioctl(I2cDevHandle, I2C_SLAVE,txAddress) < 0) I2cError |= ERROR_I2C_SETUP;	

  if(!I2cError)
  {
    if((::write(I2cDevHandle, txBuffer, txBufferLength)) != txBufferLength) 	I2cError |= ERROR_I2C_WRITE;	
  }

  //printf("\n leng = %d \n",txBufferLength);
  txBufferIndex = 0;
  txBufferLength = 0;


  //close(I2cDevHandle);
}

void TwoWire::write(uint8_t cmd)
{
    if(txBufferLength >= BUFFER_LENGTH){
      return;
    }
    // put byte in tx buffer
    txBuffer[txBufferIndex] = cmd;
    ++txBufferIndex;
    // update amount in buffer   
    txBufferLength = txBufferIndex;
}

void TwoWire::write(uint8_t reg, uint8_t dat)
{
  uint8_t buf[2];
  buf[0]=reg;
  buf[1]=dat;
  if(!I2cError)
  {
    if((::write(I2cDevHandle, buf, 2)) != 2) 	I2cError |= ERROR_I2C_WRITE;	
  }
}

void TwoWire::write(uint8_t* dat, int length)
{
    if(txBufferLength+length >= BUFFER_LENGTH){
      return;
    }
    memcpy(txBuffer, dat, length);
    txBufferIndex+=length;
    txBufferLength = txBufferIndex;
    return;

  if(!I2cError)
  {
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

