/*
设计一个限制器，用信号量：比如同时创建10个线程；
但是同时只能运行3个，只有一个运行完了，才能接着运行新线程
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

sem_t sem;

//第一个进程打印10个1，第二个进程打印是10个2....
//第一个进程打印了一个1就会解锁第二个线程，第二个打印一个2解锁第三个....
void pthread_func(int arg)
{
    sem_wait(&sem);//阻塞
    printf("%d\n",arg);
    sleep(3);
    sem_post(&sem);

    pthread_exit(NULL);//线程退出
}


int main()
{
	
	sem_init(&sem,0,3);
	pthread_t tid[10];

	for(int i=0;i<10;i++)
	{
		pthread_create(tid+i,NULL,(void*)pthread_func,(void*)(__intptr_t)(i));
	}
    
	for(int i=0;i<10;i++)
		pthread_join(tid[i],NULL);

	sem_destroy(&sem);

	return 0;
}
