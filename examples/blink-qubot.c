/*
 * blink.c:
 *
 *	Welcome to MikuQ.com! MikuDuino for BananaPi 
 *	
 *     by MikuQ(i@mikuq.com) 2016-6-2
 *	
 * https://github.com/bpiq/MikuPi
 *
 */

#include "MikuDuino.h"

int led = 13;

void setup()
{
	pinMode (led, OUTPUT) ;
}

void loop()
{
	digitalWrite (led, HIGH) ;
	delay(500);
	digitalWrite (led, LOW) ;
	delay(500);
}
