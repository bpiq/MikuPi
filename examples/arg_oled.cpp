#include "MikuDuino.h"
#include "MikuOled.h"

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

void setup()
{
	sayHello();
	oled.begin();
        oled.setEncoding(UTF8);
	oled.clearDisplay();
	int i;
	for(i=1;i<lu_argc;i++){
		sprintf(buf,"%s\n",lu_argv[i]);
		oled.drawText(buf);
		oled.display();
	}
}

void loop()
{
	exit(0);
}
