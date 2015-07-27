#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void timer_handler(int signo)
{
    if (signo == SIGALRM)
    {
        printf("the time is now\n");
        exit(0);
    }else
    {
        printf("unexpected signal\n");
    }
}

int main(int argc,char *argv[])
{
    if (signal(SIGALRM,timer_handler) == SIG_ERR)
    {
        perror("can't set handler for SIGALARM");
        exit(0);
    }

    alarm(1);
    while(1)
    {
        printf("too early\n");
    }

    printf("should not be heare,never\n");
    return 0;
}