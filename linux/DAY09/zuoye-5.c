/*
5、编写一个程序，创建3个线程，每个线程分别打印字母A、B、C，
要求依次循环打印ABCABCABC...，使用条件锁互斥锁来实现线程的同步。
*/
//第七天作业四用的是条件锁做出来
//今天用条件锁和互斥锁


#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int arr[3]={0,1,2};
char current = 'A';

void *func(void* arg)
{
    int a = *(int*)arg;
    while (1)
    {
        pthread_mutex_lock(&mutex);
        while (current != a+65)
        {
            
            pthread_cond_wait(&cond,&mutex);
        }
        printf("%c\n",a+65);
        if (current == 'C')
        {
            current = 'A';
        }
        else{
            current++;
        }
        pthread_cond_broadcast(&cond);//唤醒所有的沉睡项目
        sleep(1);
        pthread_mutex_unlock(&mutex);
    }
    
}

int main()
{
    pthread_t tid[3];

    for (int i = 0; i < 3; i++)
    {
        pthread_create(&tid[i],NULL,func,(void*)&arr[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        pthread_join(tid[i],NULL);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}