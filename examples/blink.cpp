/*
 * blink.cpp:
 *
 *	Welcome to MikuQ.com! MikuDuino for BananaPi 
 *	
 *     by MikuQ(i@mikuq.com) 2016-6-2
 *	
 * https://github.com/bpiq/MikuPi
 *
 */

#include "MikuDuino.h"

#define	LED D7

void setup()
{
	pinMode (LED, OUTPUT) ;
}

void loop()
{
	digitalWrite (LED, HIGH) ;
	delay(500);
	digitalWrite (LED, LOW) ;
	delay(500);
}
