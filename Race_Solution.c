#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int x = 0;
pthread_mutex_t lock;
void sum(){
    for(int i = 1; i <= 100; i++){
        pthread_mutex_lock(&lock);
        x = x + 1;
        //pthread_mutex_unlock(&lock);
        printf("i : %d. After Addition: %d\n", i, x);
        pthread_mutex_unlock(&lock);
    }
}
void sub(){
    for(int i = 1; i <= 100; i++){
        pthread_mutex_lock(&lock);
        x = x - 1;
        //pthread_mutex_unlock(&lock);
        printf("j : %d. After Subtraction: %d\n", i, x);
        pthread_mutex_unlock(&lock);
    }
}
int main(){
    // // Following Functions are conventional functions
    // // Which are executed consecutively
    // sum();
    // sub();

    // Initialize mutex before using
    pthread_mutex_init(&lock, NULL);

    // To run sum() and sub() concurrently, we use threads
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, (void *)sum, NULL);
    pthread_create(&tid2, NULL, (void *)sub, NULL);

    // Wait termination of all threads before terminating main thread.
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    // To check if the threads are running concurrently
    printf("Main Thread will terminate now\n");

    exit(EXIT_SUCCESS);
}