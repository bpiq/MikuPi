#include "MikuDuino.h"
#include "MikuOled.h"

/*
 * apple.cpp:
 *
 *	Welcome to MikuQ.com! MikuDuino for BananaPi 
 *	
 *     by Uncle Li(kgogo@163.com) 2015-1
 *     modify MikuQ(i@mikuq.com) 2016-6-25
 *	
 * https://github.com/bpiq/MikuPi
 *
 */

#define BUFFER_SIZE 1024
uint8_t buffer[BUFFER_SIZE];

Miku_Oled oled;

void setup()
{
	sayHello();
	oled.begin();
}

void loop()
{
	int r;
	FILE *fphzk;
	fphzk=fopen("apple.dat","rb");
	r=fread(buffer,1,BUFFER_SIZE,fphzk);
	while(r>0)
	{
		oled.showBMP(buffer);
		oled.display();
		r=fread(buffer,1,BUFFER_SIZE,fphzk);
		delay(50);
	}
	fclose(fphzk);
}