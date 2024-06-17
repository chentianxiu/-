#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

pid_t pid_1;
pid_t pid_2;
volatile sig_atomic_t flag1 = 1;
volatile sig_atomic_t flag2 = 1;

void signal_user(int sig){
    printf("第一个子进程收到父进程发送的进程号\n");
    //给第二个子进程发信号
    printf("第一个子进程向第二个子进程发送信号\n");
    kill(pid_2,SIGUSR2);
    sleep(1);
    flag1 = 0;
}

void signal_user2(int sig){

    printf("子进程2收到了子进程1的信号\n");
    flag2 = 0;
}

int main()
{
    pid_1=fork();
    if (pid_1<0)
    {   
        perror("fork error");
        return 1;
    }
    if(pid_1==0)
    {
        printf("我是第一个子进程\n");
        signal(SIGUSR1,signal_user);
        while(flag1);
        exit(EXIT_SUCCESS);
    }

    pid_2 = fork();
    if (pid_2<0)
    {   
        perror("fork error");
        return 1;
    }
    if(pid_2==0){
        printf("我是第二个子进程\n");
        signal(SIGUSR2,signal_user2);
        while (flag2);
        exit(EXIT_SUCCESS);
    }
    else{

        sleep(2);
        printf("我是父进程\n");
        kill(pid_1,SIGUSR1);//发消息给第一个子进程

        wait(NULL);
        wait(NULL);
        printf("父进程: 所有子进程已结束\n");
    }

    
    return 0;
}