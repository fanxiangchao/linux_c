#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>

int main(int argc,char *argv[])
{
    char addr_p[16];
    struct in_addr addr_in;

    if (inet_pton(AF_INET,"192.168.11.6",&addr_in) == -1)
    {
        perror("fail to convert");
        exit(1);
    }

    printf("address : %x\n",addr_in.s_addr);

    if (inet_ntop(AF_INET,&addr_in,&addr_p,sizeof(addr_p)) == NULL)
    {
        perror("fail to convert");
        exit(1);
    }

    printf("address : %s\n",addr_p);
    return 0;
}