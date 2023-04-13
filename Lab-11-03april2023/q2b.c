#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void create_processes(int n) {
    int i;
    pid_t pid, child_pid;

    for (i = 1; i <= n; i++) {
        pid = fork();
        if (pid < 0) {
            fprintf(stderr, "fork failed\n");
            exit(1);
        } else if (pid == 0) {
            printf("Child %d pid=%d ppid=%d\n", i, getpid(), getppid());
            if (i < n) {
                create_processes(n-i);
            }
            exit(0);
        }
    }

    for (i = 1; i <= n; i++) {
        child_pid = waitpid(-1, NULL, 0);
        if (child_pid < 0) {
            fprintf(stderr, "waitpid failed\n");
            exit(1);
        }
    }
}

int main() {
    int n;
    printf("Enter number of levels: ");
    scanf("%d", &n);

    create_processes(n);

    return 0;
}
/*
Enter number of levels: 3
Child 1 pid=1001 ppid=1000
Child 2 pid=1002 ppid=1001
Child 3 pid=1003 ppid=1002
Child 4 pid=1004 ppid=1003
Child 5 pid=1005 ppid=1004
Child 6 pid=1006 ppid=1005
*/