#include "MikuDuino.h"
#include "MikuOled.h"
#include <stdio.h>
#include<stdlib.h>
/*
 * arg_oled.cpp:
 *
 *	Show console parameter on Oled
 *
 *	Usage:arg_oled "parameter1" "parameter2" "parameter3" 
 *
 *	Notice:Chinese character set need use GB2312 code!!!
 *
 *	modify mo10(0w0@0w0.pw) 2016-7-9
 *	
 *	https://github.com/bpiq/MikuPi
 *
 */

Miku_Oled oled;
char buf[20];

void setup(int argc,char *argv[])
{
	sayHello();
	oled.begin();
	oled.clearDisplay();
	int i;
	for(i=1;i<argc;i++){
		sprintf(buf,"%s\n",argv[i]);
		oled.drawText(buf);
		oled.display();
	}
}

void loop()
{
	exit(0);
}
