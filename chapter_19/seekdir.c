#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char *argv[])
{
    DIR *dir;
    struct dirent *d_ptr;
    off_t offset;
    
    dir = opendir("/home/fanxiangchao");
    if (dir == NULL)
    {
        perror("fail to open dir");
        exit(1);
    }

    while((d_ptr = readdir(dir)) != NULL)
    {
        if (strcmp(d_ptr->d_name,"..") == 0)
        {
            offset = telldir(dir);
        }
    }
    
    seekdir(dir,offset);

    while((d_ptr = readdir(dir)) != NULL)
    {
        printf("dir name is : %s\n",d_ptr->d_name);
    }

    closedir(dir);

    return 0;
}