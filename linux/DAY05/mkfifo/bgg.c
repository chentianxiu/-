#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    //两个管道，一个b到a只写，一个a到b只读
    int fd_bs = open("atob",O_RDONLY);
    int fd_bf = open("btoa",O_WRONLY);
    
    if (fd_bf<0||fd_bs<0)
    {
        perror("open error");
        return 1;
    }
    //创建一个子进程，一个读取，一个写入,实现通信

    pid_t pid = fork();

    if(pid<0)
    {
        perror("fork error");
        return 1;
    }
    if (pid==0)
    {
        //b 向 a 发送消息
        while (1)
        {
            char buf[128]={};
            system("clear");
            printf("b send:");
            fgets(buf,128,stdin);
            write(fd_bf,buf,strlen(buf)+1);
            if (strcmp(buf,"/exit\n")==0)
            {
                break;
            }
            close(fd_bf);
        }
        
    }else{
        while (1)
        {
            //a 向 b 发送消息，b接受
            char buf[128]={};
            int bytes = read(fd_bs,buf,128);
            if(bytes<=0){
                break;
            }
            if(strcmp(buf,"/exit\n")==0){
                break;
            }
            system("clear");
            printf("b receive:%s\n",buf);
            printf("b send: ");
            fflush(stdout);
        }
        close(fd_bs);
        wait(NULL);
    }
    return 0;

}