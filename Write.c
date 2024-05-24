#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
    char *msg;
    char buffer[100];
    msg = "Write a Message : ";
    write(STDIN_FILENO, msg, strlen(msg));
    int sz = read(STDIN_FILENO, &buffer, sizeof(buffer));
    buffer[sz] = '\n';
    int pipId = open("chat", 0666);
    write(pipId, buffer, strlen(buffer));
    
    exit(EXIT_SUCCESS);
    
}
