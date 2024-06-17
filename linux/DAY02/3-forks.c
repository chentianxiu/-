#include<unistd.h> 
#include<sys/types.h>
#include<stdio.h>

//创建多个子进程
int main()
{
    pid_t pid = 0;
    int i=0;
    for ( i = 0; i < 3; i++)//循环创建子进程
    {
        pid = fork();
        if (pid<0)
        {
            return 1;
        }
        if (pid == 0)
        {
            break;//如果是子进程就跳出来，不然就会创建子进程的子进程
        }
    }
    if (pid==0 && i==0)
    {
        printf("i am 1st child.\n");
    }else if (pid==0 && i==1)
    {
        printf("i am 2nd child.\n");
    }else if (pid == 0 && i==2)
    {
        printf("i am 3rd child.\n");
    }else{
        printf("i am the father.\n");
    }
    return 0 ;
}