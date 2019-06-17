#include <stdio.h>
#include <stdlib.h>
/*
singlesh.c
launch singularity as a login shell from directive in ~/.singleshrc
*/

int main()
{
  char buf[256],cmd[256];
  FILE *fp;
  char singleshrc[25] = ".singleshrc";  // rc filename
  char singularity[] = "/usr/local/bin/singularity"; // path to singularity executable

  fp = fopen(singleshrc, "r"); // read mode
 
  if (fp != NULL)
    {
      fscanf(fp,"%[^\n]", buf);

      fclose(fp);

      sprintf(cmd, "%s %s", singularity, buf);

      system(cmd);

      return 0;
    }
  else
    {
      return EXIT_FAILURE;
    }
}

