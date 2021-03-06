#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
    pid_t pid;
    pid = fork();
    if (pid < 0)
    {
        printf("fail to fork\n");
        exit(0);
    }else if (pid == 0)
    {
        printf("the child\n");
        sleep(5);
        exit(0);
    }else
    {
        printf("the parent\n");
        sleep(30);
        if (wait(NULL) == -1)
        {
            perror("fail to wait");
            exit(1);
        }

        printf("waited done\n");
        sleep(10);
    }

    return 0;
}