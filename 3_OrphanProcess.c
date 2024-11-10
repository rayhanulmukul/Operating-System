#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    pid_t pid;
    pid = fork();
    if(pid < 0){
        printf("Fork Failed\n");
    }
    else if(pid == 0){ // child
        sleep(5);
        printf("\nI am child having is %d\n", getpid());
        printf("My parent pid is %d\n", getppid());
    }
    else if(pid > 0){ // parent
        printf("\nI am parent having pid %d\n", getpid());
        printf("My child pid is %d\n", pid);
    }
    printf("Common\n");

    exit(0);
}