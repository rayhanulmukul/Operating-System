#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork Failed!\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        printf("Child Process.\n");
        //while (1);
        printf("Child Terminate.\n");
        exit(EXIT_SUCCESS);
    } else {
        printf("Parent Process.\n");
        sleep(10);
        printf("Parent Terminated.\n");
        wait(NULL);
    }

    exit(EXIT_SUCCESS);
}