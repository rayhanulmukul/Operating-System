#include <stdio.h>
#include <sched.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    // printf("ParentID: %d\n", getpid());
    // int cid1 = fork();
    // fork();
    // fork();
    // for(int i = 0; i < 1 ; i++){
    //     printf("ProcessID: %d, Parent PID: %d, Core ID: %d\n", getpid(), getppid(), sched_getcpu());
    // }

    int cores = sysconf(_SC_NPROCESSORS_ONLN);
    int processesToBeCreated = cores + 4;
    printf("%d\n", cores);

    for(int i = 1; i <= processesToBeCreated; i++){
        if (fork() == 0) {
            printf("%d: %d --- Core ID: %d\n", i, getpid(), sched_getcpu());
            exit(EXIT_SUCCESS);
        }
    }
    wait(NULL);
    
    exit(EXIT_SUCCESS);
}