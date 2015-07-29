#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSZ 4096
#define CMDSZ 1024

struct msg
{
    long msg_types;
    char msg_buf[BUFSZ];
};

int main(int argc,char *argv[])
{
    long int qid;
    int len;
    struct msg pmsg;
    char cmd_buf[CMDSZ];
    
    if (argc != 2)
    {
        perror("USAGE: rcv_msg <queue ID>");
        exit(1);
    }

    qid = atoi(argv[1]);
    len = msgrcv(qid,&pmsg,BUFSZ,0,0);
    if (len > 0)
    {
        pmsg.msg_buf[len] = '\0';
        printf("reading queue id : %5ld\n",qid);
        printf("message type : %5ld\n",pmsg.msg_types);
        printf("message length : %d bytes\n",len);
        printf("message text : %s\n",pmsg.msg_buf);
    }else if (len == 0)
    {
        printf("have no message from queue %ld\n",qid);
    }else
    {
        perror("msgrcv");
        exit(1);
    }

    sprintf(cmd_buf,"ipcs -q | grep %d",qid);
    system(cmd_buf);
    exit(0);
}