#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

int gnum = 0;

pthread_rwlock_t rwlock;

void funcl()
{
    for (int i = 0; i < 10; i++)
    {
        pthread_rwlock_rdlock(&rwlock);
        printf("func1 read gnum = %d\n",gnum);
        pthread_rwlock_unlock(&rwlock);
    }
    
}