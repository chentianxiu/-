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

sem_t sem[10]={};

//第一个进程打印10个1，第二个进程打印是10个2....
//第一个进程打印了一个1就会解锁第二个线程，第二个打印一个2解锁第三个....
void pthread_func(int arg)
{
	for(int i=0;i<10;i++)
	{
		sem_wait(sem+arg);
		printf("%d",arg+1);
		if((arg+1==10))
			printf("\n");
		fflush(stdout);
		sem_post(sem+(arg+1)%10);
	}
}


int main()
{
	for(int i=0;i<10;i++)
		sem_init(sem+i,0,0);
	sem_post(sem);//给sem[0]赋值为1
	pthread_t tid[10];

	for(int i=0;i<10;i++)
	{
		pthread_create(tid+i,NULL,(void*)pthread_func,(void*)(__intptr_t)(i));
	}
	
	for(int i=0;i<10;i++)
		pthread_join(tid[i],NULL);

	for(int i=0;i<10;i++)
		sem_destroy(sem+i);

	return 0;
}
