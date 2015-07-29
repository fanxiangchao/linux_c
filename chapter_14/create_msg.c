#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

int main(int argc,char *argv[])
{
    int qid;
    key_t key;
    char cmd_buf[BUF_SIZE];
    key = 113;

    qid = msgget(key,IPC_CREAT | 0666);
    if (qid < 0)
    {
        perror("msgget");
        exit(1);
    }

    sprintf(cmd_buf,"ipcs -q | grep %d",qid);
    printf("created queue id : %d\n",qid);
    system(cmd_buf);
    exit(0);
}