/*  fork.c - Fork example

    Copyright (c) 2016 Monaco F. J. monaco@icmc.usp.br

    This file is part of Foobar.

    Foobar is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Foobar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main (int argc, char **argv)
{
  int count;
  printf ("Hello fork\n");
  int pid;
  int status, *p;

  pid = fork();

  if (pid>0)			/* Parent */
    {
      printf ("Luke, I am your father!\n");
      count=10;
      while (count--)
	{
	  printf ("P: %d \n", count);
	  sleep(2);
	}
      
      wait (&status);
      printf ("Child returned %s with %d\n", 
	      WIFEXITED (status) ? "normally" : "abnornally",
	      WEXITSTATUS(status));

      count=5;
      while (count--)
	{
	  printf ("La lalala... \n");
	  sleep(1);
	}

    }
  else				/* Child */
    {
      printf ("Noooooooo....\n");
      p = (int *) 10;
      *p = 20;
      count=10;
      while (count--)
	{
	  printf ("C: %d (daddy is %d) \n", count, getppid());
	  sleep(1);
	}
      return 17;
    }
  
  printf ("Done\n");

  return EXIT_SUCCESS;
}
