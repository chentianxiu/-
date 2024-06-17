#include<unistd.h> 
#include<sys/types.h>
#include<stdio.h>
#include<sys/wait.h>

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

        pid_t pid2 = wait(NULL);//等任意子进程结束
        printf("child %d end !\n",pid2);//阻塞结束就程序结束
    }

    return 0 ;
}