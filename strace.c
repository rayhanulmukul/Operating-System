#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void main(){
    pid_t pid = fork();
    int status;
    if(pid < 0){
        printf("Child Process Creation Error!!\n");
        exit(EXIT_FAILURE);
    }
    else if(pid == 0){
        printf("Child Process: %d\n", getpid());
        exit(EXIT_SUCCESS);
    }
    else{
        wait(NULL);
        printf("Parent Process Waiting for Child\n");

         //sleep(1000);
        // printf("Parent Process Exiting\n");
    }   

    exit(EXIT_SUCCESS); 
}