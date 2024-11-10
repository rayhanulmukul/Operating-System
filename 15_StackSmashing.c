#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
    char str1[5], str2[5];
    strcpy(str1, "1234567889");
    printf("Str1 : %s\n", str1);
    int len = strlen(str1);
    for(int i = 0; i < len; i++){
        str2[i] = 42;
        printf("Str2: %s\n", str2);
    }

    exit(EXIT_SUCCESS);
}