#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>


/*
singlesh.c
launch singularity as a login shell from directive in /etc/singlesh.conf
format:
uid:the command line for singularity
*/

int main()
{
  #define BUFSIZE 256
  char buf[BUFSIZE],cmd[BUFSIZE],scmd[BUFSIZE],ch=':';
  char uid[16],u[16];
  int i, Flag;
  FILE *fp;
  char sconf[25] = "/etc/singlesh.conf";  // singlesh.conf filename
  char singularity[] =
    "/usr/local/bin/singularity";         // path to singularity executable

  sprintf(uid,"%d", getuid());

  cmd[0] = 0; // make unresovled command detectable
  fp = fopen(sconf, "r"); // open singlesh.conf in read mode
  if (fp != NULL)
    {
      while (fgets(buf, sizeof buf, fp) != NULL)
	{
	  // break line into uid, command
	  Flag = 0;
	  for(i = 0; i <= strlen(buf); i++)
	    {
	      u[i] = buf[i]; // build the uid string
	      if(buf[i] == ch)  // detect the seperator
		{
		  Flag++;       // found a uid command pair
		  u[i] = 0;     // terminate uid string
		  strcpy(cmd,buf + i + 1);  // copy rest of buffer to command
		  break;    	
		}
	    }
	  if(Flag == 0)  // bad conf file format
	    {
	      return EXIT_FAILURE;   // no colon
	    }
	  else
	    {
	   // if uid matches, execute the command
	      if(strcmp(uid,u) == 0)
		{
		  fclose(fp);
		  sprintf(scmd, "%s %s", singularity, cmd);
		  system(scmd);  // and off we go

		  return 0;
		}
	   
	    }
	} // ran out of conf file before uid match
    } // failed to open conf file
  return EXIT_FAILURE;
}
