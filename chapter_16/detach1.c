#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *tfn1(void *arg)
{
    printf("the thread,sleep\n");
    sleep(5);
    printf("the thread done\n");
    return NULL;
}

int main(int argc,char *argv[])
{
    int err;
    pthread_t tid;
    pthread_attr_t attr;

    err = pthread_create(&tid,&attr,tfn1,NULL);
    if (err != 0)
    {
        printf("can't create thread %s\n",strerror(err));
        exit(1);
    }

    sleep(1);
    err = pthread_detach(tid);
    if (err != 0)
    {
        printf("can't detach thread %s\n",strerror(err));
        exit(1);
    }
    
    err = pthread_join(tid,NULL);
    if (err != 0)
    {
        printf("thread has been detached\n");
    }

    sleep(5);
    printf("the main thread done\n");
    return 0;
}