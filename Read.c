#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(){
    int pipId = open("chat", 0666);
    if(pipId < 0){
        printf("Pipe open failed");
        exit(EXIT_FAILURE);
    }
    char buffer[100];
    int n = read(pipId, &buffer, sizeof(buffer));
    buffer[n] = '\0';
    write(STDOUT_FILENO, buffer, strlen(buffer));

    char *msg;
    char buffer1[100];
    msg = "Write a Message : ";
    write(STDIN_FILENO, msg, strlen(msg));
    int sz = read(STDIN_FILENO, &buffer1, sizeof(buffer1));
    buffer1[sz] = '\n';
    int pipId1 = open("chat", 0666);
    write(pipId1, buffer1, strlen(buffer1));

    close(pipId);
    exit(EXIT_SUCCESS);
}