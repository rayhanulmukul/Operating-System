#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include<fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(){
    int pipId = open("chat", 0666);
    char buffer[100];
    char* user1 = "Mrinal : ";
    int sz;
    write(STDOUT_FILENO, user1, strlen(user1));
    read(STDIN_FILENO, &buffer, sizeof(buffer));
    write(pipId, buffer, strlen(buffer));


    read(pipId, &buffer, sizeof(buffer));
    write(STDOUT_FILENO, buffer, strlen(buffer));
    read(pipId, &buffer, sizeof(buffer));
    write(STDOUT_FILENO, buffer, strlen(buffer));

    exit(EXIT_SUCCESS);
}