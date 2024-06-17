#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>
#include <fcntl.h>
#include<signal.h>
#include<semaphore.h>

sem_t sem_1;
sem_t sem_2;

int flag = 1;

void sig_user(int sig)
{
    flag = 0;
}

int num = 0;


//生成随机数
void *func1(void *len)
{
    signal(SIGINT,sig_user);
    srand(time(NULL));
    while (flag)
    {
        sem_wait(&sem_1);
        int randnum = rand()%10;
        num = randnum;
        sleep(1);
        sem_post(&sem_2);
    }
    pthread_exit(NULL);//线程退出
}

//写入文件
void *func2(void *len)
{
    signal(SIGINT,sig_user);
    int fd_w=open("a.txt",O_WRONLY|O_TRUNC,0666);
    if (fd_w == -1) {
        perror("打开文件失败");
    }
    while (flag)
    {
        sem_wait(&sem_2);
        char buffer[12];  // 足够大的缓冲区来存储整数和换行符
        int length = snprintf(buffer, sizeof(buffer), "%d\n", num);
        write(fd_w,buffer,length);
        printf("%d\n",num);
        sem_post(&sem_1);
    }
    close(fd_w);
    pthread_exit(NULL);//线程退出
}


int main()
{
    sem_init(&sem_1,0,1);
    sem_init(&sem_2,0,0);
    pthread_t tid[2];

    if(pthread_create(&tid[1],NULL,func1,NULL)<0)//(void*)func也行
    {
        perror("pthread error");
        return 1;
    }
    if(pthread_create(&tid[0],NULL,func2,NULL)<0)//(void*)func也行
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
