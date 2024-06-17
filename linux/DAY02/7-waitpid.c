#include<unistd.h> 
#include<sys/types.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>


//wait不阻塞，一致等待
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
        for (int i = 0; i < 10; i++)
        {
            printf("%d",i);
            fflush(stdout);
            system("ps -o ppid,pid,command");
            sleep(1);
        } 
    }else{
        while (1)
        {
            int res = waitpid(pid,NULL,WNOHANG);
            if (res == pid)
            {
                break;
            }
            printf("child is not ending!\n");
            sleep(1);
        }
        
    }

    return 0 ;
}