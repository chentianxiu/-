#include<unistd.h> 
#include<sys/types.h>
#include<stdio.h>

int main()
{
    pid_t pid = 0;
    printf("i am your father .pid = %d\n",getpid());
    pid  = fork();//创建子进程
    if (pid == 0)
    {
        printf(" i am child. pid = %d\n",getpid());

        pid_t new_pid = fork();//创建孙进程

        if (new_pid == 0)
        {
            printf("i am grandchild. pid = %d;ppid = %d\n",getpid(),getppid());
        }
        
    }

    return 0 ;
}