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
    //创建管道的写入端
    int fd = open("namepipe",O_WRONLY);
    if (fd<0)
    {
        perror("open error");
        return 1;
    }
    while (1)
    {
        char buf[128]={0};
        printf("please input:");
        fgets(buf,128,stdin);

        if (strcmp(buf,"/exit\n")==0)
        {
            break;
        }
        write(fd,buf,strlen(buf));
    }
    close(fd);
    
}