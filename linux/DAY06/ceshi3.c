#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <time.h>
#include <termios.h>

int num = 0;

void sing_usr(int sig)
{
    num++;
}

int main()
{

    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork error");
        return 1;
    }
    signal(SIGUSR1, sing_usr);
    if (pid == 0)
    {
        while (1)
        {

            while (num > 0)
            {
                printf("helloworld\n");
                num--;
            }
        }
    }
    else
    {
        int chose = 0;
        while (1)
        {
            printf("请输入你的选择\n");
            scanf("%d", &chose);
            switch (chose)
            {
            case 1:
                kill(pid, SIGUSR1);
                break;
            case 2:
                kill(pid, SIGUSR1);
                usleep(100);
                kill(pid, SIGUSR1);
                break;
            case 3:
                kill(pid, SIGUSR1);
                usleep(100);
                kill(pid, SIGUSR1);
                usleep(100);
                kill(pid, SIGUSR1);
                break;
            default:
                break;
            }
            sleep(1);
        }
    }

    return 0;
}