#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>
//编写一个C程序，创建一个子进程，
//然后让父进程向子进程发送一个信号，子进程在接收到信号后捕获并处理另一个不同的信号。


//处理子进程第二个信号
void signal_user2(int sig){

    printf("子进程处理收到的第二个信号\n");
    exit(42);

}

//子进程接受父进程的信号
void signal_user(int sig)
{
    printf("收到了父进程的信号\n");

    //收到信息后，
    signal(SIGUSR2,signal_user2);

    printf("子进程生成了处理第二个信号的程序\n");
}

int main()
{

    pid_t pid = fork();//创建子进程

    if (pid<0)
    {
        perror("fork error");
    }

    if (pid==0)
    {
        signal(SIGUSR1,signal_user);// 设置处理 SIGUSR1 信号的处理函数

        //无限循环等待信号
        while(1){
            pause();//等待第二个信号
        }
    }
    else{
        
        sleep(1);
        kill(pid,SIGUSR1);//发消息给子进程
        printf("父进程发送第一个信号\n");
        
        sleep(1);
        kill(pid,SIGUSR2);//发第二个消息给子进程，让子进程处理不同的信号
        printf("父进程发送第二个信号\n");

        //等待子进程结束
        wait(NULL);
    }
    
    return 0;
}