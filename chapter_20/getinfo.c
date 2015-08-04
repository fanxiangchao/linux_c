#include "common.h"

int get_load_avg()
{
    char line_buf[MAX];
    int fd;
    int n;
    int res = -1;

    if ((fd = open("/proc/loadavg",O_RDONLY)) == -1)
    {
        perror("fail to loadavg");
        return -1;
    }

    if ((n = read(fd,line_buf,MAX)) == -1)
    {
        perror("fail to loadavg");
        goto err;
    }

    line_buf[n] = '\0';
    printf("Average Load: %s",line_buf);
    res = 0;
err:
    close(fd);
    return res;
}

int search(char *path,char *name)
{
    int fd;
    char char_all[MAX] = "\0";
    char line_buf[MAX] = "\0";
    char *p;
    char *s;
    int n;
    int res = -1;

    if ((fd = open(path,O_RDONLY)) == -1)
    {
        perror("fail to open");
        return -1;
    }

    if ((n = read(fd,char_all,MAX)) == -1)
    {
        perror("fail to read");
        goto err;
    }

    char_all[n] = '\0';
    p = strstr(char_all,name);
    s = strstr(p,"\n");
    n = s - p + 1;

    strncpy(line_buf,p,n);
    printf("%s\n",line_buf);
    res = 0;

err:
    close(fd);
    return res;
}