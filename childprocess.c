#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t child_pid, myPID;
    child_pid = fork();
    if(child_pid < 0){
        printf("Child process failed\n");
    }
    else if(child_pid == 0){
        myPID = getpid();
        while(1){
            printf("ChildPID: %d & MyPID: %d\n", child_pid, myPID);
        }
    }
    else{
        myPID = getpid();
        for(int i = 0; i < 2000; i++){
            printf("ParentPID: %d & MyPID: %d\n", myPID, child_pid); 
            wait(NULL);
        }
    }

    exit(0);
}