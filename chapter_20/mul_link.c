#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define MAX 1024

int main(int argc,char *argv[])
{
    int fd,n;
    char buf[MAX];

    if (symlink("test.txt","sl1") == -1)
    {
        perror("fail to create symbol link");
        exit(1);
    }

    if (symlink("sl1","sl2") == -1)
    {
        perror("fail to create symbol link");
        exit(1);
    }
    
    if ((fd = open("sl2",O_RDWR)) == -1)
    {
        perror("fail to open");
        exit(1);
    }

    if ((n = read(fd,buf,MAX)) == -1)
    {
        perror("fail to read");
        exit(1);
    }

    buf[n] = '\0';
    printf("file content is : %s\n",buf);

    strcat(buf,",root\n");

    if (write(fd,buf,strlen(buf)) == -1)
    {
        perror("fail to write");
        exit(1);
    }

    printf("done\n");
    close(fd);
    
    return 0;
}