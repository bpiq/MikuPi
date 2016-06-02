#ifndef _GPIO_LIB_H_
#define _GPIO_LIB_H_

#define SW_PORTC_IO_BASE 0x01c20800
#define SW_PORTL_IO_BASE 0x01f02c00

#define SETUP_OK            0
#define SETUP_DEVMEM_FAIL   1
#define SETUP_MALLOC_FAIL   2
#define SETUP_MMAP_FAIL     3

#define HIGH    1
#define LOW     0

#define INPUT   0
#define OUTPUT  1
#define PER     2


struct sunxi_gpio {
    unsigned int cfg[4];
    unsigned int dat;
    unsigned int drv[2];
    unsigned int pull[2];
};

/* gpio interrupt control */
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

extern int sunxi_gpio_input(unsigned int pin);
extern int sunxi_gpio_init(void);
extern int sunxi_gpio_set_cfgpin(unsigned int pin, unsigned int val);
extern int sunxi_gpio_get_cfgpin(unsigned int pin);
extern int sunxi_gpio_output(unsigned int pin, unsigned int val);
extern void sunxi_gpio_cleanup(void);

extern unsigned int SUNXI_PIO_BASE;
extern unsigned int SUNXI_PIO_LM_BASE;
#endif
