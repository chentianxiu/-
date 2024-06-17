#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include<time.h>
#include <termios.h>

int flag = 1;

void signal_alarm(int sig)
{
    //system("clear");
    time_t t = time(NULL);
    struct tm*ptime = localtime(&t);//获取结构体时间
    //准备字符串,用字符串打印
    char buf[50]={0};
    strftime(buf,sizeof(buf),"%Y-%m-%d %H:%M:%S",ptime);
    fputs(buf,stdout);
    printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
    fflush(stdout);
    alarm(1);
}

void sig_user()
{
    flag = 0;
}


int main()
{
    signal(SIGUSR1,sig_user);
    
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork error");
        return 1;
    }

    if (pid == 0)
    {
        signal(SIGALRM,signal_alarm);
        alarm(1);
        
        while(flag);
        exit(0);
    }
    else
    {
        //无限循环等待信号
        char str[]="exit\n";
        printf("请输入exit退出\n");
        char str1[6];
        fgets(str1,6,stdin);
        if (strcmp(str,str1)==0)
        {
            kill(pid,SIGUSR1);
        }
        wait(NULL);
    }

    return 0;
}