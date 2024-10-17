#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(){
    char str[5];
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for(int i = 0; i < 7; i++){
        str[i] = 'A';
    }
    printf("%d\n", strlen(str));
    printf("Str: %s\n", str); 
    
    exit(EXIT_SUCCESS);
}

