#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int share = 0;

//两个锁要一起用
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;//initializer
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;//initializer

void *func1(void* arg)
{
    while (1)
    {
        pthread_mutex_lock(&mutex);
        share++;
        sleep(1);
        printf("this thread is running for increase share: %d\n",share);
        pthread_cond_signal(&cond);//发信号
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    
}

void *func2(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&mutex); 
        while (share%2==0)
        {
            //不符合奇数，等待，卡在这，解锁mutex。让share继续++，直到收到信号，停止等待，继续运行
            pthread_cond_wait(&cond,&mutex);
            printf("--\n");
        }
        printf("this thread detext ood: %d\n",share);
       
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