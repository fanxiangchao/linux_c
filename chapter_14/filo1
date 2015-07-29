#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>

#define BUFSZ PIPE_BUF

int main(int argc,char *argv[])
{
    FILE *fp;
    char *cmd = "cat recat.c";
    char buf[BUFSZ];

    if ((fp = popen(cmd,"r")) == NULL)
    {
        perror("failed to popen");
        exit(1);
    }

    while((fgets(buf,BUFSZ,fp)) != NULL)
    {
        printf("%s",buf);
    }

    pclose(fp);
    exit(0);
}