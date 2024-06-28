//编写一个程序，创建两个线程，一个线程用于递增一个全局变量
//另一个线程用于递减同一个全局变量，使用互斥锁确保递增和递减操作的正确性

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


pthread_mutex_t mutex1;
pthread_mutex_t mutex2;
pthread_mutex_t mutex3;

void func1()
{
    while (1)
    {
        pthread_mutex_lock(&mutex1);//上锁
        printf("A\n");
        pthread_mutex_unlock(&mutex2);//解锁
        sleep(1);
    }
}

void func2()
{
    while (1)
    {
        pthread_mutex_lock(&mutex2);//上锁
        printf("B\n");
        pthread_mutex_unlock(&mutex3);//解锁
        sleep(1);
        
    }
    
}

void func3()
{
    while (1)
    {
        pthread_mutex_lock(&mutex3);//上锁
        printf("C\n");
        pthread_mutex_unlock(&mutex1);//解锁
        sleep(1);
    }
}



int main()
{
    pthread_mutex_init(&mutex1,NULL);
    pthread_mutex_init(&mutex2,NULL);
    pthread_mutex_init(&mutex3,NULL);

    pthread_mutex_lock(&mutex2);//上锁
    pthread_mutex_lock(&mutex3);//上锁

    pthread_t tid1 = 0;
    pthread_t tid2 = 0;
    pthread_t tid3 = 0;

    if (pthread_create(&tid1,NULL,(void*)func1,NULL)<0)
    {
        perror("pthread error");
        return 1;
    }
    if (pthread_create(&tid2,NULL,(void*)func2,NULL)<0)
    {
        perror("pthread error");
        return 1;
    }
    if (pthread_create(&tid3,NULL,(void*)func3,NULL)<0)
    {
        perror("pthread error");
        return 1;
    }
    

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    pthread_join(tid3,NULL);
    pthread_mutex_destroy(&mutex1);//删除锁
    pthread_mutex_destroy(&mutex2);//删除锁
    pthread_mutex_destroy(&mutex3);//删除锁
    return 0;
}