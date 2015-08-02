#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 1024

int main(int argc,char *argv[])
{
    char buf[MAX];

    if (getcwd(buf,MAX) == NULL)
    {
        perror("fail to get pwd");
        exit(1);
    }

    printf("%s\n",buf);

    if (system("cd ../") == -1)
    {
        perror("fail to exec");
        exit(1);
    }

    if (getcwd(buf,MAX) == NULL)
    {
        perror("fail to get pwd");
        exit(1);
    }

    printf("%s\n",buf);

    return 0;
}