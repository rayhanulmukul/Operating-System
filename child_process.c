#include <stdio.h>
#include <sched.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if(pid < 0){
        printf("Fork failed\n");
    }
    else if(pid == 0){
        execlp("ls", "ls", NULL);
        printf("Child process\n");
        exit(EXIT_FAILURE);
    }
    else{
        wait(NULL);
        printf("Child Process Finished\n");
    }
    
    exit(EXIT_SUCCESS);
}