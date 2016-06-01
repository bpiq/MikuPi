#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gpio_lib.h"

// pinToGpio:
//	Take a Wiring pin (0 through X) and re-map it to the BCM_GPIO pin
//	Cope for 3 different board revisions here.

static int *wPinToGpio ;

static int wPinToGpioM2p [32] =
{
	1,16,0,3,		15,68,2,6, 
	12,11,67,71,	64,65,66,13, 
	14,-1,-1,-1,	-1,7,8,9, 
	10,17,354,356,  21,20,19,18
} ;

static int wPinToGpioM3 [32] =
{
	68,35,71,81,		34,360,361,362, 
	229,228,67,234,		64,65,66,32, 
	33,-1,-1,-1,		-1,82,202,203, 
	204,132,205,133,	146,147,227,226
} ;

//static int *bPinTowPin;

static int bPinTowPin[41] =
{
  -1,		// 0
  -1, -1,	// 1, 2
   8, -1,  //3, 4
   9, -1,  //5, 6
   7, 15,  //7, 8
  -1, 16, //9,10
  0, 1, //11,12
  2, -1, //13,14
  3, 4, //15,16
  -1, 5, //17,18
  12, -1, //19,20
   13, 6, //21,22
  14, 10, //23, 24
  -1,  11,	// 25, 26
  
  30,   31,   //27, 28
  21,  -1,  //29, 30
  22,  26,  //31, 32
  23, -1, //33, 34
  24, 27, //35, 36
  25, 28, //37, 38
  -1, 29, //39, 40
} ;

//#define PA6    SUNXI_GPA(6)  *32+6
#define PA6    wPinToGpioM2p[bPinTowPin[36]]

int main()
{
	/*
	  if (geteuid () != 0)
	  {
    printf("wiringPiSetup: Must be root. (Did you forget sudo?)\n") ;
	return -1;
	  }
	  */
	    if(SETUP_OK!=sunxi_gpio_init()){
        printf("Failed to initialize GPIO\n");
        return -1;
    }

    if(SETUP_OK!=sunxi_gpio_set_cfgpin(PA6,OUTPUT)){
        printf("Failed to config GPIO pin\n");
        return -1;
    }

    int i,j;
      while(1)	{
        if(sunxi_gpio_output(PA6,HIGH)){
            printf("Failed to set GPIO pin value\n");
            return -1;
        }

        usleep(500000);
        if(sunxi_gpio_output(PA6,LOW)){
            printf("Failed to set GPIO pin value\n");
            return -1;
        }
        usleep(500000);
    
}
    sunxi_gpio_cleanup();

  return 0;
}