#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>

int main() {

    //create a unnamed pipe
    int fd[2];
    int pipeFlag = pipe(fd);
    if(pipeFlag == -1) {
        printf("Pipe creation failed\n");
        exit(EXIT_FAILURE);
    }
    else {
        printf("Pipe created successfully\n");
    }
    pid_t childPid = fork();
    if(childPid == -1) {
        printf("Fork failed\n");
        exit(EXIT_FAILURE);
    }
    else if(childPid == 0) {
        //child process
        close(fd[0]);
        char msg[] = "Do not wait for me";
        write(fd[1], msg, sizeof(msg));
        close(fd[1]);
        for(;;);
        exit(EXIT_SUCCESS);
    }
    else {
        //parent process
        close(fd[1]);
        char msg[100];
        read(fd[0], &msg, sizeof(msg));
        printf("Message from child process: %s\n", msg);
        if(strcmp(msg,"Do not wait for me")==0) {
            printf("Child process sent message to terminate parent process.\n");
            exit(EXIT_SUCCESS);
        }
        else {
            wait(NULL);
        }
        close(fd[0]);
    }

    exit(EXIT_SUCCESS);
}