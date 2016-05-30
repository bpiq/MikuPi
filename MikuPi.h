#ifndef _MIKUPI_H_
#define _MIKUPI_H_

#ifndef TRUE
#define       TRUE    (1==1)
#define       FALSE   (1==2)
#endif

#define	PI_MODEL_UNKNOWN	0
#define	PI_MODEL_M1		1
#define	PI_MODEL_R1		2
#define	PI_MODEL_M2		3
#define	PI_MODEL_M1p	4
#define PI_MODEL_M3     5
#define PI_MODEL_M2p    6

#define	VERSION "0.20"

extern const char *piModelNames    [7] ;

void delay (unsigned int howLong);

void piBoardId(int *model, int *mem);
void sayhello();

#endif
