/*
4、练习：有4个小孩，每个小孩的任务就是领取生活费1000，回学校之前，
父母先在银行卡中存2000块钱，2个线程拿到1000块钱之后退出，另外2个
线程进去条件变量中等待，父亲再打钱1000，唤醒所有的小孩起来拿钱， 
过一会，再打1000块钱，再唤醒最后一个小孩起来拿钱赶紧走人上学。
*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int cardmoney = 2000;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *func(void * arg)
{
    int a = *(int*)arg;
    pthread_mutex_lock(&mutex);
    while (cardmoney<1000)
    {
        pthread_cond_wait(&cond,&mutex);
    }
    cardmoney-=1000;
    printf("%d号孩子拿了1000\n",a);
    pthread_mutex_unlock(&mutex);

}


int main(){
    //创建四个子线程,每个子线程的任务一样
    pthread_t tid[4];
    int arr[4]={1,2,3,4};
    for (int i = 0; i < 4; i++)
    {
        pthread_create(&tid[i],NULL,func,(void*)&arr[i]);
    }

    sleep(2);//父亲等待两秒打钱

    pthread_mutex_lock(&mutex);
    cardmoney+=1000;
    printf("父亲打款一千\n");
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);


    sleep(2);//父亲再等两秒打钱
    pthread_mutex_lock(&mutex);
    cardmoney+=1000;
    printf("父亲再打款一千\n");
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);

    // while (1)
    // {
    //     pthread_mutex_lock(&mutex);
    //     cardmoney+=1000;
    //     printf("父亲打款一千\n");
    //     pthread_cond_signal(&cond);
    //     pthread_mutex_unlock(&mutex);
    // }
    


    //等待四个子进程完成
    for (int i = 0; i < 4; i++)
    {
        pthread_join(tid[i],NULL);
    }

    //删除条件锁和锁
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    
    return 0;
}

