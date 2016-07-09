#include "MikuDuino.h"

/*
 * MikuDuino.cpp:
 *
 *	Welcome to MikuQ.com! MikuDuino for BananaPi 
 *	
 *     by MikuQ(i@mikuq.com)
 *	
 * https://github.com/bpiq/MikuPi
 *
 */

int main(int argc,char *argv[])
{
  mikuPiSetup();
  setup(argc,argv);
  while(1)
    loop();
}
