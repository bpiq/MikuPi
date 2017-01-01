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

#define       GB2312 (0)
#define       UTF8 (1)

#define	PI_MODEL_UNKNOWN	0
#define	PI_MODEL_M1		1
#define	PI_MODEL_R1		2
#define	PI_MODEL_M2		3
#define	PI_MODEL_M1p	4
#define PI_MODEL_M3     5
#define PI_MODEL_M2p    6
#define PI_MODEL_M2u    7

extern char *i2cDevice;
extern const int bPinTowPin[41];

#define	VERSION "0.31"

extern const char *piModelNames    [9] ;
extern const char *piModelFullNames [9];

void delay (unsigned int howLong);

int piCpuTemp(char *temp);
void piBoardId(int *model, int *mem);
void sayHello();

void mikuPiSetup (void);

void pinMode(int pin, int mode);
void digitalWrite(int pin,int value);

#define SW_PORTC_IO_BASE 0x01c20800
#define SW_PORTL_IO_BASE 0x01f02c00

extern unsigned int SUNXI_PIO_BASE;
extern unsigned int SUNXI_PIO_LM_BASE;

struct sunxi_gpio {
    unsigned int cfg[4];
    unsigned int dat;
    unsigned int drv[2];
    unsigned int pull[2];
};

struct sunxi_gpio_int {
    unsigned int cfg[3];
    unsigned int ctl;
    unsigned int sta;
    unsigned int deb;
};

struct sunxi_gpio_reg {
    struct sunxi_gpio gpio_bank[9];
    unsigned char res[0xbc];
    struct sunxi_gpio_int gpio_int;
};

#define GPIO_BANK(pin)	((pin) >> 5)
#define GPIO_NUM(pin)	((pin) & 0x1F)

#define GPIO_CFG_INDEX(pin)	(((pin) & 0x1F) >> 3)
#define GPIO_CFG_OFFSET(pin)	((((pin) & 0x1F) & 0x7) << 2)

#endif
