#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(){
    int arr[5];
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2};
    
    for(int i = 0; i < 8; i++){
        arr[i] = 8;
    }
    printf("%d\n", sizeof(arr));
    for(int i = 0; i < sizeof(arr); i++){
        printf("arr[%d]: %d\n", i, arr[i]);
    }
    
    exit(EXIT_SUCCESS);
}

