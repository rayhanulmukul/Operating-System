#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define NUM 64

void signal_handler(int sig) {
    if (sig >= 1 && sig <= NUM) {
        printf("Signal %d is caught!\n", sig);
    }
}

int main() {
    for (int sig = 1; sig <= NUM; sig++) {
        if (signal(sig, signal_handler) == SIG_ERR) continue;
        kill(getpid(), sig);
    }  

    return 0;
}