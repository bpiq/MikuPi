#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef TRUE
#define       TRUE    (1==1)
#define       FALSE   (1==2)
#endif

int wiringPiDebug       = TRUE;

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
  if ((cpuFd = fopen ("/proc/cpuinfo", "r")) == NULL)
    piBoardRevOops ("Unable to open /proc/cpuinfo") ;
  while (fgets (line, 120, cpuFd) != NULL)
  {
    if (strncmp (line, "Hardware", 8) == 0)
      break;
  }
		
  fclose (cpuFd) ;
  if (strncmp (line, "Hardware", 8) != 0)
    piBoardRevOops ("No \"Hardware\" line") ;
	
  for (d = &line [strlen (line) - 1] ; (*d == '\n') || (*d == '\r') ; --d)
    *d = 0 ;
  if (wiringPiDebug)
    printf ("piboardRev: Hardware string: %s\n", line) ;
	
  if (strstr(line,"sun8i") != NULL)
  {
    if (wiringPiDebug)
      printf ("Hardware:%s\n",line) ;
    return TRUE;
  }
  else
  {
    if (wiringPiDebug)
      printf ("Hardware:%s\n",line) ;
    return FALSE;
  }
}

int main()
{
  printf("Hello MikuQ.com!\n");
  if (isH3())
    printf("is H3!\n");
  else
    printf("is not H3!\n");
  return 0;
}