#ifndef _MIKUPI_H_
#define _MIKUPI_H_

#ifndef TRUE
#define       TRUE    (1==1)
#define       FALSE   (1==2)
#endif

//https://www.arduino.cc/en/Reference/Constants

#define       true    (1)
#define       false   (0)

#define       HIGH  (1)
#define       LOW   (0)

#define       INPUT		(0)
#define       INPUT_PULLUP	(2)
#define       OUTPUT	(1)


#define	PI_MODEL_UNKNOWN	0
#define	PI_MODEL_M1		1
#define	PI_MODEL_R1		2
#define	PI_MODEL_M2		3
#define	PI_MODEL_M1p	4
#define PI_MODEL_M3     5
#define PI_MODEL_M2p    6

#define	VERSION "0.21"

extern const char *piModelNames    [7] ;

void delay (unsigned int howLong);

void piBoardId(int *model, int *mem);
void sayhello();

void pinMode(int pin, int mode);
void digitalWrite(pin, value);

#endif
