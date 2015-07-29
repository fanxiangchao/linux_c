#include <sys/sem.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

int main(int argc,char *argv[])
{
    int semid;
    int nsems = 1;
    int flags = 0666;
    char cmd_buf[BUF_SIZE];
    
    semid = semget(IPC_PRIVATE,nsems,flags);
    if (semid < 0)
    {
        perror("semget");
        exit(1);
    }

    printf("successfully created a semaphore : %d\n",semid);
    sprintf(cmd_buf,"ipcs -s | grep %d",semid);
    system(cmd_buf);

    if ((semctl(semid,0,IPC_RMID)) < 0)
    {
        perror("semctl");
        exit(1);
    }else
    {
        printf("semaphore removed\n");
        system(cmd_buf);
    }
    exit(0);
}