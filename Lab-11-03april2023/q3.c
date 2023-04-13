/*Implement combination of multiple and multilevel process using for system call.*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int num_levels, num_children;
    printf("Enter number of levels in the process tree: ");
    scanf("%d", &num_levels);
    printf("Enter number of child processes at each level: ");
    scanf("%d", &num_children);

    pid_t pid, wpid;
    int status;

    for (int level = 0; level < num_levels; level++) {
        printf("Level %d:\n", level+1);
        for (int i = 0; i < num_children; i++) {
            pid = fork();
            if (pid == -1) {
                perror("fork failed");
                exit(EXIT_FAILURE);
            } else if (pid == 0) {
                printf("Child %d pid=%d ppid=%d\n", i+1, getpid(), getppid());
                exit(EXIT_SUCCESS);
            }
        }
        while ((wpid = wait(&status)) > 0);
    }

    return 0;
}