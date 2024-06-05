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
    
    //fd现在变成了输出流，所以，下面的good moning写在了文件里
    dup2(fd,STDOUT_FILENO);

    printf("good morning\n");

    fflush(stdout);
    //重新定向输出流，下面打印到了终端
    freopen("/dev/tty","w",stdout);

    printf("misson completed\n");

    return 0;
}