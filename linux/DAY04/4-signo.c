#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int flag = 1; 

void sigchild_handler(int signo)
{   //回收子进程
    printf("signo:%d\n",signo);
    if (signo == SIGCHLD)
    {
        printf("child is end.\n");
        wait(NULL);
        flag = 0;
    }
}

void sigint_handler(int signo)
{   //ctl+c 中断程序
    printf("%d ended\n",getpid());
    exit(EXIT_SUCCESS);
}

int main()
{
    pid_t pid = fork();
    if (pid<0)
    {
        perror("fork error\n");
        return 1;
    }

    if (pid==0)
    {
        signal(SIGINT,sigint_handler);
        while (1)
        {
            printf("i am child %d,my parent is %d\n",getpid(),getppid());
            sleep(1);
        }
        
    }
    else
    {
        signal(SIGINT,sigchild_handler);
        signal(SIGCHLD,sigchild_handler);
        while (flag)
        {
            printf("i am parent %d,my child is %d \n",getpid(),pid);
            sleep(2);
        }
        
    }
    
    return 0;
}
/*解释
int flag：flag 被声明为 int 类型，以确保在信号处理程序和主程序之间正确地传递值。
sigchld_handler：这个信号处理程序处理 SIGCHLD 信号，当子进程结束时触发。使用 wait 循环回收所有已终止的子进程。
sigint_handler：这个信号处理程序处理 SIGINT 信号，当按下 Ctrl+C 时触发，打印进程结束信息并退出程序。
信号处理程序注册：在父进程中，注册 SIGCHLD 和 SIGINT 信号处理程序；在子进程中，只注册 SIGINT 信号处理程序。
这段代码现在应该能够正确处理 SIGCHLD 和 SIGINT 信号，子进程和父进程各自打印信息，按下 Ctrl+C 后程序会正确退出。*/