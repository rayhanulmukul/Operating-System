#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

#define num 64

void signalHandler(int sig){
    if(sig >= 1 && sig <= num){
        printf("Signal %d is caught!\n", sig);
    }
}
int main(){
    for(int sig = 1; sig <= num; sig++){
        if(signal(sig, signalHandler) == SIG_ERR){
            continue;
        }
        kill(getpid(), sig);
    }

    return 0;
}