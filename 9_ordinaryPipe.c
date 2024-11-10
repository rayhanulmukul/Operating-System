#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(){
    int file[2];
    pipe(file);
    pid_t pid = fork();
    if(pid < 0){
        printf("Fork Failed");
        exit(EXIT_FAILURE);
    }
    if(pid == 0){
        char *msg = "Hello World!";
        write(file[1], msg, strlen(msg));
    }
    else{
        sleep(1);
        char buffer[200];
        int n = read(file[0], buffer, sizeof(buffer));
        buffer[n] = '\0';
        write(STDOUT_FILENO, buffer, strlen(buffer));
    }
    wait(NULL);

    exit(EXIT_SUCCESS);
}