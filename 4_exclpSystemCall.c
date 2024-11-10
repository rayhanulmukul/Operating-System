#include <stdio.h>
#include <unistd.h>

int main(){
    printf("This will be replaced by `ls` command.\n");
    execlp("ls", "ls", "-l", NULL);
    printf("\nThe statement wont print\n");
    
    return 0;
}