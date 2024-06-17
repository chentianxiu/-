#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int share = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;//initializer

void *func1(void* arg)
{
    while (1)
    {
        pthread_mutex_lock(&mutex);
        share++;
        printf("this thread is running for increase share: %d\n",share);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    
}

void *func2(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&mutex);
        if (share%2!=0)
        {
            printf("this thread detext ood: %d\n",share);
        }
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    
}

int main()
{
    pthread_t tid[2];
    pthread_create(&tid[0],NULL,func1,NULL);
    pthread_create(&tid[1],NULL,func2,NULL);

    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);

    pthread_mutex_destroy(&mutex);

    return 0;

}