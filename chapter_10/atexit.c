#include <stdlib.h>
#include <stdio.h>

void f1(void)
{
    printf("the first exit handler\n");
}

void f2(void)
{
    printf("the second exit handler\n");
}

int main(void)
{
    if (atexit(f1) != 0)
    {
        perror("fail to set exit handler\n");
        exit(1);
    }

    if (atexit(f1) != 0)
    {
        perror("fail to set exit handler\n");
        exit(1);
    }

    if (atexit(f2) != 0)
    {
        perror("falil to set exit handler\n");
        exit(1);
    }

    return 0;
}