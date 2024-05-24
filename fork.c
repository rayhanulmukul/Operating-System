#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;
    printf("Hello World!\n"); // Added newline for better formatting
    pid = fork(); // Create a new process
    
    //printf("pid of program is %d\n", getpid());


    if (pid < 0) {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        return 1; // Return an error code
    } else if (pid == 0) {
        // Child process
        printf("I am the child process, pid: %d\n", getpid());
    } else {
        // Parent process
        printf("I am the parent process, pid: %d\n", getpid());
        printf("Child's pid: %d\n", pid);
    }

    return 0;
}

