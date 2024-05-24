#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
    FILE *file;
    char buffer[100];
    file = fopen("file.txt", "r");
    while(fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    return 0;
}