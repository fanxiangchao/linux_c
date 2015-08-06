#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_LINE 100

void my_fun(char *p)
{
    if (p == NULL)
    {
        return;
    }

    for (; *p != '\0';p++)
    {
        if (*p >= 'A' && *p <= 'Z')
        {
            *p = *p - 'A' + 'a';
        }
    }
}

int main(int argc,char *argv[])
{
    struct sockaddr_in sin;
    struct sockaddr_in cin;

    int l_fd;
    int c_fd;
    socklen_t len;
    char buf[MAX_LINE];
    char addr_p[INET_ADDRSTRLEN];
    int port = 8000;
    int n;

    bzero(&sin,sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(port);
    l_fd = socket(AF_INET,SOCK_STREAM,0);
    bind(l_fd,(struct sockaddr *)&sin,sizeof(sin));

    listen(l_fd,10);

    printf("waiting ...\n");
    while (1)
    {
        c_fd = accept(l_fd,(struct sockaddr *)&cin,&len);
        n = read(c_fd,buf,MAX_LINE);
        inet_ntop(AF_INET,&cin.sin_addr,addr_p,sizeof(addr_p));
        printf("client IP is %s, port is %d\n",addr_p,ntohs(cin.sin_port));
        printf("content is : %s\n",buf);
        my_fun(buf);

        write(c_fd,buf,n);
        close(c_fd);
    }

    return 0;
}