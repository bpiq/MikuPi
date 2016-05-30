#include "MikuDuino.h"

int i=0;

void setup()
{
  sayhello();
}

void loop()
{
  delay(5000);
  printf("%d\n",++i);
}

