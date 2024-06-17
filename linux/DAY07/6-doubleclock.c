#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex1;
pthread_mutex_t mutex2;

void func()
{
    while (1)
    {
        pthread_mutex_lock(&mutex2);//上锁
        printf("i am child\n");
        pthread_mutex_unlock(&mutex1);//解锁
        sleep(1);
    }
    
}

int main()
{
    pthread_mutex_init(&mutex1,NULL);
    pthread_mutex_init(&mutex2,NULL);

    pthread_t tid = 0;

    if (pthread_create(&tid,NULL,(void*)func,NULL)<0)
    {
        perror("pthread error");
        return 1;
    }
    while (1)
    {
        pthread_mutex_lock(&mutex1);//上锁
        printf("i am parent\n");
        pthread_mutex_unlock(&mutex2);//解锁
        sleep(1);
    }
    pthread_join(tid,NULL);
    pthread_mutex_destroy(&mutex1);//删除锁
    pthread_mutex_destroy(&mutex2);//删除锁
    return 0;
}