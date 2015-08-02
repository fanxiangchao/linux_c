#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

#define MAX 1024

int get_file_count(char *root)
{
    DIR *dir;
    struct dirent *ptr;
    int total = 0;
    char path[MAX] = {0};
    int i;

    for (i = 0; i < MAX; i++)
    {
        path[i] = '\0';
    }
    
    dir = opendir(root);
    if (dir == NULL)
    {
        perror("fail to open dir");
        exit(1);
    }

    errno = 0;
    while ((ptr = readdir(dir)) != NULL)
    {
        if (strcmp(ptr->d_name,".") == 0 || strcmp(ptr->d_name,"..") == 0)
        {
            continue;
        }

        if (ptr->d_type == DT_DIR)
        {
            sprintf(path,"%s/%s",root,ptr->d_name);
            total += get_file_count(path);
        }

        if (ptr->d_type == DT_REG)
        {
            total++;
        }
    }

    if (errno != 0)
    {
        perror("fail to read dir");
        exit(1);
    }

    closedir(dir);
    return total;
}

int main(int argc,char *argv[])
{
    int total;
    if (argc != 2)
    {
        printf("wrong usage\n");
        exit(1);
    }

    total = get_file_count(argv[1]);
    printf("%s has %d files\n",argv[1],total);
    return 0;
}