#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sigusr1_handler(int signo)
{
    printf("catch SIGUSR1\n");
}

int main(int argc,char *argv[])
{
    struct sigaction act;
    act.sa_handler = sigusr1_handler;
    act.sa_flags = SA_RESETHAND;
    sigemptyset(&act.sa_mask);
    if (sigaction(SIGUSR1,&act,NULL) == -1)
    {
        perror("fail to set handler for SIGCHILD");
        exit(1);
    }

    printf("process begin\n");
    sleep(10);
    sleep(10);
    printf("done\n");
    return 0;
}