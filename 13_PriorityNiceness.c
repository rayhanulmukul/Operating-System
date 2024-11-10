#include <sys/resource.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int coreNo, priority;

    coreNo = sched_getcpu();
    priority = getpriority(PRIO_PROCESS, 0);
    printf("%d, %d\n", coreNo, priority);

    nice(2);
    priority = getpriority(PRIO_PROCESS, 0);
    printf("%d, %d\n", coreNo, priority);


    nice(9);
    setpriority(PRIO_PROCESS, 0, 18);
    priority = getpriority(PRIO_PROCESS, 0);
    printf("%d, %d\n", coreNo, priority);
}