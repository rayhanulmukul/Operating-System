#include <stdio.h>
#include <sched.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    printf("ParentID: %d\n", getpid());
    for(int i = 0; i < 4; i++){
        fork();
    }
    for(int i = 0;  ; i++){
        printf("ProcessID: %d, Parent PID: %d, Core ID: %d\n", getpid(), getppid(), sched_getcpu());
    }

    
    exit(EXIT_SUCCESS);
}