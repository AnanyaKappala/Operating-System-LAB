/*Implement the following algorithm using c.
  S1: Start;
  S2: Declare the variables Pid,Pid1,Pid2.
  S3: Call for k() system to create process.
  S4: If unsuccessful exit.
  S5: If successful, print Pid [Use getpid()].
  S6: Print the Pid.
  S7: Stop.
  [Use hearderfile <unistd.h>]. */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pid, pid1, pid2;
    pid = fork();
    if (pid == -1) {
        printf("Error in creating child process");
        exit(0);
    } else if (pid == 0) {
        printf("Child process created with pid: %d and parent pid: %d \n", getpid(), getppid()); 
        pid1 = fork();
        
        if (pid1 == -1) {
            printf("Error in creating child process");
            exit(0);
        } else if (pid1 == 0) {
            printf("Child process created with pid: %d and parent pid: %d \n", getpid(), getppid());
            pid2 = fork();
            
            if (pid2 == -1) {
                printf("Error in creating child process");
                exit(0);
            } else if (pid2 == 0) {
                printf("Child process created with pid: %d and parent pid: %d \n", getpid(), getppid());
            } else {
                wait(NULL);
                printf("Child process with pid: %d terminated \n", pid2);
            }
        } else {
            wait(NULL);
            printf("Child process with pid: %d terminated \n", pid1);
        }
        
    } else {
        wait(NULL);
        printf("Child process with pid: %d terminated \n", pid);
        
        
    }
    return 0;
}
/*Child process created with pid: 19619 and parent pid: 19618 
  Child process created with pid: 19620 and parent pid: 19619 
  Child process created with pid: 19621 and parent pid: 19620 
  Child process with pid: 19621 terminated 
  Child process with pid: 19620 terminated 
  Child process with pid: 19619 terminated*/