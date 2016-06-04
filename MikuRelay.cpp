#include "MikuDuino.h"
#include "MikuRelay.h"

/*
 * MikuRelay.cpp:
 *
 *	Welcome to MikuQ.com! MikuDuino for BananaPi 
 *	
 *     by MikuQ(i@mikuq.com)
 *	
 * https://github.com/bpiq/MikuPi
 *
 */


Miku_Relay::Miku_Relay()
{
  onPin=D13;
  offPin=D11;
}

Miku_Relay::Miku_Relay(int on, int off)
{
  onPin=on;
  offPin=off;
}

void Miku_Relay::setOn(void)
{
  pinMode (onPin, OUTPUT) ;
  digitalWrite(onPin,  LOW) ;
  delay (10) ;  
  digitalWrite(onPin, HIGH) ;
}

void Miku_Relay::setOff(void)
{
  pinMode (offPin, OUTPUT) ;
  digitalWrite(offPin,  LOW) ;
  delay (10) ;  
  digitalWrite(offPin, HIGH) ;
}
