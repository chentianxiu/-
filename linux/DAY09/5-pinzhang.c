#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<bits/pthreadtypes.h>

#define NUM_THREADS 4

pthread_barrier_t barrier;

void *func(void *arg)
{
    int thread_id = *(int*)arg;
    printf("thread %d started.\n",thread_id);

    pthread_barrier_wait(&barrier);//等待，等所有线程启动
    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];//传数组进去

    pthread_barrier_init(&barrier,NULL,NUM_THREADS);//初始化屏障,需要等待四个线程准备就绪，不足四个会一直卡住

    for (int i = 0; i < NUM_THREADS; i++)
    {
        thread_ids[i]=i;
        pthread_create(&threads[i],NULL,func,&thread_ids[i]);
    }
    
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i],NULL);
    }
    
    pthread_barrier_destroy(&barrier);//释放
    printf("所有线程结束\n");
    
    return 0;
}