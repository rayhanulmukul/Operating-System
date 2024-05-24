#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int x = 5, y = 2; // Global variables
// int result = 0;
int sub(){
    int result = 0;
    for(int i = 0; i < 300; i++){
        result += x - y;
        printf("i: %d, %d - %d = %d\n",i+1, x, y, x - y);
    }
}
int sum(){
    int result;
    for(int i = 0; i < 300; i++){
        result += x + y;
        printf("i: %d, %d + %d = %d\n",i+1, x, y, x + y);
    }
}
int main(){
    //sum();
    //sub();
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, (void *)sum, NULL);
    pthread_create(&tid2, NULL, (void *)sub, NULL);
    printf("%lu, %lu", tid1, tid2);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);



    exit(EXIT_SUCCESS);
}