#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>

int flag = 0;

void signal_handler(int signal)
{
    flag = 0;
}

int main()
{
    signal(SIGUSR1,signal_handler);

    pid_t pid = fork();

    if (pid<0)
    {
        perror("pid error");
        return 1;
    }
    if (pid==0)
    {
        flag = 1;
        for(int i = 0;i<10;++i){
            while (flag);
            printf("i am chlid %d\n",i);
            flag = 1;
            usleep(100);//给时间发信号
            kill(getppid(),SIGUSR1);//把信号发给父进程,经过函数处理后，解除父进程的阻塞
        }
    }
    else{
        flag = 0;
        for (int i = 0; i < 10; i++)
        {
            while (flag);
            printf("i am the parent %d\n",i);
            flag = 1;
            usleep(100);
            kill(pid,SIGUSR1);//发消息给子进程
        }
        wait(NULL);
    }
    return 0;
}