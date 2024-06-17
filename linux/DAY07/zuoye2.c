#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include <unistd.h>
#include <sys/types.h>

//返回值

void * func(void * arg)
{
   
    printf("\033[32m我是子线程,id是%ld\033[0m\n",pthread_self());
    //printf("%d\n",gettid());
}

int main()
{
    pthread_t tid = 0;

    if (pthread_create(&tid,NULL,(void *)func,NULL)<0)
    {
        perror("pthread error");
        return 1;
    }
    printf("\033[35m我是父线程\033[0m\n");
    pthread_join(tid,NULL);//没有返回值
    return 0;
}
