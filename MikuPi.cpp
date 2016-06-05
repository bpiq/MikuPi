#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

/*
 * MikuPi.cpp:
 *
 *	Welcome to MikuQ.com! MikuDuino for BananaPi 
 *	
 *     by MikuQ(i@mikuq.com)
 *	
 * https://github.com/bpiq/MikuPi
 *
 */

#include "MikuPi.h"

char *i2cDevice;

const char *i2cDevices[3] =
{
  "/dev/i2c-0",
  "/dev/i2c-1",
  "/dev/i2c-2"
} ;

const char *piModelNames [7] =
{
  "Unknown",
  "BPI-M1 ",
  "BPI-R1 ",
  "BPI-M2 ",
  "BPI-M1+",
  "BPI-M3 ",
  "BPI-M2+",
} ;

int MikuPiDebug       = FALSE;

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

const int bPinTowPin[41] =
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

unsigned int SUNXI_PIO_BASE = 0;
unsigned int SUNXI_PIO_LM_BASE = 0;
static volatile long int *gpio_map = NULL;

void delay(unsigned int howLong)
{
  struct timespec sleeper, dummy ;

  sleeper.tv_sec  = (time_t)(howLong / 1000) ;
  sleeper.tv_nsec = (long)(howLong % 1000) * 1000000 ;

  nanosleep (&sleeper, &dummy) ;
}

static void piBoardRevOops (const char *why)
{
  //fprintf (stderr, "piBoardRev: Unable to determine board revision from /proc/cpuinfo\n") ;
  fprintf (stderr, " -> %s\n", why) ;
  fprintf (stderr, " ->  You may want to check:\n") ;
  fprintf (stderr, " ->  http://MikuQ.com\n") ; 
  exit (EXIT_FAILURE) ;
}

void piBoardId(int *model, int *mem)
{
  FILE *cpuFd ;
  char line [120] ;
  char *d;

  int processorCount=0;

  if ((cpuFd = fopen ("/proc/cpuinfo", "r")) == NULL)
    piBoardRevOops ("Unable to open /proc/cpuinfo") ;
  while (fgets (line, 120, cpuFd) != NULL)
  {
	if (strncmp (line, "processor", 9) == 0)
      processorCount++;
    if (strncmp (line, "Hardware", 8) == 0)
      break;
  }
		
  fclose (cpuFd) ;
  if (strncmp (line, "Hardware", 8) != 0)
    piBoardRevOops ("No \"Hardware\" line") ;
	
  for (d = &line [strlen (line) - 1] ; (*d == '\n') || (*d == '\r') ; --d)
    *d = 0 ;
  if (MikuPiDebug)
    printf ("piboardRev: Hardware string: %s\n", line) ;
	
  if (strstr(line,"sun8i") != NULL)
  {
	  if (processorCount==4)
	  {
		  //H3-M2p
		  *model = PI_MODEL_M2p;
		  *mem = 1024;
	  }
	  if (processorCount==8)
	  {
		  //A83T-M3
		  *model = PI_MODEL_M3;
		  *mem = 2048;
	  }
    if (MikuPiDebug)
	{
      printf ("Hardware:%s\n",line) ;
      printf ("processorCount:%d\n",processorCount) ;
	}
  }
  else if (strstr(line,"sun7i") != NULL)
  {
	      *model = PI_MODEL_M1;
		  *mem = 1024;
  }
  else if (strstr(line,"sun6i") != NULL)
  {
	      *model = PI_MODEL_M2;
		  *mem = 1024;
  }
  else
  {
	  	  *model = PI_MODEL_UNKNOWN;
		  *mem = 0;
    if (MikuPiDebug)
      printf ("Hardware:%s\n",line) ;
  }
}

void sayHello()
{
	int model, mem;
	printf("Welcome to MikuQ.com! MikuDuino for BananaPi version: %s\n", VERSION);
	piBoardId (&model, &mem);

    if (model == PI_MODEL_UNKNOWN)
    {
      printf ("Your Pi has an unknown model type. Please report this to\n") ;
      printf ("    i@mikuq.com\n") ;
      printf ("with a copy of your /proc/cpuinfo if possible\n") ;
    }
    else
    {
      printf ("BananaPi Details:\n") ;
      printf ("  Type: %s, Memory: %dMB\n", piModelNames [model], mem) ;
      //printf ("  I2C Device: %s\n",i2cDevice) ;
    }
}

void mikuPiSetup (void)
{
    int fd;
    unsigned int addr_start, addr_offset;
    unsigned int PageSize, PageMask;

	if (geteuid () != 0)
		piBoardRevOops("MikuPiSetup: Must be root. (Did you forget sudo?)");

	int model, mem;
	piBoardId (&model, &mem);
	if (model == PI_MODEL_UNKNOWN)
    {
      printf ("Your Pi has an unknown model type. Please report this to\n") ;
      printf ("    i@mikuq.com\n") ;
      piBoardRevOops ("with a copy of your /proc/cpuinfo if possible") ;
    }

  if (model == PI_MODEL_M2p) {
    wPinToGpio=wPinToGpioM2p;
    i2cDevice=(char *)i2cDevices[0];
  }
  if (model == PI_MODEL_M3) {
    wPinToGpio=wPinToGpioM3;
    i2cDevice=(char *)i2cDevices[3];
  }

    fd = open("/dev/mem", O_RDWR);

    PageSize = sysconf(_SC_PAGESIZE);
    PageMask = (~(PageSize-1));

    addr_start = SW_PORTC_IO_BASE & PageMask;
    addr_offset = SW_PORTC_IO_BASE & ~PageMask;
    gpio_map = (volatile long int*)mmap(0, PageSize*2, PROT_READ|PROT_WRITE, MAP_SHARED, fd, addr_start);

    SUNXI_PIO_BASE = (unsigned int)gpio_map;
    SUNXI_PIO_BASE += addr_offset;

	addr_start = SW_PORTL_IO_BASE & PageMask;
    addr_offset = SW_PORTL_IO_BASE & ~PageMask;
	gpio_map = (volatile long int*)mmap(0, PageSize*2, PROT_READ|PROT_WRITE, MAP_SHARED, fd, addr_start);

    SUNXI_PIO_LM_BASE = (unsigned int)gpio_map;
    SUNXI_PIO_LM_BASE += addr_offset;

    close(fd);
}

void pinMode(int pin, int mode)
{
	pin=wPinToGpio[pin];
	unsigned int val = mode;
	unsigned int cfg;
    unsigned int bank = GPIO_BANK(pin);
    unsigned int index = GPIO_CFG_INDEX(pin);
    unsigned int offset = GPIO_CFG_OFFSET(pin);

    if(SUNXI_PIO_BASE == 0)
        return;

	struct sunxi_gpio *pio;
	if(bank>10)
		pio = &((struct sunxi_gpio_reg *)SUNXI_PIO_LM_BASE)->gpio_bank[bank-11];
	else
		pio = &((struct sunxi_gpio_reg *)SUNXI_PIO_BASE)->gpio_bank[bank];

    cfg = *(&pio->cfg[0] + index);
    cfg &= ~(0xf << offset);
    cfg |= val << offset;

    *(&pio->cfg[0] + index) = cfg;
}

void digitalWrite(int pin, int value)
{
	pin=wPinToGpio[pin];
	unsigned int val = value;
	unsigned int bank = GPIO_BANK(pin);
    unsigned int num = GPIO_NUM(pin);

    if(SUNXI_PIO_BASE == 0)
        return;

	struct sunxi_gpio *pio;
	if(bank>10)
		pio = &((struct sunxi_gpio_reg *)SUNXI_PIO_LM_BASE)->gpio_bank[bank-11];
	else
		pio = &((struct sunxi_gpio_reg *)SUNXI_PIO_BASE)->gpio_bank[bank];

    if(val)
        *(&pio->dat) |= 1 << num;
    else
        *(&pio->dat) &= ~(1 << num);
}

