#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <strings.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define MAX_LINE 100

int main(int argc,char *argv[])
{
    struct sockaddr_in sin;
    struct sockaddr_in cin;
    char buf[MAX_LINE];
    int s_fd;
    int port = 8000;
    int n;
    socklen_t addr_len;
    
    bzero(&sin,sizeof(sin));
    sin.sin_family = AF_INET;
    inet_pton(AF_INET,"127.0.0.1",&sin.sin_addr);
    sin.sin_port = htons(port);

    if ((s_fd = socket(AF_INET,SOCK_DGRAM,0)) == -1)
    {
        perror("fail to creat socket");
        exit(1);
    }

    if (fgets(buf,MAX_LINE,stdin) == NULL)
    {
        perror("fail to get a line");
        exit(1);
    }
    
    n = sendto(s_fd,buf,strlen(buf) + 1,0,(struct sockaddr *)&sin,sizeof(sin));

    if (n == -1)
    {
        perror("fail to send\n");
        exit(1);
    }

    addr_len = sizeof(cin);
    n = recvfrom(s_fd,buf,MAX_LINE,0,(struct sockaddr *)&cin,&addr_len);
    if (n == -1)
    {
        perror("fail to receive\n");
        exit(1);
    }else
    {
        printf("receive from server: %s\n",buf);
    }

    if (close(s_fd) == -1)
    {
        perror("fail to close");
        exit(1);
    }

    return 0;
}