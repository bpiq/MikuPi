#include "MikuDuino.h"

int main()
{
  mikuPiSetup();
  setup();
  while(1)
    loop();
}