#ifndef _MIKUOLED_H_
#define _MIKUOLED_H_

#include "MikuTypes.h"

#define OLED_BUFFER_LENGTH 1024

#define OLED_CMD_DISPLAYON			0xAF
#define OLED_CMD_DISPLAYOFF			0xAE
 
/*
//  Display Byte
//    0    E.g. D3 ->    1 \
//    1                  1  \ = 3 (0011)
//    2                  0  /
//    3                  0 /
//    4                  1 \
//    5                  0  \ = D (1101)
//    6                  1  /
//    7                  1 /
*/

#define OLED_CMD_LOWCOLUMN   	0x00  // 0x00 - 0x0F
#define OLED_CMD_HIGHCOLUMN  	0x10  // 0x10 - 0x17
#define OLED_CMD_STARTLINE		0x40

#define OLED_CMD_SEGREMAP			0xA0

#define OLED_CMD_SCANNORMAL		0xC0
#define OLED_CMD_SCANREMAP		0xC8

#define OLED_CMD_COMPIN				0xDA

#define OLED_CMD_CONTRAST			0x81

#define OLED_CMD_RESUMEDISPLAY	0xA4

#define OLED_CMD_NORMALDISPLAY	0xA6
#define OLED_CMD_INCERSEDISPLAY	0xA7

#define OLED_CMD_1306_ADDRESSMODE 0x20   
// 10xb - Page addressing mode (PAGESTART, LOWCOLUMN, HIGHCOLUMN)
// 00xb - Horizontal addressing mode
// 01xb - Vertical addressing mode
#define OLED_HORIZONTAL_ADDRESSING			0x00    // 00xb
#define OLED_VERTICAL_ADDRESSING				0x01    // 01xb
#define OLED_PAGE_ADDRESSING						0x02    // 10xb

#define OLED_CMD_COLUMNADDRESS 		0x21
#define OLED_CMD_PAGEADDRESS   		0x22
#define OLED_CMD_STARTPAGE     		0xB0    // B0 - B7 (i.e. page start)


#define OLED_CMD_DISPLAYCLOCK			0xD5
#define OLED_CMD_MULTIPLEXRATIO		0xA8
#define OLED_CMD_DISPLAYOFFSET		0xD3

#define OLED_CMD_SETVCOMDETECT 		0xDB

#define OLED_CMD_1106_PUMPVOLTAGE	0x30
#define OLED_CMD_1106_DCCONTROL		0xAD
#define	OLED_CMD_1306_CHARGEPUMP	0x8D

#define OLED_CMD_ACTIVATESCROLL 		0x2F
#define OLED_CMD_DEACTIVATESCROLL  	0x2E


class Miku_Oled {
 public:
  Miku_Oled();
  void begin();
  void shift();
  void display(void);
  void showLogo(void);
  void clearDisplay(void); 
  void showBMP(uint8*);
  void setPos(uint8,uint8);
  void drawPoint(uint8,uint8,uint8);
  void drawText(const char*);
 private:
  void oled_sendCommand(int);
  static uint8 buf[];
  uint8 *buffer;
  uint8 xpos,ypos;
};


#endif