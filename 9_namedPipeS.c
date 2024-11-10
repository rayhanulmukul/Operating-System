#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>

int main(){
    char *filepath = "./path";
    mkfifo(filepath, 0666);
    int file = open(filepath, O_WRONLY);

    char *msg = "Hello World!";
    int val = write(file, msg, strlen(msg));
    sleep(15);

    exit(0);
}