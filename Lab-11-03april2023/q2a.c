#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
    pid_t pid;
    int i;
    if((pid=fork())<0){
        fprintf(stderr,"Error:Failed to fork first child\n");
        exit(EXIT_FAILURE);
    }
    else if(pid==0){
        printf("First child (pid=%d) created by parent (pid=%d)",getpid(),getpid());
        if((pid=fork())<0){
            fprintf(stderr,"Error:Failed to fork second child\n");
            exit(EXIT_FAILURE);
        }
        else if(pid==0){
            printf("Second child(pid=%d) created by first child (pid=%d)",getpid(),getpid());
            if((pid=fork())<0){
                fprintf(stderr,"Error:Failed to fork third child\n");
                exit(EXIT_FAILURE);
            }
            else if (pid==0){
                printf("Third child (pid=%d) created by second child (pid=%d)",getpid(),getpid());
                exit(EXIT_SUCCESS);
            }
            exit(EXIT_SUCCESS);
        }
        exit(EXIT_SUCCESS);
    }
    for(i=0;i<3;i++){
        wait(NULL);
    }
}