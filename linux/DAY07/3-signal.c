#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<signal.h>

pthread_t tid = 0;

void signal_handler(int sig)
{
    pthread_cancel(tid);
    signal(sig,SIG_DFL);
    //运行这个程序后，按下 Ctrl+C，会触发 SIGINT 信号，
    //并调用自定义信号处理程序。第二次按下 Ctrl+C 时，由于信号处理程序已经被重置为默认处理程序，进程将会终止
}

void *func(void*arg)//子线程函数
{
    while (1)
    {
        printf("\033[32m我是子线程\033[0m\n");
        sleep(1);
    }
    return NULL;
}

int main()
{
    signal(SIGINT,signal_handler);
    if (pthread_create(&tid,NULL,func,NULL)<0)
    {
        perror("pthread error");
        return 1;
    }
    while (1)
    {
        system("ps -L -o pid,lwp,nlwp,command");
        sleep(1);
    }

    pthread_join(tid,NULL);
    return 0;
}