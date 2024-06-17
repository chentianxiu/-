/*************************************************************************
	> File Name: sem_mutex.c
	> Author: chenliang
	> Mail: 2779783956@qq.com 
	> Created Time: Fri 14 Jun 2024 01:05:42 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<semaphore.h>

sem_t sem;

void printer(char * str)
{
	sem_wait(&sem);//阻塞
	while(*str)
	{
		putchar(*str);
		fflush(stdout);
		str++;
		sleep(1);
	}
	sem_post(&sem);
}

void* func1(void *arg)
{
	char *str1 = "hello";
	printer(str1);

}


void* func2(void *arg)
{
	char *str2 = "world";
	printer(str2);
}

int main()
{
	sem_init(&sem,0,1);
	pthread_t thread[2];
	
	pthread_create(&thread[0],NULL,func1,NULL);
	pthread_create(&thread[1],NULL,func2,NULL);
	
	pthread_join(thread[0],NULL);
	pthread_join(thread[1],NULL);
	
	sem_destroy(&sem);
	printf("\n");
	return 0;
}





