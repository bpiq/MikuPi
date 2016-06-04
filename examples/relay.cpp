/*
 * relay.cpp:
 *
 *	Welcome to MikuQ.com! MikuDuino for BananaPi 
 *	
 *     by MikuQ(i@mikuq.com) 2016-6-4
 *	
 * https://github.com/bpiq/MikuPi
 *
 */

#include "MikuDuino.h"
#include "MikuRelay.h"

Miku_Relay relay;

void setup()
{	
	sayHello();
}

void loop()
{
	relay.setOn();
	delay(2000);
	relay.setOff();
	delay(8000);
}
