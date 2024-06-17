#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

/*
僵尸进程:父进程太忙,子进程结束,未被回收;解决方法:kill僵尸进程(kill KILL-(进程号))、kill僵尸进程的父进程;
kill -9 进程号; = kill KILL-(进程号),强制关闭; kill 进程号,等待进程完成某些内容后关闭;
kill -l:显示所有的信号;
SIGINT（信号情报）是一种情报收集方法，通过拦截和分析通信信号来获取情报信息。在计算机领域，SIGINT也可以指代信号中断（Signal Interrupt），用于通知进程发生了外部事件，需要进行处理。
SIGCHLD（子进程状态改变信号）是在Unix/Linux系统中用来通知父进程子进程状态改变的信号。当一个子进程终止或停止时，操作系统会向父进程发送SIGCHLD信号，父进程可以通过捕获这个信号来处理子进程的状态改变。
signal函数用于告诉操作系统当接收到 信号 时应该调用哪个函数来处理。例:signal(SIGINT,sigchld_handler);
*/
/*
信号: signal(信号,可执行函数),当程序捕获到目标信号,运行可执行程序;
    SIGINT:
        中断,signal(SIGINT,可执行函数),当程序捕获到中断(ctrl+c),运行可执行程序;
    SIGCHLD:
        子进程状态改变,当子进程结束,发送信号,signal(SIGCHLD,可执行函数)-接收信号,运行可执行程序;
    SIGALRM:
        时钟,用于定时;alarm(定时时间)-发送信号,signal(SIGALRM,可执行函数)-接收信号,运行可执行程序;
    SIGUSR1:
        用户自定义信号1;使用kill(进程ID,SIGUSR1)-给ID发送自定义信号1,signal(SIGUSR1,可执行函数)-接收信号,运行可执行程序;
信号量(semid):
    void sem_post(int semid,int num)
    {
        struct sembuf sop = {};
        sop.sem_flg = SEM_UNDO;//自动回收
        sop.sem_num = num;
        sop.sem_op = 1;
        semop(semid,&sop,1);//信号量标志,结构体指针,需操作信号量数量
    }
    void sem_wait(int semid,int num)
    {
        struct sembuf sop = {};
        sop.sem_flg = SEM_UNDO;//自动回收
        sop.sem_num = num;
        sop.sem_op = -1;
        semop(semid,&sop,1);
    }
    key_t mykey = ftok(__FILE__,1);(__FILE__)现表示本文件,可修改,不同文件之间通信，指向同一文件；
    int semid = semget(mykey,2,IPC_CREAT|0666);

    semctl(semid,0,SETVAL,1);
    semctl(semid,1,SETVAL,0);
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork fail\n");
        return 1;
    }
    if(pid == 0)
    {
        while(1)
        {
            sem_wait(semid,1);//信号量1做减法,后执行
            可执行程序;
            sem_post(semid,0);//信号量0做加法
        }
        semctl(semid,1,IPC_RMID);
    }
    else
    {
        while(1)
        {
            sem_wait(semid,0);//信号量0做减法,先执行
            可执行程序;
            sem_post(semid,1);//信号量1做加法
        }
        semctl(semid,0,IPC_RMID);
    }
*/
