#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h>
#include <unistd.h> 


int main(void)
{
  char *my_args[5];
  pid_t pid;
  
  my_args[0] = "child2";
  my_args[1] = "C2_a1";
  my_args[2] = "C2_a2";
  my_args[3] = NULL;
  
  puts ("child fork()ing");
  pid = fork();
  switch (pid)
  {
    case -1:
      /* Fork() has failed */
      perror ("fork");
      break;
    case 0:
      /* This is processed by the child */
      execv (my_args[0], my_args);
      puts("Uh oh! If this prints, execv() must have failed");
      exit(EXIT_FAILURE);
      break;
    default:
      /* This is processed by the parent */
      puts ("This is a message from child");
      break;
  }
  
  puts ("End of child program");
  return 0;
}

/*
 * Program output:
 fork()ing
 This is a message from the parent
 End of parent program
 I am the child
 Arg 1 arg1
 Arg 2 arg2
 *
 */
