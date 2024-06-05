#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


int main(int argc,char *argv[])
{
    int fd = open("dream.txt",O_WRONLY|O_APPEND);//可读可写
    if (fd<=0)
    {
        perror("open error");
        return 1;
    }//判断文件是否打开
    
    //文件描述符之复制
    int new_fd = dup(fd);

    write(new_fd,"new fd",sizeof("new_fd"));

    close(new_fd);

    close(fd);

    return 0;
}