#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>



int main()
{
    //创建管道
    int fd[2];
    if (pipe(fd)<0)
    {
        perror("pipe error");
        return 1;
    }

    //创建子进程
    pid_t pid = fork();
    if (pid<0)
    {
        perror("fork error");
        return 1;
    }

    if (pid==0)
    {
        //接受消息
        char buf[128]={0};
        close(fd[1]);//关闭写入
        while (1)
        {
            int bytes = read(fd[0],buf,128);
            if (bytes<=0)
            {
                break;
            }
            printf("child receive:%s\n",buf);
            memset(buf,0,128);
        }
        close(fd[0]);//关闭读取
    }
    else
    {
        //关闭读取
        close(fd[0]);
        char buf[128] = {0};
        //发送信息
        while (1)
        {
            printf("please input string\n");
            fgets(buf,128,stdin);
            if (strcmp(buf,"/exit\n")==0)
            {
                printf("parent is ending...\n");
                break;
            }
            write(fd[1],buf,strlen(buf)+1);//+1就是加一个'\0'
            usleep(100);
            memset(buf,0,128);
        }
        close(fd[1]);//关闭写入
        wait(NULL);
    }
    

    return 0;
    
}