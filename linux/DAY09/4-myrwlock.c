#include<stdio.h>
#include<pthread.h>
#include<unistd.h>


int x = 0;

pthread_rwlock_t myrwlock;

//读线程
void *read_thread(void *args)
{
    printf("---%lu read_thread ready\n",pthread_self());//lu:无符号长整型
    while (1)
    {
        sleep(1);
        pthread_rwlock_rdlock(&myrwlock);
        printf("read_thread:%lu,x=%d\n",pthread_self(),x);
        sleep(1);
        pthread_rwlock_unlock(&myrwlock);
    }
    return NULL;
}

//写线程
void * write_thread(void *args)
{
    printf("---%lu write_thread ready\n",pthread_self());
    while (1)
    {
        sleep(1);
        pthread_rwlock_wrlock(&myrwlock);
        ++x;
        printf("write_thread:%lu,x=%d\n",pthread_self(),x);
        sleep(1);
        pthread_rwlock_unlock(&myrwlock);
        
    }
    return NULL;
}

int main()
{
    pthread_rwlock_init(&myrwlock,NULL);

    pthread_t readThread[3];//3个读线程
    for (int i = 0; i < 3; i++)
    {
        pthread_create(&readThread[i],NULL,read_thread,NULL);
    }

    pthread_t writeThread;//写线程
    pthread_create(&writeThread,NULL,write_thread,NULL);

    pthread_join(writeThread,NULL);

    for (int i = 0; i < 3; i++)
    {
        pthread_join(readThread[i],NULL);
    }
    
    return 0;
}