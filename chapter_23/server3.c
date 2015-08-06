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

    int s_fd;
    socklen_t addr_len;
    char buf[MAX_LINE];
    char addr_p[INET_ADDRSTRLEN];
    int port = 8000;
    int n;

    bzero(&sin,sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(port);

    if ((s_fd = socket(AF_INET,SOCK_DGRAM,0)) == -1)
    {
        perror("fail to creat socket");
        exit(1);
    }
    
    if (bind(s_fd,(struct sockaddr *)&sin,sizeof(sin)) == -1)
    {
        perror("fail to bind");
        exit(1);
    }
    
    while (1)
    {
        addr_len = sizeof(sin);
        
        n = recvfrom(s_fd,buf,MAX_LINE,0,(struct sockaddr *)&cin,&addr_len);
        if (n == -1)
        {
            perror("fail to receive");
            exit(1);
        }
        
        inet_ntop(AF_INET,&cin.sin_addr,addr_p,sizeof(addr_p));
        printf("client IP is %s, port is %d\n",addr_p,ntohs(cin.sin_port));
        printf("content is : %s\n",buf);

        my_fun(buf);

        n = sendto(s_fd,buf,n,0,(struct sockaddr *)&cin,addr_len);
        if (n == -1)
        {
            perror("fail to send");
            exit(1);
        }
    }

    if (close(s_fd) == -1)
    {
        perror("fail to close");
        exit(1);
    }

    return 0;
}