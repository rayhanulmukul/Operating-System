#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    int shmid = shmget(121, 1024, 0777 | IPC_CREAT);
    int *x = shmat(shmid, 0, 0);
    *x = 10;
    sleep(10);
    shmctl(shmid, IPC_RMID, NULL);

    exit(EXIT_SUCCESS);
}