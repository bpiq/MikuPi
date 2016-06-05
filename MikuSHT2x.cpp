#include "MikuDuino.h"
#include "Wire.h"

/*
 *MikuSHT2x.cpp:
 *
 *	Welcome to MikuQ.com! MikuDuino for BananaPi 
 *	
 *     by MikuQ(i@mikuq.com)
 *	
 * https://github.com/bpiq/MikuPi
 *
 */

#include "MikuSHT2x.h"

float Miku_SHT2x::GetHumidity(void)
{
  return (-6.0 + 125.0 / 65536.0 * (float)(readSensor(eRHumidityHoldCmd)));
}

float Miku_SHT2x::GetTemperature(void)
{
  return (-46.85 + 175.72 / 65536.0 * (float)(readSensor(eTempHoldCmd)));
}

uint16 Miku_SHT2x::readSensor(uint8 command)
{
    uint16 result;

    Wire.beginTransmission(eSHT2xAddress);
    Wire.write(command);
    delay(100);
    Wire.endTransmission();

    Wire.requestFrom(eSHT2xAddress, 3);
    while(Wire.available() < 3) {
      ;
    }

    result = ((Wire.read()) << 8);
    result += Wire.read();
	result &= ~0x0003;
    return result;
}

