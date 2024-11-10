#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){
    int filename = open("file.txt", O_RDWR | O_CREAT, 0777);
    char *msg = "Operating System";
    write(filename, msg, strlen(msg));

    char buffer[200];
    int n = read(filename, &buffer, sizeof(buffer));
    buffer[n] = '\0';
    read(filename, *buffer, strlen(buffer));
    
    exit(EXIT_SUCCESS);
}