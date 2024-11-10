#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>


int x = 0;
pthread_mutex_t mutex;

void* sum(){
    for(int i = 0; i < 100; i++){
        pthread_mutex_lock(&mutex);
        x = x + 1;
        printf("i : %d Summation :  %d\n", i, x);
        pthread_mutex_unlock(&mutex);
    }
}
void* sub(){
    for(int i = 0; i < 100; i++){
        pthread_mutex_lock(&mutex);
        x = x - 1;
        printf("i : %d Subtraction :  %d\n", i, x);
        pthread_mutex_unlock(&mutex);
    }
}
void main(){
    pthread_mutex_init(&mutex, NULL);
    pthread_t t1, t2;

    pthread_create(&t1, NULL, sum, NULL);
    pthread_create(&t2, NULL, sub, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&mutex);
}

/* Output with mutex lock (operations are going parallely but no race condition)
i: 0 Summation  : x + 1 = 1
i: 1 Summation  : x + 1 = 2
j: 0 Subtraction: x - 1 = 1
j: 1 Subtraction: x - 1 = 0
j: 2 Subtraction: x - 1 = -1
j: 3 Subtraction: x - 1 = -2
j: 4 Subtraction: x - 1 = -3
j: 5 Subtraction: x - 1 = -4
j: 6 Subtraction: x - 1 = -5
j: 7 Subtraction: x - 1 = -6
j: 8 Subtraction: x - 1 = -7
j: 9 Subtraction: x - 1 = -8
i: 2 Summation  : x + 1 = -7
i: 3 Summation  : x + 1 = -6
i: 4 Summation  : x + 1 = -5
i: 5 Summation  : x + 1 = -4
i: 6 Summation  : x + 1 = -3
i: 7 Summation  : x + 1 = -2
i: 8 Summation  : x + 1 = -1
i: 9 Summation  : x + 1 = 0
*/

/* Output without mutex lock
i: 0 Summation  : x + 1 = 1
i: 1 Summation  : x + 1 = 2
i: 2 Summation  : x + 1 = 3
i: 3 Summation  : x + 1 = 4
i: 4 Summation  : x + 1 = 5
i: 5 Summation  : x + 1 = 6
i: 6 Summation  : x + 1 = 7
i: 7 Summation  : x + 1 = 8 
i: 8 Summation  : x + 1 = 8 // inconsistent data
i: 9 Summation  : x + 1 = 9
j: 0 Subtraction: x - 1 = 7
j: 1 Subtraction: x - 1 = 8
j: 2 Subtraction: x - 1 = 7
j: 3 Subtraction: x - 1 = 6
j: 4 Subtraction: x - 1 = 5
j: 5 Subtraction: x - 1 = 4
j: 6 Subtraction: x - 1 = 3
j: 7 Subtraction: x - 1 = 2
j: 8 Subtraction: x - 1 = 1
j: 9 Subtraction: x - 1 = 0
*/