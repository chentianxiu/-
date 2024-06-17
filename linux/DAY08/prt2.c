/*
用信号量是实现生产者消费者模型
生产者负责生产产品，消费者负责消费产品
最多10个产品，仓库容量为5;
*/

/*************************************************************************
	> File Name: sem1.c
	> Author: chenliang
	> Mail: 2779783956@qq.com 
	> Created Time: Fri 14 Jun 2024 01:49:59 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

sem_t sem_cangku;
sem_t sem_num;

int numin = 0;
int numout = 0;

void *pthread_func(void *arg)//生产
{
    while (numin<10)
    {
        sem_wait(&sem_cangku);//仓库容量减一;
        numin++;
        printf("生产第%d个\n",numin);
        sem_post(&sem_num);
    }
}

void *pthread_func2(void *arg)//消费
{
    while (numout<10)
    {
        sem_wait(&sem_num);//消费一个
        numout++;
        printf("消费%d个\n",numout);
        sem_post(&sem_cangku);//仓库数量+1;
    }
}

int main()
{
	
	sem_init(&sem_cangku,0,5);//仓库库存
    sem_init(&sem_num,0,0);//数量
	pthread_t tid[2];

	pthread_create(&tid[0],NULL,(void*)pthread_func,NULL);
    pthread_create(&tid[1],NULL,(void*)pthread_func2,NULL);

	pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);

	sem_destroy(&sem_cangku);
    sem_destroy(&sem_num);

	return 0;
}
