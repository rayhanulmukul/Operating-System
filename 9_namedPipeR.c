#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    char *filepath = "./path";
    int file = open(filepath, O_WRONLY);

    char buffer[200];
    int n = read(file, buffer, sizeof(buffer));
    buffer[n] = '\0';
    printf("%s\n", buffer);

    exit(0);
}