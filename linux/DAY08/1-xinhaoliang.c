#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>
#include<semaphore.h>

sem_t sem;

void func1(void * arg)
{
    sem_wait(&sem);
    int *running = arg;
    printf("pthread running\n");
    printf("%d\n",*running);
}

void func2(void * arg)
{
    printf("pthread2 running\n");
    sem_post(&sem);
}

int main()
{
    sem_init(&sem,0,0);//初始化,前一个0是属性,后一个0是val
    pthread_t thread[2];
    int a =5;

    if (pthread_create(&thread[0],NULL,(void*)func1,(void*)&a)<0)
    {
        perror("error");
        return 1;
    }
    printf("main thread running!\n");
    sleep(2);
    if (pthread_create(&thread[1],NULL,(void*)func2,(void*)&a)<0)
    {
        perror("error");
        return 1;
    }
    printf("main thread running2!\n");

    pthread_join(thread[0],NULL);
    pthread_join(thread[1],NULL);

    sem_destroy(&sem);

    return 0;
}