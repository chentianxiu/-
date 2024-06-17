#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    
    pid_t pid = fork();

    if (pid<0)
    {
        printf("创建失败\n");
    }
    if (pid==0)
    {
        printf("这是子进程\n");
        int res = execlp("ls","ls",NULL);
        
        if (res<0)
        {
            return 1;
        }
        int status;
        //waitpid(pid, &status, WNOHANG);
        //printf("%d\n",status);
        printf("子进程结束\n");
    }else{
        //int status;
        printf("这是父进程\n");
        //waitpid(pid, &status, WNOHANG);
        //printf("%d\n",status);
        wait(NULL);
        printf("子进程结束，父进程再结束\n");
    }
    
}