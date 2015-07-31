#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX 32

int main(int argc,char *argv[])
{
    int fd;
    int len;
    int rest;
    int i;
    off_t off;
    
    char buf[MAX];
    if (argc != 3)
    {
        len = MAX;
        rest = 0;
    }else
    {
        len = atoi(argv[1]);
        rest = atoi(argv[2]);
    }

    if (truncate("test.txt",len) == -1)
    {
        perror("fail to truncate");
        exit(1);
    }

    fd = open("test.txt",O_RDWR | O_APPEND);
    if (fd == -1)
    {
        perror("fail to open");
        exit(1);
    }

    off = lseek(fd,0,SEEK_CUR);
    printf("current offset is : %d\n",off);
    i = 0;
    while(i < rest)
    {
        buf[i] = '0';
        i++;
    }

    if (write(fd,buf,rest) == -1)
    {
        perror("fail to write");
        exit(1);
    }

    off = lseek(fd,0,SEEK_CUR);
    printf("current offset after write is : %d\n",off);
    
    close(fd);
    return 0;
}