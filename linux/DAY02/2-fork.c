#include<unistd.h> 
#include<sys/types.h>
#include<stdio.h>

int main()
{
    pid_t pid = fork();//创建子进程
    if (pid <0)
    {
        perror("pid error");
        return 1;
    }
    if (pid == 0)
    {
        printf("\033[31m i am child [%d],my parent is %d \033[0m\n",getpid(),getppid());
    }else{
        printf("\033[31m i am PARENT [%d],my CHILD is %d \033[0m\n",getpid(),pid);
    }

    return 0 ;
}