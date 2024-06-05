#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main()
{
    int fd = open("a.txt",O_WRONLY|O_APPEND);//只写，追加
    if (fd<=0)
    {
        perror("open error");
        return 1;
    }
    //更改描述符
    int flags = fcntl(fd,F_GETFL,0);
    flags = flags|O_WRONLY;//只写权限
    fcntl(fd,F_SETFL,flags);

    write(fd,"Hello world",strlen("Hello world"));
    close(fd);

    return 0;   
}