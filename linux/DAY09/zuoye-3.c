/*
3、编写程序使用三个子线程计算1~N的阶乘和，注意共享资源的安全。
最后主线程得到计算结果并输出。（4分）
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t mutex;

int sum = 0;

typedef struct 
{
    int start;
    int end;
    unsigned long long result; 
}rang;

// void *func(void* arg)//求阶乘
// {
//     rang a = *(rang*)arg;
//     a.result = 1;
//     for (int i =a.start ; i <=a.end; i++)
//     {
//         a.result *=i;
//     }
//     printf("%d   %d\n",a.start,a.end);

//     pthread_mutex_lock(&mutex); 
//     sum*=a.result;
//     pthread_mutex_unlock(&mutex);
// }

int jieChen(int num)
{
    int Num = 1;
    for (int i = 1; i <= num; i++)
    {
        Num*=i;
    }
    return Num;
}

void *func(void* arg)//求阶乘的和
{
    rang a = *(rang*)arg;
    a.result = 0;
    int temp = 0;
    for (int i =a.start ; i <=a.end; i++)
    {
        temp = jieChen(i);
        a.result +=temp;
    }
    printf("%d   %d\n",a.start,a.end);
    printf("%lld\n",a.result);
    

    pthread_mutex_lock(&mutex); 
    sum+=a.result;
    pthread_mutex_unlock(&mutex);
}

int main()
{
    pthread_mutex_init(&mutex,NULL);
    rang table[3];
    int N = 0;
    printf("请输入你要求的阶乘的数:\n");
    scanf("%d",&N);
    int num1 = N/3;

    pthread_t tid[3];

    for (int i = 0; i < 3; i++)
    {
        if (i==2)
        {
            table[i].start=i*num1+1;
            table[i].end = N;
        }else{
            table[i].start=i*num1+1;
            table[i].end = (i+1)*num1;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        pthread_create(&tid[i],NULL,func,(void*)&table[i]);
    }
    

    for (int i = 0; i < 3; i++)
    {
        pthread_join(tid[i],NULL);
    }
    pthread_mutex_destroy(&mutex);
    printf("%d阶乘的和为%d\n",N,sum);
    return 0;
}