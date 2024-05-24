#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// #include <asm-generic/fcntl.h>
int main() {
    char *pipePath;
    int pipeFlag, fd;
    pipePath = "pipe3";  // Name of the pipe or pipe path
    if (access(pipePath, F_OK) == 0) {
        printf("%s Pipe exists\n", pipePath);
    } else {
        pipeFlag = mkfifo(pipePath, 0666);  // Create a pipe
        if (pipeFlag == -1) {
            perror("Error creating pipe");
            return 1;
        } else {
            printf("Pipe created\n");
            char *dataToWrite = "Hello, this is some data.\n";

            ssize_t bytesWritten =
                write(pipeFlag, dataToWrite, strlen(dataToWrite));
        }
    }
}
// Lab work
// 1.effect of wait() in child and parent processes
// 2.Check parent process of orphan process
// 3.Use execlp() system call to run a separate exe file as child process
// 4.Check how multi-threading helps us do our tasks parallely
//     a.global variable effect,loacl variable effect
//     b.thread_race problem
// 5.Study about system  call:exit(),wait(),open(),read(