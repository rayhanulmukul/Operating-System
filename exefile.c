#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    execlp("./hello", "./hello", NULL);

    perror("execlp");
    exit(0);
}