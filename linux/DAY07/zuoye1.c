#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

//返回值
int num1 = 0;
int num2 = 0;
int sum = 0;

void * func1()
{
    for (int i = 1; i <=100; i+=2)
    {
        num1+=i;
    }
    printf("奇数和为%d\n",num1);
}
void *func2()
{
    for (int j = 0; j <=100; j+=2)
    {
        num2+=j;
    }
    printf("偶数和为%d\n",num2);
}
void *func3()
{
    for (int m = 0; m <=100; m++)
    {
        sum+=m;
    }
    printf("所有数和为%d\n",sum);
}

int main()
{
    pthread_t tid = 0;

    if (pthread_create(&tid,NULL,(void *)func1,NULL)<0)
    {
        perror("pthread error");
        return 1;
    }
    if (pthread_create(&tid,NULL,(void *)func2,NULL)<0)
    {
        perror("pthread error");
        return 1;
    }
    if (pthread_create(&tid,NULL,(void *)func3,NULL)<0)
    {
        perror("pthread error");
        return 1;
    }

    pthread_join(tid,NULL);//没有返回值
    printf("所有线程执行完毕\n");

    return 0;
}
