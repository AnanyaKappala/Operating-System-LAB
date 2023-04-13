/*Implement multiple process using fork system call. */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int n;
    pid_t pid;

    printf("Enter number of child processes to create: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        pid = fork();
        if (pid == 0) {
            printf("Child %d pid=%d ppid=%d\n", i+1, getpid(), getppid());
            exit(0);
        } else if (pid < 0) {
            printf("Fork failed.\n");
        }
    }

    for (int i = 0; i < n; i++) {
        wait(NULL);
    }

    return 0;
}