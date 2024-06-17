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
    //两个管道，一个a到b只写，一个b到a只读
    int fd_af = open("atob",O_WRONLY);
    int fd_as = open("btoa",O_RDONLY);
    if (fd_af<0||fd_as<0)
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
        //a 向 b 发送消息
        while (1)
        {
            char buf[128]={};
            system("clear");
            printf("a send:");
            fgets(buf,128,stdin);
            write(fd_af,buf,strlen(buf)+1);
            if (strcmp(buf,"/exit\n")==0)
            {
                break;
            }
            close(fd_af);
        }
        
    }else{
        while (1)
        {
            //b 向 a 发送消息，a接受
            char buf[128]={};
            int bytes = read(fd_as,buf,128);
            if(bytes<=0){
                break;
            }
            if(strcmp(buf,"/exit\n")==0){
                break;
            }
            system("clear");
            printf("a receive:%s\n",buf);
            printf("a send: ");
            fflush(stdout);
        }
        close(fd_as);
        wait(NULL);
    }
    return 0;

}