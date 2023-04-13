/*Implement the following algorithm using c.
  S1: Start;
  S2: Declare the variables Pid,Pid1,Pid2.
  S3: Call for k() system to create process.
  S4: If unsuccessful exit.
  S5: If successful, print Pid [Use getpid()].
  S6: Print the Pid.
  S7: Stop.
  [Use hearderfile <unistd.h>]. */
//01
#include <stdio.h>
#include <unistd.h>

int main()
{
  pid_t pid, pid1, pid2;

  pid = fork();

  if (pid < 0)
  {
    printf("Error: fork failed\n");
    return 1;
  }
  else if (pid == 0)
  {
    pid1 = getpid();
    printf("Child process Pid: %d\n", pid1);
  }
  else
  {
    pid2 = getpid();
    printf("Parent process Pid: %d\n", pid2);
  }

  return 0;
}
//02
#include <stdio.h>
#include <unistd.h>
main()
{
  int pid, pid1, pid2;
  pid = fork();
  if (pid == -1)
  {
    printf("ERROR IN PROCESS CREATION \n");
    exit(1);
  }
  if (pid != 0)
  {
    pid1 = getpid();
    printf("\n the parent process ID is % d\n", pid1);
  }
  else
  {
    pid2 = getpid();
    printf("\n the child process ID is % d\n", pid2);
  }
}
//03
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
  int pid, pid1, pid2;
  pid = fork();
  if (pid == -1)
  {
    printf("ERROR IN PROCESS CREATION \n");
    exit(1);
  }
  if (pid != 0)
  {
    pid1 = getpid();
    printf("\n the parent process ID is %d", pid1);
  }
  else
  {
    pid2 = getpid();
    printf("\n the child process ID is %d", pid2);
  }
}
/* OUTPUT-03
the parent process ID is 18636
 the child process ID is 18637*/