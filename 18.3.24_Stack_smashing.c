#include <stdio.h>
#include <stdlib.h>

void main(){
    char str1[4], str2[4];
    int i, len;
    strcpy(str1, "1234567890");
    printf("str1: %s\n", str1);
    len = strlen(str1);
    for(i = 0; i < len; i++){
        str2[i] = 42;
        printf("str2: %s\n", str2);
    }

    exit(EXIT_SUCCESS);
}