#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    int shmid = shmget(121, 1024, 0666 | IPC_CREAT);
    int *x = shmat(shmid, 0, 0);
    printf("%d\n", *x);
    shmctl(shmid, IPC_RMID, NULL);

    exit(EXIT_SUCCESS);
}