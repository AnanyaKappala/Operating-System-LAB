/*Implement combination of multiple and multilevel process using for system call.*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
    int i,pid,j,k;
    for(i=0;i<2;i++){
        pid=fork();
        if(pid==-1){
            printf("Error:Failed to create child process\n");
            exit(0);
        }
        else if(pid==0){
            for(j-0;j<2;j++){
                pid=fork();
                if(pid==-1){
                    printf("Error:Failed to create child process\n");
                    exit(1);
                }
                else if(pid==0){
                    for(k=0;k<2;k++){
                        printf("Child process %d %d %d is running\n",i+1,j+1,k+1);
                    }
                    exit(0);
                }
            }
            for(j=0;j<2;j++){
                wait(NULL);
            }
            exit(0);
        }
    }
    for(i=0;i<2;i++){
        wait(NULL);
    }
    return 0;
}