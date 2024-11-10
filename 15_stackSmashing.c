#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
    char str[5];
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    for(int i = 0; i < 6; i++){
        str[i] = 'A';
    }
    printf("%ld\n", strlen(str));
    printf("Str : %s\n", str);

    exit(EXIT_SUCCESS);
}