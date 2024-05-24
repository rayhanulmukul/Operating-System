#include <sys/resource.h>

int main(){
    int coreNo, priority;

    coreNo = sched_getcpu();
    priority = getpriority(PRIO_PROCESS, 0);
    printf("Logicl Processor: %d, Priority: %d\n", coreNo, priority);

    nice(2);
    priority = getpriority(PRIO_PROCESS, 0);
    printf("Logicl Processor: %d, Priority: %d\n", coreNo, priority);

    nice(9);
    setpriority(PRIO_PROCESS, 0, 18);
    priority = getpriority(PRIO_PROCESS, 0);
    printf("Logicl Processor: %d, Priority: %d\n", coreNo, priority);

    return 0;
}