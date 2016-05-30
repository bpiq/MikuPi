#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

const char *piModelNames [7] =
{
  "Unknown",
  "BPI-M1",
  "BPI-R1",
  "BPI-M2",
  "BPI-M1+",
  "BPI-M3",
  "BPI-M2+",
} ;

int MikuPiDebug       = TRUE;

static void piBoardRevOops (const char *why)
{
  fprintf (stderr, "piBoardRev: Unable to determine board revision from /proc/cpuinfo\n") ;
  fprintf (stderr, " -> %s\n", why) ;
  fprintf (stderr, " ->  You may want to check:\n") ;
  fprintf (stderr, " ->  http://MikuQ.com\n") ; 
  exit (EXIT_FAILURE) ;
}

int isH3(void)
{
  FILE *cpuFd ;
  char line [120] ;
  char *d;
  int processorCount=0;

  if ((cpuFd = fopen ("/proc/cpuinfo", "r")) == NULL)
    piBoardRevOops ("Unable to open /proc/cpuinfo") ;
  while (fgets (line, 120, cpuFd) != NULL)
  {
	if (strncmp (line, "processor", 9) == 0)
      processorCount++;
    if (strncmp (line, "Hardware", 8) == 0)
      break;
  }
		
  fclose (cpuFd) ;
  if (strncmp (line, "Hardware", 8) != 0)
    piBoardRevOops ("No \"Hardware\" line") ;
	
  for (d = &line [strlen (line) - 1] ; (*d == '\n') || (*d == '\r') ; --d)
    *d = 0 ;
  if (MikuPiDebug)
    printf ("piboardRev: Hardware string: %s\n", line) ;
	
  if (strstr(line,"sun8i") != NULL)
  {
	  if (processorCount==4)
	  {
		  //H3-M2P
	  }
	  if (processorCount==8)
	  {
		  //A83T-M3
	  }
    if (MikuPiDebug)
	{
      printf ("Hardware:%s\n",line) ;
      printf ("processorCount:%d\n",processorCount) ;
	}
    return TRUE;
  }
  else
  {
    if (MikuPiDebug)
      printf ("Hardware:%s\n",line) ;
    return FALSE;
  }
}



void piBoardId(int *model, int *mem)
{
  FILE *cpuFd ;
  char line [120] ;
  char *d;

  int processorCount=0;

  if ((cpuFd = fopen ("/proc/cpuinfo", "r")) == NULL)
    piBoardRevOops ("Unable to open /proc/cpuinfo") ;
  while (fgets (line, 120, cpuFd) != NULL)
  {
	if (strncmp (line, "processor", 9) == 0)
      processorCount++;
    if (strncmp (line, "Hardware", 8) == 0)
      break;
  }
		
  fclose (cpuFd) ;
  if (strncmp (line, "Hardware", 8) != 0)
    piBoardRevOops ("No \"Hardware\" line") ;
	
  for (d = &line [strlen (line) - 1] ; (*d == '\n') || (*d == '\r') ; --d)
    *d = 0 ;
  if (MikuPiDebug)
    printf ("piboardRev: Hardware string: %s\n", line) ;
	
  if (strstr(line,"sun8i") != NULL)
  {
	  if (processorCount==4)
	  {
		  //H3-M2p
		  *model = PI_MODEL_M2p;
		  *mem = 1024;
	  }
	  if (processorCount==8)
	  {
		  //A83T-M3
		  *model = PI_MODEL_M3;
		  *mem = 2048;
	  }
    if (MikuPiDebug)
	{
      printf ("Hardware:%s\n",line) ;
      printf ("processorCount:%d\n",processorCount) ;
	}
  }
  else if (strstr(line,"sun7i") != NULL)
  {
	      *model = PI_MODEL_M1;
		  *mem = 1024;
  }
  else if (strstr(line,"sun6i") != NULL)
  {
	      *model = PI_MODEL_M2;
		  *mem = 1024;
  }
  else
  {
	  	  *model = PI_MODEL_UNKNOWN;
		  *mem = 0;
    if (MikuPiDebug)
      printf ("Hardware:%s\n",line) ;
  }
}


int main()
{
  int model, mem;
  printf("Hello MikuQ.com!\n");
  piBoardId (&model, &mem);

    if (model == PI_MODEL_UNKNOWN)
    {
      printf ("Your Pi has an unknown model type. Please report this to\n") ;
      printf ("    i@mikuq.com\n") ;
      printf ("with a copy of your /proc/cpuinfo if possible\n") ;
    }
    else
    {
      printf ("BananaPi Details:\n") ;
      printf ("  Type: %s, Memory: %dMB\n", 
	  piModelNames [model], mem) ;
    }
  /*
  if (isH3())
    printf("is H3!\n");
  else
    printf("is not H3!\n");
	*/
  return 0;
}