#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc,char *argv[])
{
    struct stat statbuf;
    printf("before changing\n");

    if (stat("test.txt",&statbuf) == -1)
    {
        perror("fail to get status");
        exit(1);
    }

    printf("the owner of test.txt is : %u\n",(unsigned int)statbuf.st_uid);
    printf("the group of test.txt is : %u\n",(unsigned int)statbuf.st_gid);

    if (lstat("sl1",&statbuf) == -1)
    {
        perror("fail to get status");
        exit(1);
    }

    printf("the owner of sl1 is : %u\n",(unsigned int)statbuf.st_uid);
    printf("the group of sl1 is : %u\n",(unsigned int)statbuf.st_gid);

    if (lchown("sl1",1000,-1) == -1)
    {
        perror("fail to change owner");
        exit(1);
    }

    printf("after changing\n");

    if (stat("test.txt",&statbuf) == -1)
    {
        perror("fail to get status");
        exit(1);
    }

    printf("the owner of test.txt is : %u\n",(unsigned int)statbuf.st_uid);
    printf("the group of test.txt is : %u\n",(unsigned int)statbuf.st_gid);

    if (lstat("sl1",&statbuf) == -1)
    {
        perror("fail to get status");
        exit(1);
    }

    printf("the owner of sl1 is : %u\n",(unsigned int)statbuf.st_uid);
    printf("the group of sl1 is : %u\n",(unsigned int)statbuf.st_gid);

    return 0;
}