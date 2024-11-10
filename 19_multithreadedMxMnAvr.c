#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int arr[50], n;
void *firstThread(){
    printf("Enter the input number : ");
    scanf("%d", &n);
    float sum = 0.0;
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    sum /= n;
    printf("The average value is %f\n", sum);

}
void *secondThread(){
    int mn = arr[0];
    for(int i = 1; i < n; i++){
        if(mn > arr[i]){
            mn = arr[i];
        }
    }
    printf("The minimum value is %d\n", mn);
}
void *thirdThread(){
    int mx = arr[0];
    for(int i = 1; i < n; i++){
        if(mx < arr[i]){
            mx = arr[i];
        }
    }
    printf("The maximum value is %d\n", mx);
}
int main(){
    pthread_t t1;
    pthread_create(&t1, NULL, &firstThread, NULL);
    pthread_join(t1, NULL);

    pthread_t t2;
    pthread_create(&t1, NULL, &secondThread, NULL);
    pthread_join(t1, NULL);

    pthread_t t3;
    pthread_create(&t1, NULL, &thirdThread, NULL);
    pthread_join(t1, NULL);

    exit(EXIT_SUCCESS);
}