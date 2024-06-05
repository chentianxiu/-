#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

//将“My dream”打印到文件“text.txt”中.
//然后将文件用fcntl函数改为追加方再将“My Lady .....”打印在文件中.
//最终文件中出现“My dream My Lady.....”. 

int main(int argc,char *argv[])
{
    int fd = open(argv[1],O_WRONLY|O_APPEND);//可读可写
    if (fd<=0)
    {
        perror("open error");
        return 0;
    }//判断文件是否打开
    //对文件进行追加读写操作
    //int flags = fcntl(fd,F_GETFL,0);
    //flags = flags|O_WRONLY|O_APPEND;//只写，追加 |管道符
    //fcntl(fd,F_SETFL,flags);

    write(fd,"my lady...",strlen("my lady..."));
    close(fd);

    return 0;
}