#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define MAX 1024
#define PID 6
#define PATH_SIZE 128

int main(int argc,char *argv[])
{
    FILE *fp;
    pid_t pid;
    char pid_str[PID];
    char path[PATH_SIZE];
    char buf[MAX];

    pid = getpid();
    sprintf(pid_str,"%d",pid);
    strcpy(path,"/proc/self/task/");
    strcat(path,pid_str);
    strcat(path,"/status");

    fp = fopen(path,"r");

    if (fp == NULL)
    {
        perror("fail to open");
        exit(1);
    }

    while(fgets(buf,MAX,fp) != NULL)
    {
        printf("%s",buf);
    }

    fclose(fp);
    return 0;
}