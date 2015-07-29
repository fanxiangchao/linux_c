#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>

#define BUFSZ PIPE_BUF

int main(int argc,char *argv[])
{
    int fd;
    int len;
    char buf[BUFSZ];
    mode_t mode = 0666;

    if ((fd = open("fifo2",O_RDONLY)) < 0)
    {
        perror("open");
        exit(1);
    }

    while((len = read(fd,buf,BUFSZ)) > 0)
    {
        printf("read_fifo read: %s",buf);
    }

    close(fd);
    exit(0);
}