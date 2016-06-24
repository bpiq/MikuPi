#include "MikuDuino.h"
#include "MikuOled.h"

/*
 * oled.cpp:
 *
 *	Welcome to MikuQ.com! MikuDuino for BananaPi 
 *	
 *     by MikuQ(i@mikuq.com) 2016-6-24
 *	
 * https://github.com/bpiq/MikuPi
 *
 */

Miku_Oled oled;

void setup()
{
	sayHello();
	oled.begin();
	oled.showLogo();
	oled.display();
}

void loop()
{
	delay(1000);
}