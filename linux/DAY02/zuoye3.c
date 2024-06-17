#include<unistd.h> 
#include<sys/types.h>
#include<stdio.h>
#include<sys/wait.h>
//创建多个子进程
int main()
{
    pid_t pid[2];
    int i=0;
    for ( i = 0; i < 2; i++)//循环创建子进程
    {
        pid[i] = fork();
        if (pid[i]<0)
        {
            return 1;
        }
        if (pid[i] == 0)
        {
            break;//如果是子进程就跳出来，不然就会创建子进程的子进程
        }   
    }
    if (pid[0]==0)
    {
        sleep(3);
        printf("i am 1st child.\n");
    }else if (pid[1]==0)
    {
        sleep(4);
        printf("i am 2nd child.\n");

    }else{
        int* stat1 = NULL;
        int* stat2 = NULL;
        waitpid(pid[0],stat1,WNOHANG);
        wait(NULL);
        wait(NULL);
        printf("%ls\n",stat1);
        printf("i am the father.\n");
    }
    return 0 ;
}