#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

    pid_t pid;
    pid = fork();

    if(pid < 0){
        printf("Fork Failed\n");
    }
    else if(pid == 0){// Child Process
        printf("\nChild having id %d\n", getpid());
        printf("My parent's pid %d\n", getppid());
    }
    else if(pid > 0){// Parent Process
        wait(NULL);
        printf("\nI am Parent having id %d\n", getpid());
        printf("My child id %d\n", pid);
    }

    printf("Common\n");

    exit(0);
}