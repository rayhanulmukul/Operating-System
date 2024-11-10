#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    pid_t child_pid = fork();

    if(child_pid < 0){
        printf("Fork Failed\n");
        exit(EXIT_FAILURE);
    }
    else if(child_pid == 0){
        for(int i = 0; i < 500; i++){
            printf("Child Id %d\n", getpid());
            kill(getppid(), SIGKILL);
        }
    }
    else{
        wait(10);
        for(int i = 0; ; i++){
            printf("Parent Id %d\n", getppid());
            kill(getpid(), SIGKILL);
        }
        
    }
    exit(EXIT_SUCCESS); 
}
