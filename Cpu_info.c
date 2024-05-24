#include <stdlib.h>
#include <sched.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#define _GNU_SOURCE

void get_cpu_info(char *processor_type, char *thread_type){
    int coreId, i;
    for(int i = 0; i < 10; i++){
        coreId = sched_getcpu();
        printf("%s, %s Core Id: %d\n", processor_type, thread_type, coreId);
    }
}
void sub_thread(char *processType){
    get_cpu_info(processType, "SubThread");
}
int main(){
    pid_t pid = fork();
    if(pid < 0){
        printf("Child Process Creation Error!!\n");
        exit(EXIT_FAILURE);
    }
    else if(pid == 0){
        pthread_t tid;
        pthread_create(&tid, NULL, (void *)sub_thread, "child");
        get_cpu_info("Child", "MainThread");
        pthread_join(tid, NULL);
    }
    else{
        pthread_t tid;
        pthread_create(&tid, NULL, (void *)sub_thread, "Parent");
        get_cpu_info("Child", "MainThread");
        pthread_join(tid, NULL);
        wait(NULL);
    } 


    // get_cpu_info("Parent");
    exit(EXIT_SUCCESS);
}