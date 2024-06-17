#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<time.h>
#include <termios.h>

void sigalrm_handler(int signo)
{
    system("clear");
    time_t t = time(NULL);
    struct tm*ptime = localtime(&t);//获取结构体时间
    //准备字符串,用字符串打印
    char buf[50]={0};
    strftime(buf,sizeof(buf),"%Y-%m-%d %H:%M:%S",ptime);
    fputs(buf,stdout);
    fflush(stdout);
    alarm(3);//一秒钟发一下时间
}


void sigalrm(int signo)
{
    printf("hello\n");
}

int main()
{
    //signal(SIGALRM,sigalrm);//注册（收到信号后才执行）收到警告信息后打印hello
    signal(SIGALRM,sigalrm_handler);
    alarm(3);//三秒后发警告

    //while (1);
    char a = '\0';
    a = getchar();

    return 0;
}