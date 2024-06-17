#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>

//将小写字符串转换为大写
void Upstr(char *str)
{
    while (*str!='\0')
    {
        if (*str>='a'&&*str<='z')
        {
            *str = *str - 32;
        }
        str++;
    }
    
}

int main()
{
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
        // 打开管道读取端
        int fd;
        fd = open("namepipe", O_RDONLY);
        if (fd < 0) {
            perror("open fifo for read error");
            return 1;
        }
        while (1)
        {
            int bytes = read(fd,buf,128);
            if (bytes<=0)
            {
                break;
            }
            Upstr(buf);
            printf("child receive:%s\n",buf);
            memset(buf,0,128);
        }
        close(fd);//关闭读取
    }
    else
    {
        char buf[128] = {0};
        // 打开管道写入端
        int fd;
        fd = open("namepipe", O_WRONLY);
        if (fd < 0) {
            perror("open fifo for write error");
            return 1;
        }
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
            write(fd,buf,strlen(buf)+1);//+1就是加一个'\0'
            usleep(100);
            memset(buf,0,128);
        }
        close(fd);//关闭写入
        wait(NULL);
    }
    

    return 0;
    
}