#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char * argv[])
{
  char * ls_args[3] = { "ls", "-l", NULL} ;
  pid_t c_pid, pid;
  int status;
  c_pid = fork();
  if (c_pid == 0)
{
    printf("Child: executing ls\n");
    execvp( ls_args[0], ls_args);
    perror("execve failed");
  }
else if (c_pid > 0)
{
    if( (pid = wait(&status)) < 0)
{
      perror("wait");
      _exit(1);
    }
    printf("Parent: finished\n");
  }else
{
    perror("fork failed");
    _exit(1);
  }
  return 0; 
}