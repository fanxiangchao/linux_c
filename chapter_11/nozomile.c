#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc,char *argv[])
{
    pid_t pid;
    pid = fork();
    if (pid < 0)
    {
        printf("fail to fork\n");
        exit(1);
    }else if (pid == 0)
    {
        printf("the child\n");
        pid = fork();
        if (pid < 0)
        {
            printf("fail to fork\n");
            exit(1);
        }else if (pid == 0)
        {
            printf("do something you want\n");
            sleep(5);
            printf("done\n");
            printf("parent pid : %u\n",getppid());
            exit(0);
        }else
        {
            exit(0);
        }
    }else
    {
        if (waitpid(pid,NULL,0) > 0)
        {
            printf("child exited\n");
        }
        sleep(10);
        printf("the parent\n");
    }

    return 0;
}