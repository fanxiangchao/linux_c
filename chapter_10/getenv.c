#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
    char *p;
    p = getenv("PATH");
    if (p == NULL)
    {
        perror("fail to get env");
        exit(1);
    }
    printf("$PATH is %s\n",p);
    return 0;
}