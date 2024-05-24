#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PIPE_PATH "my_pipe"

int main() {
    int pipe_fd[2];
    pid_t pid;
    char buffer[100];

    // Create a named pipe
    if (mkfifo(PIPE_PATH, 0666) == -1) {
        perror("Error creating named pipe");
        return 1;
    }

    // Open the named pipe for writing
    pipe_fd[1] = open(PIPE_PATH, O_WRONLY);
    if (pipe_fd[1] == -1) {
        perror("Error opening named pipe for writing");
        return 1;
    }

    // Fork a child process
    pid = fork();
    if (pid < 0) {
        perror("Error forking child process");
        return 1;
    } else if (pid == 0) {  // Child process
        char *dataToWrite = "Hello, this is the child process writing.\n";
        // Write data into the named pipe
        ssize_t bytesWritten = write(pipe_fd[1], dataToWrite, strlen(dataToWrite));
        if (bytesWritten == -1) {
            perror("Error writing to named pipe");
            return 1;
        }
        close(pipe_fd[1]);  // Close the write end of the pipe in the child process
        exit(0);
    } else {  // Parent process
        // Open the named pipe for reading
        pipe_fd[0] = open(PIPE_PATH, O_RDONLY);
        if (pipe_fd[0] == -1) {
            perror("Error opening named pipe for reading");
            return 1;
        }

        // Read data from the named pipe and display it
        ssize_t bytesRead = read(pipe_fd[0], buffer, sizeof(buffer));
        if (bytesRead == -1) {
            perror("Error reading from named pipe");
            return 1;
        }
        printf("Parent process received: %s", buffer);

        // Close the read end of the pipe in the parent process
        close(pipe_fd[0]);
    }

    return 0;
}
