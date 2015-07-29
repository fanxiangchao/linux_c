#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

int main(int argc,char *argv[])
{
    char cmd_buf[BUF_SIZE];
    int qid;

    if (argc != 2)
    {
        puts("USAGE: del_msg <queue ID>");
        exit(1);
    }

    qid = atoi(argv[1]);
    sprintf(cmd_buf,"ipcs -q | grep %d",qid);
    system(cmd_buf);
    if ((msgctl(qid,IPC_RMID,NULL)) < 0)
    {
        perror("msgctl");
        exit(1);
    }

    system(cmd_buf);
    printf("successfully removed %d queue\n",qid);
    exit(0);
}