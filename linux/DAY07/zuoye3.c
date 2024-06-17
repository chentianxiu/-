//编写一个程序，创建两个线程，一个线程用于递增一个全局变量
//另一个线程用于递减同一个全局变量，使用互斥锁确保递增和递减操作的正确性

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int num =1;
pthread_mutex_t mutex1;
pthread_mutex_t mutex2;

void func1()
{
    while (1)
    {
        pthread_mutex_lock(&mutex1);//上锁
        num++;
        printf("线程1的num是%d\n",num);
        pthread_mutex_unlock(&mutex2);//解锁
        
        sleep(1);
        
    }
    
}

void func2()
{
    while (1)
    {
        pthread_mutex_lock(&mutex2);//上锁
        num--;
        printf("线程2的num是%d\n",num);
        pthread_mutex_unlock(&mutex1);//解锁
        
        sleep(1);
    }
    
}

int main()
{
    pthread_mutex_init(&mutex1,NULL);
    pthread_mutex_init(&mutex2,NULL);

    pthread_t tid = 0;

    if (pthread_create(&tid,NULL,(void*)func1,NULL)<0)
    {
        perror("pthread error");
        return 1;
    }
    if (pthread_create(&tid,NULL,(void*)func2,NULL)<0)
    {
        perror("pthread error");
        return 1;
    }

    pthread_join(tid,NULL);
    pthread_mutex_destroy(&mutex1);//删除锁
    pthread_mutex_destroy(&mutex2);//删除锁
    return 0;
}