#include <stdio.h>
#include <stdlib.h>
#include <string.h>





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





int main()
{

  /*
  if (isH3())
    printf("is H3!\n");
  else
    printf("is not H3!\n");
	*/
  return 0;
}