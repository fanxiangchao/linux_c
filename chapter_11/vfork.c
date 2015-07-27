#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int global;
int main(int argc,char *argv[])
{
    pid_t pid;
    int stack = 1;
    int *heap;
    heap = (int *)malloc(sizeof(int));
    *heap = 2;
    pid = vfork();
    if (pid < 0)
    {
        printf("fail to fork\n");
        exit(1);
    }
    else if (pid == 0)
    {
        global++;
        stack++;
        (*heap)++;
        printf("the child, data : %d,, stack : %d, heap : %d, heap address : %p\n",global,stack,*heap,heap);
        printf("child terminates\n");
        exit(0);
    }
    else
    {
        printf("the parent,data : %d, stack : %d, heap : %d, heap address : %p\n",global,stack,*heap,heap);
        printf("parent terminates\n");
        return 0;
    }
}