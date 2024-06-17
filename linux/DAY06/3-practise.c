#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int flag = 1;
int flag1 = 1;

void signal_handler(int sig)
{
    flag = 0;
}

void signal_user(int sig)
{
    flag1 = 0;
}

int main()
{

    signal(SIGUSR1, signal_user);
    signal(SIGINT, signal_handler);
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork error");
        return 1;
    }

    if (pid == 0)
    {
        // 无限循环等待信号
        while (flag1)
            ;
        for (int i = 1; i < 6; i++)
        {
            printf("%d\n", i);
            sleep(1);
        }
        printf("关机\n");
        exit(0);
    }
    else
    {
        // 无限循环等待信号
        
        while (flag)
        {
        }
        kill(pid, SIGUSR1);
        wait(NULL);
    }

    return 0;
}