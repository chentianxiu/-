#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>
#include<semaphore.h>

int men1 = 5000;
int men2 = 0;
int change = 0;


sem_t sem_1,sem_2;

//模拟账户转账方
void *func1(void *len)
{
    int flag = 1;
    while(flag){
    sem_wait(&sem_1);
    printf("小张初始金额：%d\n",men1);
    printf("请输入转账金额(输入0退出):\n");
    scanf("%d",&change);
    if (change==0)
    {
        flag = 0;
    }
    men1 -=change;
    printf("小张还剩下：%d\n",men1);
    sem_post(&sem_2);
    }
    pthread_exit(NULL);//线程退出
}

//模拟账户接收方
void *func2(void *len)
{
    int flag2 = 1;
    while(flag2){
    sem_wait(&sem_2);
    printf("李四原本金额为%d\n",men2);
    if (change == 0)
    {
        flag2 = 0;
    }
    men2 +=change;
    printf("李四接受转账余额为%d\n",men2);
    sem_post(&sem_1);
    }
    pthread_exit(NULL);//线程退出
}

int main()
{
    sem_init(&sem_1,0,1);
    sem_init(&sem_2,0,0);
    pthread_t tid[2];
    

    if(pthread_create(&tid[0],NULL,func1,NULL)<0)//(void*)func也行
    {
        perror("pthread error");
        return 1;
    }
    if(pthread_create(&tid[1],NULL,func2,NULL)<0)//(void*)func也行
    {
        perror("pthread error");
        return 1;
    }

    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);

    sem_destroy(&sem_1);
    sem_destroy(&sem_2);

    
    return 0;
}
