/*
* BerryClip.cpp:
*
*        Welcome to MikuQ.com! MikuDuino for BananaPi 
*        
*     by MikuQ(i@mikuq.com) 2017-01-01
*        
* https://github.com/bpiq/MikuPi
*
*/

#include "MikuDuino.h"

#define        LED1 D7
#define        LED2 D11

#define        LED3 D15
#define        LED4 D19

#define        LED5 D21
#define        LED6 D23

#define        Buzzer D24
#define        Switch D26

#define SPACE 100

void setup()
{
        pinMode (LED1, OUTPUT);
        pinMode (LED2, OUTPUT);
        pinMode (LED3, OUTPUT);
        pinMode (LED4, OUTPUT);
        pinMode (LED5, OUTPUT);
        pinMode (LED6, OUTPUT);
        digitalWrite (LED1, LOW);
        digitalWrite (LED2, LOW);
        digitalWrite (LED3, LOW);
        digitalWrite (LED4, LOW);
        digitalWrite (LED5, LOW);
        digitalWrite (LED6, LOW);
}

void loop()
{
        digitalWrite (LED1, HIGH);
        delay(SPACE);
        digitalWrite (LED1, LOW);
        digitalWrite (LED2, HIGH);
        delay(SPACE);
        digitalWrite (LED2, LOW);
        digitalWrite (LED3, HIGH);
        delay(SPACE);
        digitalWrite (LED3, LOW);
        digitalWrite (LED4, HIGH);
        delay(SPACE);
        digitalWrite (LED4, LOW);
        digitalWrite (LED5, HIGH);
        delay(SPACE);
        digitalWrite (LED5, LOW);
        digitalWrite (LED6, HIGH);
        delay(SPACE);
        digitalWrite (LED6, LOW);
}
