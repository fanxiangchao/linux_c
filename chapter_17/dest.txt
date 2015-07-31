#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX 1024

int main(int argc,char *argv[])
{
    char buf[MAX];
    int in,out;
    int n;
    off_t off;
    
    if (argc != 3)
    {
        exit(1);
    }

    if ((in = open(argv[2],O_RDONLY)) == -1)
    {
        perror("fail to open");
        exit(1);
    }

    if ((out = open(argv[1],O_WRONLY | O_TRUNC | O_CREAT)) == -1)
    {
        perror("fail to open");
        exit(1);
    }

    while((n = read(in,buf,MAX)) > 0)
    {
        if (write(out,buf,n) != n)
        {
            perror("fail to write");
            exit(1);
        }
    }

    off = lseek(in,0,SEEK_CUR);
    printf("read file offset is : %d\n",off);
    off = lseek(out,0,SEEK_CUR);
    printf("write file offset is : %d\n",off);
    
    if (n < 0)
    {
        perror("fail to read");
        exit(1);
    }

    printf("copy done\n");
    close(in);
    close(out);
    return 0;
}