#include <stdio.h>
#include <unistd.h>

int main(){
    int n = 4;
    for(int i = 0; i < n; i++){
        fork();
    }

    return 0;
}
