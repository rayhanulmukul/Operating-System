#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int *shared_data;

int main(){
    int shmId = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    shared_data = (int *)shmat(shmId, NULL, 0);
    *shared_data = 42;
    printf("Value of shared_data: %d\n", *shared_data);
    if(shmdt(shared_data) == -1){
        printf("Error in detaching shared memory\n");
        exit(EXIT_FAILURE);
    }
    
    exit(EXIT_SUCCESS);
}