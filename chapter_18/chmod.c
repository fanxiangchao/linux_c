#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc,char *argv[])
{
    struct stat statbuf;

    if (stat("test10.txt",&statbuf) == -1)
    {
        perror("fail to get status");
        exit(1);
    }

    printf("before changing owner\n");
    printf("the owner of test10.txt is : %d\n",(unsigned int)statbuf.st_uid);
    printf("the group of test10.txt is : %d\n",(unsigned int)statbuf.st_gid);
    printf("\n");

    if (chown("test10.txt",0,-1) == -1)
    {
        perror("fail to change owner");
        exit(1);
    }

    if (stat("test10.txt",&statbuf) == -1)
    {
        perror("fail to get status");
        exit(1);
    }

    printf("after changing owner\n");
    printf("the owner of test10.txt is : %d\n",(unsigned int)statbuf.st_uid);
    printf("the group of test10.txt is : %d\n",(unsigned int)statbuf.st_gid);
    printf("\n");

    if (chown("test10.txt",100,-1))
    {
        perror("fail to change owner");
        exit(1);
    }

    if (stat("test10.txt",&statbuf) == -1)
    {
        perror("fail to get status");
        exit(1);
    }

    printf("nonexist owner\n");
    printf("the owner of test10.txt is : %d\n",(unsigned int)statbuf.st_uid);
    printf("the group of test10.txt is : %d\n",(unsigned int)statbuf.st_gid);
    printf("\n");

    return 0;
}