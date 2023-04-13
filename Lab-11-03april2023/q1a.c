#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
    int i,pid;
    for(i=0;i<5;i++){
        pid=fork();
        if(pid<0){
            printf("Fork fail\n");
            exit(1);
        }
        else if(pid==0){
            printf("Child %d with pid %d\n",i,getpid());
            exit(0);
        }
        else{
            printf("Parent with pid %d created child %d with pid %d\n",getpid(),i,pid);
        }
    }
    for(i=0;i<5;i++){
        wait(NULL);
    }
    return (0);
}