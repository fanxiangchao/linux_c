#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
    DIR *dir;
    struct dirent *d_ptr;
    long offset;
    dir = opendir("/home/fanxiangchao");

    if (dir == NULL)
    {
        perror("fail to open dir");
        exit(1);
    }

    while((d_ptr = readdir(dir)) != NULL)
    {
        offset = telldir(dir);

        if (offset == -1)
        {
            perror("fail to get offset");
            exit(1);
        }

        printf("dir name is : %s offset is : %ld\n",d_ptr->d_name,offset);
    }

    closedir(dir);

    return 0;
}