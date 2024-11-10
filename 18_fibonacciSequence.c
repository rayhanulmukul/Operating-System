#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int n;
    printf("Enter the number of Fibnacci numbers: ");
    scanf("%d", &n);

    pid_t pid = fork();
    if(pid < 0){
        printf("Fork create failed");
    }
    else if(pid == 0){ // child
        int *fibonacci = malloc(sizeof(int) * n);
        if(fibonacci == NULL){
            printf("Failed to allocate memory");
            exit(1);
        }
        for(int i = 0; i < n; i++){
            if(i < 2){
                fibonacci[i] = i;
            }
            else fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
            printf("%d ", fibonacci[i]);
        }
        free(fibonacci);
    }
    else{ // parent
        wait(NULL);
        printf("\nParent thread wait for the child thread to finish.");
    }

    exit(0);
}