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

int lu_argc;
char **lu_argv;

int main(int argc,char *argv[])
{
  //by Small Lu(mo10), Sky Arrow's first son.
  lu_argc=argc;
  lu_argv=argv;

  mikuPiSetup();
  setup();
  while(1)
    loop();
}