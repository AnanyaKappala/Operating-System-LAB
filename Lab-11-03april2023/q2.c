/*Implement multi-level process using fork system call. */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int n;
    printf("Enter number of levels: ");
    scanf("%d", &n);

    pid_t pid;
    int i;
    for (i = 0; i < n; i++) {
        pid = fork();
        if (pid < 0) {
            fprintf(stderr, "fork failed\n");
            exit(1);
        } else if (pid == 0) {
            printf("Child %d pid=%d ppid=%d\n", i+1, getpid(), getppid());
        } else {
            wait(NULL);
            printf("Parent pid=%d\n", getpid());
            exit(0);
        }
    }

    return 0;
}

/*
Enter number of levels: 3
Child 1 pid=1234 ppid=1233
Child 2 pid=1235 ppid=1234
Child 3 pid=1236 ppid=1235
Parent pid=1236
Parent pid=1235
Parent pid=1234
*/