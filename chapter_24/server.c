#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/select.h>
#include "iolib.h"

#define MAX_LINE 100
int port = 8000;

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

    int lfd;
    int cfd;
    int sfd;
    int rdy;
    int client[FD_SETSIZE];
    int maxi;
    int maxfd;
    fd_set rset;
    fd_set allset;
    socklen_t addr_len;
    char buf[MAX_LINE];
    char addr_p[INET_ADDRSTRLEN];
    int i;
    int n;
    int len;
    int opt = 1;

    bzero(&sin,sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(port);

    if ((lfd = socket(AF_INET,SOCK_STREAM,0)) == -1)
    {
        perror("fail to creat socket");
        exit(1);
    }

    setsockopt(lfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
    
    if (bind(lfd,(struct sockaddr *)&sin,sizeof(sin)) == -1)
    {
        perror("fail to bind");
        exit(1);
    }

    if (listen(lfd,10) == -1)
    {
        perror("fail to listen");
        exit(1);
    }

    printf("Accepting connections ...\n");

    maxfd = lfd;
    maxi = -1;

    for (i = 0; i < FD_SETSIZE; i++)
    {
        client[i] = -1;
    }

    FD_ZERO(&allset);
    FD_SET(lfd,&allset);
    
    while (1)
    {
        rset = allset;

        rdy = select(maxfd + 1,&rset,NULL,NULL,NULL);

        if (FD_ISSET(lfd,&rset))
        {
            printf("listen fd is readable, %d\n",rdy);
            addr_len = sizeof(cin);
            cfd = accept(lfd,(struct sockaddr *)&cin,&addr_len);
            if (cfd == -1)
            {
                perror("fail to accept");
                exit(1);
            }

            for (i = 0; i < FD_SETSIZE; i++)
            {
                if (client[i] < 0)
                {
                    client[i] = cfd;
                    break;
                }
            }

            if (i == FD_SETSIZE)
            {
                printf("too many clients\n");
                exit(1);
            }

            FD_SET(cfd,&allset);
            if (cfd > maxfd)
            {
                maxfd = cfd;
            }

            if (i > maxi)
            {
                maxi = i;
            }

            if (--rdy <= 0)
            {
                continue;
            }
        }

        for (i = 0; i <= maxi; i++)
        {
            if ((sfd = client[i]) < 0)
            {
                continue;
            }

            if (FD_ISSET(sfd,&rset))
            {
                n = my_read(sfd,buf,MAX_LINE);
                if (n == 0)
                {
                    printf("the othre side has been closed.\n");
                    fflush(stdout);
                    close(sfd);
                    FD_CLR(sfd,&allset);
                    client[i] = -1;
                }else
                {
                    inet_ntop(AF_INET,&cin.sin_addr,addr_p,sizeof(addr_p));
                    printf("client IP is %s, port is %d\n",addr_p,ntohs(cin.sin_port));
                    printf("content is : %s\n",buf);
                    my_fun(buf);
                    n = my_write(sfd,buf,n);
                    if (n == -1)
                    {
                        exit(1);
                    }
                }

                if (--rdy <= 0)
                {
                    break;
                }
            }
        }
        
    }

    close(lfd);
    return 0;
}