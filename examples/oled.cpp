#include "MikuDuino.h"
#include "MikuOled.h"

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