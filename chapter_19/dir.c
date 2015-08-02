#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc,char *argv[])
{
    struct stat buf;
    if (stat("/home",&buf) == -1)
    {
        perror("fail to stat");
        exit(1);
    }

    if (!S_ISDIR(buf.st_mode))
    {
        printf("this is not a directory file\n");
        exit(1);
    }

    if (S_IRUSR & buf.st_mode)
    {
        printf("user can read the dir\n");
    }

    if (S_IWUSR & buf.st_mode)
    {
        printf("user can write the dir\n");
    }

    if (S_IXUSR & buf.st_mode)
    {
        printf("user can through the dir\n");
    }

    return 0;
}