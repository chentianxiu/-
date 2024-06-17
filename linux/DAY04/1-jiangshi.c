#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();
    if (pid<0)
    {
        perror("fork error!");
        return 1;
    }
    if (pid==0)
    {
        printf("子进程开始\n");
        sleep(1);
        printf("子进程结束\n");
    }
    else{
        while (1)
        {
            system("ps -o ppid,pid,stat,command");
            sleep(1);
        }
        wait(NULL);
    }
    
    return 0;
}