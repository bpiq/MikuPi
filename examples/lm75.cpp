/*
 * lm75.cpp:
 *
 *      Welcome to MikuQ.com! MikuDuino for BananaPi
 *
 *     by MikuQ(i@mikuq.com) 2017-1-8
 *
 * https://github.com/bpiq/MikuPi
 *
 */

#include <MikuDuino.h>
#include <Wire.h>

void setup()
{
  Wire.begin();
}

void loop()
{
  Wire.requestFrom(72, 2);    
  while(Wire.available()) 
  { 
    int part1 = Wire.read();
    int part2 = Wire.read();
    printf("result is : %.1f\r\n",part1+part2/256.0);
    printf("-----------------\r\n");
  }
  delay(500);
}


