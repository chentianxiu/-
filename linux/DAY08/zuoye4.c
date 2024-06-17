/*
编写一个程序，创建两个线程，一个线程负责打印奇数，
另一个线程负责打印偶数，
要求两个线程交替执行，并且使用信号量来实现同步。
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

sem_t sem_1;
sem_t sem_2;

void *pthread_func(void *arg)//
{
   for (int i = 0; i <= 100; i+=2)
   {    
        sem_wait(&sem_1);
        printf("线程1打印：%d\n",i);
        sem_post(&sem_2);
   }
   pthread_exit(NULL); // 线程退出
}

void *pthread_func2(void *arg)//
{
    for (int i = 1; i <= 100; i+=2)
   {
        sem_wait(&sem_2);
        printf("线程2打印：%d\n",i);
        sem_post(&sem_1);
   }
   pthread_exit(NULL); // 线程退出
}

int main()
{
	
	sem_init(&sem_1,0,1);//
    sem_init(&sem_2,0,0);//
    pthread_t tid[2];

	pthread_create(&tid[0],NULL,(void*)pthread_func,NULL);
    pthread_create(&tid[1],NULL,(void*)pthread_func2,NULL);

	pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);

	sem_destroy(&sem_1);
    sem_destroy(&sem_2);

	return 0;
}
