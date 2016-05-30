#include "MikuDuino.h"

void sayhello()
{
  printf("Hello MikuDuino!\n");
}

void delay (unsigned int howLong)
{
  struct timespec sleeper, dummy ;

  sleeper.tv_sec  = (time_t)(howLong / 1000) ;
  sleeper.tv_nsec = (long)(howLong % 1000) * 1000000 ;

  nanosleep (&sleeper, &dummy) ;
}

int main()
{
  setup();
  while(1)
    loop();
}