#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX 1024

int main(int argc,char *argv[])
{
    int fd,n;
    char buf[MAX];

    if (symlink("test.txt","sl3") == -1)
    {
        perror("fail to create symbol link");
        exit(1);
    }

    if (symlink("sl3","sl4") == -1)
    {
        perror("fail to create symbol link");
        exit(1);
    }

    if ((n = readlink("sl3",buf,MAX)) == -1)
    {
        perror("fail to read symbol-link");
        exit(1);
    }

    buf[n] = '\0';

    printf("%s\n",buf);

    if ((n = readlink("sl4",buf,MAX)) == -1)
    {
        perror("fail to read symbol-link");
        exit(1);
    }

    buf[n] = '\0';

    printf("%s\n",buf);

    return 0;
}