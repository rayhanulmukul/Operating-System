#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>

int balance = 100;

void *deposit() {
    for (int i = 1; i <= 100; i++) {
        usleep(3000);
        balance = balance + 1;
        printf("Deposit: %d\n", balance);
        usleep(1090);
    }
}

void *withdraw() {
    for (int i = 1; i <= 100; i++) {
        usleep(5500);
        balance = balance - 1;
        printf("Withdraw: %d\n", balance);
    }
}

void main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, deposit, NULL);
    pthread_create(&t2, NULL, withdraw, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    exit(EXIT_SUCCESS);
}