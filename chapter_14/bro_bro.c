#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/types.h>

#define BUFSZ PIPE_BUF

void err_quit(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc,char *argv[])
{
    int fd[2];
    char buf[BUFSZ];
    pid_t pid;
    int len;
    if (pipe(fd) < 0)
    {
        err_quit("pipe");
    }

    if ((pid = fork()) < 0)
    {
        err_quit("fork");
    }else if (pid  == 0)
    {
        close(fd[0]);
        write(fd[1],"hello brother!\n",15);
        exit(0);
    }

    if ((pid = fork()) < 0)
    {
        err_quit("fork");
    }else if (pid > 0)
    {
        close(fd[0]);
        close(fd[1]);
        exit(0);
    }else
    {
        close(fd[1]);
        len = read(fd[0],buf,BUFSZ);
        write(STDOUT_FILENO,buf,len);
        exit(0);
    }
}