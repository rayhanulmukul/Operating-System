#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    char *pipePath = "pipe3";  // Name of the pipe or pipe path
    int pipeFlag, fd;
    char buffer[100];

    // Check if the named pipe exists
    if (access(pipePath, F_OK) == 0) {
        printf("%s Pipe exists\n", pipePath);
    } else {
        // Create a named pipe
        pipeFlag = mkfifo(pipePath, 0666);
        if (pipeFlag == -1) {
            perror("Error creating pipe");
            return 1;
        } else {
            printf("Pipe created\n");
        }
    }

    // Open the named pipe for writing
    fd = open(pipePath, O_WRONLY);
    if (fd == -1) {
        perror("Error opening pipe for writing");
        return 1;
    }

    // Read input from keyboard
    printf("Enter data to write into the pipe (Ctrl+D to end):\n");
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        // Write data into the named pipe
        ssize_t bytesWritten = write(fd, buffer, strlen(buffer));
        if (bytesWritten == -1) {
            perror("Error writing to pipe");
            return 1;
        }
    }

    // Close the file descriptor
    close(fd);

    return 0;
}
