#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <strings.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_LINE 100

int main(int argc,char *argv[])
{
    struct sockaddr_in sin;
    char buf[MAX_LINE];
    int sfd;
    int port = 8000;
    char *str = "test string";

    if (argc > 1)
    {
        str = argv[1];
    }

    bzero(&sin,sizeof(sin));
    sin.sin_family = AF_INET;
    inet_pton(AF_INET,"127.0.0.1",&sin.sin_addr);
    sin.sin_port = htons(port);

    sfd = socket(AF_INET,SOCK_STREAM,0);
    connect(sfd,(const struct sockaddr *)&sin,sizeof(sin));

    write(sfd,str,strlen(str) + 1);

    read(sfd,buf,MAX_LINE);
    printf("receive from server: %s\n",buf);

    close(sfd);

    return 0;
}