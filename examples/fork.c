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

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (int argc, char **argv)
{
  int count = 10;
  printf ("Hello fork\n");
  pid_t pid;
  int status;
  int *p;

  pid = fork();

  if (pid>0)			/* Parent */
    {
      printf ("Luke, I am your father (%d, son of %d)\n", getpid(), getppid());
      while (count--)
	{
	  printf ("P: %d (daddy=%d)\n", count, getppid());
	  sleep (2);
	}
      printf ("Waiting for child...\n");
      wait (&status);
      printf ("Child finished %s with %d\n", 
	      WIFEXITED (status) ? "normally" : "abnormally",
	      WEXITSTATUS(status));

      count = 5;
      while (count--)
	{
	  printf ("La lalal\n");
	  sleep (2);
	}

    }
  else				/* Child */
    {
      printf ("Noooooooooo... (pid=%d, son of %d)\n", getpid(), getppid());
      p=0;
      *p = 10;
      while (count--)
	{
	  printf ("C: %d (daddy=%d)\n", count, getppid());
	  sleep (1);
	}
      return 17;
    }


  return EXIT_SUCCESS;
}
