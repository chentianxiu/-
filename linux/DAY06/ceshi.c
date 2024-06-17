#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <time.h>

volatile sig_atomic_t alarm_received = 0;
volatile sig_atomic_t exit_flag = 0;

void alarm_handler(int sig)
{
    alarm_received = 1;
}

void display_clock()
{
    while (!exit_flag)
    {
        system("clear");
        time_t now = time(NULL);
        struct tm *t = localtime(&now);

        printf("当前时间: %02d:%02d:%02d\n", t->tm_hour, t->tm_min, t->tm_sec);
        sleep(1);

        if (exit_flag)
        {
            break;
        }
    }
    printf("子进程结束\n");
    exit(0);
}

int main()
{
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork error");
        return 1;
    }

    if (pid == 0)
    {
        // 子进程设置信号处理器
        struct sigaction sa;
        sa.sa_handler = alarm_handler;
        sa.sa_flags = 0;
        sigemptyset(&sa.sa_mask);

        if (sigaction(SIGALRM, &sa, NULL) == -1)
        {
            perror("sigaction");
            exit(1);
        }

        // 无限循环等待信号
        while (!alarm_received)
        {
            pause(); // 等待信号
        }

        display_clock();
    }
    else
    {
        // 设置5秒后发送alarm信号
        alarm(5);

        char input[100];

        while (1)
        {
            printf("输入 'exit' 退出程序: ");
            if (fgets(input, sizeof(input), stdin) != NULL)
            {
                // 移除换行符
                input[strcspn(input, "\n")] = '\0';
                if (strcmp(input, "exit") == 0)
                {
                    printf("发送SIGINT信号给子进程\n");
                    kill(pid, SIGINT);

                    // 等待子进程结束
                    wait(NULL);

                    printf("主进程结束\n");
                    break;
                }
                else
                {
                    printf("无效输入\n");
                }
            }
        }
    }

    return 0;
}
