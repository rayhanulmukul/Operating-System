void signal_handler(int signo){
    printf("Signal Handler: %d\n", signo);
    //kill(getpid(), SIGKILL);
}

int main(){
    int i;
    pid_t pid;
    pid = getpid();

    signal(SIGTERM, signal_handler);
    for(i = 1; i < 10000000; i++){
        printf("%d, PID: %d\n", i, pid);
    }
}

// Chat Box signal handler example