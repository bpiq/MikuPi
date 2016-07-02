#include "MikuDuino.h"
#include "MikuOled.h"

/*
 * oled_test.cpp:
 *
 *	Welcome to MikuQ.com! MikuDuino for BananaPi 
 *	
 *     modify MikuQ(i@mikuq.com) 2016-7-2
 *	
 * https://github.com/bpiq/MikuPi
 *
 */

Miku_Oled oled;

char buf[20];
int c=0;

void setup()
{
	sayHello();
	oled.begin();
	oled.display();
	delay(1000);
}

void loop()
{
	oled.clearDisplay();
	oled.drawText(">>MikuOLED¼ÆÊý<<");
	sprintf(buf,"Î»ÖÃ£º%d",c+1);
	oled.setPos(28,28);
	oled.drawText(buf);
        oled.drawPoint(c,60,1);
        oled.drawPoint(c+2,60,1);
        oled.drawPoint(c+1,61,1);
        oled.drawPoint(c,62,1);
        oled.drawPoint(c+2,62,1);
	c++;
	if (c>125)
		c=0;
	oled.display();
	delay(10);
}