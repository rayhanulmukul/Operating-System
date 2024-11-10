#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

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
        printf("\nI am Parent having id %d\n", getpid());
        printf("My child id %d\n", pid);
    }

    printf("Common\n");

    /* fork();
    fork();
    fork();
    printf("Process ID is %d\n", getpid()); */

    exit(0);
}