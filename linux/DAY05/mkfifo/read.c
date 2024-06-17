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
    //创建管道
    int fd = open("namepipe",O_RDONLY);
    if (fd<0)
    {
        perror("open error");
        return 1;
    }

    while (1)
    {
        //管道的读写端,用来获取管道另一端的内容
        char buf[128]={0};
        int bytes = read(fd,buf,128);
        if (bytes<=0)
        {
            break;
        }
        printf("received:%s\n",buf);

    }
    close(fd);
    
}