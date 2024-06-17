#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<semaphore.h>


/*
线程函数创建三种方式
void *func(void * arg)
{
    int num = *(int*)arg;
}

if(pthread_creat(&tid,NULL,func,(void*)&arg)<0)
{
    perror("pthread error");
    return 1;
}

void func(int *arg)
{
    len可以直接用
}
if(pthread_creat(&tid,NULL,(void*func),(void*)&arg))//这里的arg不能在for循环创建线程里面传变量i，会改变
{
    perror("pthread error");
    return 1;
}

void func(int arg)
{
    arg 可以直接用
}

if(pthread_creat(&tid,NULL,(void*func),(void*)(__intptr_t)arg))
{
    perror("pthread error");
    return 1;
}

pthread_t tid = 0;||pthread_t tid[2];//定义线程,上面是创建线程

pthread_join(tid,NULL);//等待线程结束


线程锁
pthread_mutex mutex_1;//创建线程锁
pthread_mutex_init(&mutex_1,NULL);//锁初始化
pthread_mutex_lock(&mutex_1)//上锁
pthread_mutex_unlock(&mutex_1)//解锁
pthread_mutex_destroy(&mutex_1);//删除锁

信号量
sem_t sem; 创建信号量

sem_init(&sem,0,0);//初始化,前一个0是属性,后一个0是val
sem_wait(&sem) sem值减一
sem_post(&sem) sem值加一
sem_destroy(&sem) 删除sem



*/