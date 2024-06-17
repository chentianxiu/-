/*************************************************************************
	> File Name: sem_mutex.c
	> Author: chenliang
	> Mail: 2779783956@qq.com 
	> Created Time: Fri 14 Jun 2024 01:05:42 PM CST
 ************************************************************************/
//打印abcd...z按顺序,两个线程，一个线程打印，一个线程把ch加1.这个题目包含互斥
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<semaphore.h>

char ch ='a';
sem_t sem_1,sem_2;


void* func1(void *arg)
{
	while(ch<='z')
	{
		sem_wait(&sem_1);//sem_1 val = 0
		ch++;
		usleep(100);
		sem_post(&sem_2);
	}
}

void* func2(void *arg)
{
	while(ch<'z')
	{
		sem_wait(&sem_2);
		printf("%c",ch);
		fflush(stdout);
		sem_post(&sem_1);
	}
}

int main()
{
	sem_init(&sem_1,0,0);
	sem_init(&sem_2,0,1);
	pthread_t thread[2];
	
	pthread_create(&thread[0],NULL,func1,NULL);
	pthread_create(&thread[1],NULL,func2,NULL);
	
	pthread_join(thread[0],NULL);
	pthread_join(thread[1],NULL);
	
	sem_destroy(&sem_1);
	sem_destroy(&sem_2);
	printf("\n");
	return 0;
}





