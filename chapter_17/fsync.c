#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
    int fd;
    int i;

    fd = open("test.txt",O_RDWR);
    if (fd == -1)
    {
        error("fail to open");
        exit(1);
    }

    i = 0;
    while (i < 10)
    {
        sleep(5);
        printf("hello\n");
        if (write(fd,"hello\n",6) == -1)
        {
            perror("fail to write");
            exit(1);
        }

        if (fsync(fd) == -1)
        {
            perror("fail to fsync");
            exit(1);
        }

        i++;
    }

    close(fd);
    return 0;
}