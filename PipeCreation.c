#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
    char *pipePath;
    pipePath = "chat";

    mkfifo(pipePath, 0666);

    return 0;
}