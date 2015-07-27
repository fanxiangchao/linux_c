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
    }
    else if (pid == 0)
    {
        printf("the child\n");
        sleep(5);
        exit(0);
    }
    else
    {
        printf("the parent\n");
        if (waitpid(pid,NULL,WNOHANG) == 0)
        {
            printf("the child is not avaliable now\n");
        }
    }

    printf("no waiting,parent done\n");
    return 0;
}