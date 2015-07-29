#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * thfn(void *arg)
{
    pid_t pid;
    pthread_t tid;
    pid = getpid();
    tid = pthread_self();

    printf("the new thread: pid is %u, tid is : %u\n",(unsigned int)pid,(unsigned int)tid);
    return NULL;
}

int main(int argc,char *argv)
{
    pid_t pid;
    int err;
    pthread_t tid,mtid;
    pid = getpid();
    mtid = pthread_self();
    err = pthread_create(&mtid,NULL,thfn,NULL);

    if (err != 0)
    {
        printf("can't create thread %d\n",strerror(err));
        exit(1);
    }

    sleep(2);
    printf("the main thread: pid is: %u, tid is: %u\n",(unsigned int)pid,(unsigned int)mtid);
    return 0;
}