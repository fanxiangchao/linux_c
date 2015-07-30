#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t tid;
typedef struct job *Job;

struct job
{
    pthread_t tid;
    Job next;
    int val;
};

struct timeval begintime;
pthread_mutex_t q_lock = PTHREAD_MUTEX_INITIALIZER;

int insert(Job head,int val,pthread_t tid)
{
    Job p,q;
    p = head;

    if (p != NULL)
    {
        while(p->next != NULL)
        {
            p = p->next;
        }
    }

    q = (Job)malloc(sizeof(struct job));
    if (q == NULL)
    {
        perror("fail to malloc");
        return -1;
    }

    q->next = NULL;
    q->val = val;
    q->tid = tid;
    
    if (p == NULL)
    {
        head = q;
        return 0;
    }

    p->next = q;
    return 0;
    
}

void get_job(Job head,Job task,int *count,pthread_t tid)
{
    Job p,q;
    q = head;
    p = q->next;
    while(p != NULL)
    {
        if (tid == p->tid)
        {
            q->next = p->next;
            p->next = NULL;
            while(task->next != NULL)
            {
                task = task->next;
            }

            task->next = p;
            p = q->next;
            (*count)++;
        }else
        {
            q = p;
            p = p->next;
        }
    }
}

int free_job(Job head)
{
    Job p,q;
    for (p = head; p != NULL;)
    {
        q = p;
        p = p->next;
        free(q);
    }

    return 0;
}

void print(Job head)
{
    Job p;
    for (p = head->next; p != NULL; p = p->next)
    {
        printf("thread %u: %d\n",(unsigned int)p->tid,p->val);
    }
}

void *tfn9(void *arg)
{
    long long count;
    Job task;
    Job p,q;
    task = (struct job *)malloc(sizeof(struct job));
    task->next = NULL;
    task->val = 0;
    task->tid = -1;
    pthread_t tid;
    struct timeval endtime;
    float elapsed_time;
    tid = pthread_self();
    count = 0;
    
    while(count < 100000000)
    {
        if (pthread_mutex_trylock(&q_lock) == 0)
        {
            q = (Job)arg;
            p = q->next;

            while(p != NULL)
            {
                if (tid == p->tid)
                {
                    count++;
                }
                p = p->next;
            }
            pthread_mutex_unlock(&q_lock);
        }
    }

    gettimeofday(&endtime,NULL);
    elapsed_time = 1000000 * (endtime.tv_sec - begintime.tv_sec) + endtime.tv_usec - begintime.tv_usec;
    elapsed_time /= 1000000;

    printf("This total used time is: %f seconds.\n",elapsed_time);
    return (void *)0;
}

int main(int argc,char *argv[])
{
    Job item;
    pthread_t tid1,tid2;
    int i,err;
    gettimeofday(&begintime,NULL);
    item = (struct job *)malloc(sizeof(struct job));

    item->next = NULL;
    item->val = 0;
    item->tid = -1;

    if ((err = pthread_create(&tid1,NULL,tfn9,item)) == -1)
    {
        printf("fail to create thread %s\n",strerror(err));
        exit(0);
    }

    if ((err = pthread_create(&tid2,NULL,tfn9,item)) == -1)
    {
        printf("fail to create thread %s\n",strerror(err));
        exit(0);
    }

    printf("=== the 1st put ===\n");

    pthread_mutex_lock(&q_lock);
    for (i = 0; i < 2; i++)
    {
        if (insert(item,i,tid1) == -1)
        {
            exit(1);
        }

        if (insert(item,i + 1,tid2) == -1)
        {
            exit(1);
        }
    }

    if (insert(item,10,tid1) == -1)
    {
        exit(1);
    }

    pthread_mutex_unlock(&q_lock);
    printf("=== the 2nd put ===\n");
    pthread_mutex_lock(&q_lock);
    if (insert(item,9,tid2) == -1)
    {
        exit(1);
    }

    pthread_mutex_unlock(&q_lock);

    err = pthread_join(tid1,NULL);
    if (err != 0)
    {
        printf("can't join thread %s\n",strerror(err));
        exit(1);
    }

    err = pthread_join(tid2,NULL);
    if (err != 0)
    {
        printf("can't join thread %s\n",strerror(err));
        exit(1);
    }

    printf("main thread done\n");
    if (item->next == NULL)
    {
        printf("No job in the queue\n");
    }

    free(item);
    return 0;
}