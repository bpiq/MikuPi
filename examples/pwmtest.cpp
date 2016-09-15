/*
 * pwmtest.cpp:
 *
 *	Welcome to MikuQ.com! MikuDuino for BananaPi 
 *	
 *     by MikuQ(i@mikuq.com) 2016-9-15
 *	
 * https://github.com/bpiq/MikuPi
 *
 */

#include <MikuDuino.h>
#include <MikuPWM.h>

MikuPWM pwm = MikuPWM();

uint8_t breathing_table[128] = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 8, 9, 10, 11, 11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 22, 23, 25, 26, 27, 29, 30, 32, 34, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53, 56, 58, 61, 63, 66, 68, 71, 74, 77, 80, 83, 86, 89, 92, 95, 98, 102, 105, 108, 112, 116, 119, 123, 126, 130, 134, 138, 142, 145, 149, 153, 157, 161, 165, 169, 173, 176, 180, 184, 188, 192, 195, 199, 203, 206, 210, 213, 216, 219, 223, 226, 228, 231, 234, 236, 239, 241, 243, 245, 247, 248, 250, 251, 252, 253, 254, 255, 255, 255
};

void setup() {
  printf("16 channel PWM test!\r\n");
  pwm.begin();
  pwm.setPWMFreq(1600);    
}

void loop() {
  int i,j;
  int x=1;
  int y=5;
  for(i=0;i<8;i++)
  {
    for(j=0;j<128;j+=x)
    {
      pwm.setPWM(i, 0, breathing_table[j]*15);
      pwm.setPWM(15-i, 0, breathing_table[j]*15);
      delay(y);
    }
    for(j=0;j<128;j+=x)
    {
      pwm.setPWM(i, 0, breathing_table[(128-x-j)]*15);
      pwm.setPWM(15-i, 0, breathing_table[(128-x-j)]*15);
      delay(y);
    }
  }
  for(i=6;i>=1;i--)
  {
    for(j=0;j<128;j+=x)
    {
      pwm.setPWM(i, 0, breathing_table[j]*15);
      pwm.setPWM(15-i, 0, breathing_table[j]*15);
      delay(y);
    }
    for(j=0;j<128;j+=x)
    {
      pwm.setPWM(i, 0, breathing_table[(128-x-j)]*15);
      pwm.setPWM(15-i, 0, breathing_table[(128-x-j)]*15);
      delay(y);
    }
  }}

