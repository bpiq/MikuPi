/*
 * sht2x.cpp:
 *
 *	Welcome to MikuQ.com! MikuDuino for BananaPi 
 *	
 *     by MikuQ(i@mikuq.com) 2016-6-5
 *	
 * https://github.com/bpiq/MikuPi
 *
 */

#include "MikuDuino.h"
#include "MikuSHT2x.h"

Miku_SHT2x sht;

void setup()
{
  sayHello();
}

void loop()
{
  printf("Humidity(%%RH): %.2f", sht.GetHumidity());
  printf("     Temperature(C): %.2f\n", sht.GetTemperature());
  delay(1000);
}
