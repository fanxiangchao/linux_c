#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc,char *argv[])
{
    int fd;
    char *p = "hello world\n";

    if (chdir("../") == -1)
    {
        perror("fail to change dir");
        exit(1);
    }

    printf("change dir successfully\n");
    if ((fd = open("test.txt",O_CREAT | O_RDWR)) == -1)
    {
        perror("fail to open");
        exit(1);
    }

    if (write(fd,p,strlen(p)) == -1)
    {
        perror("fail to write");
        exit(1);
    }

    close(fd);

    return 0;
}