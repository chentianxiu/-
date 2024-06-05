#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char *argv[])
{
    int fd_r = open(argv[1],O_RDONLY);
    if (fd_r <0)
    {
        perror("文件[a.txt]打开失败");
        return 1;
    }
    int fd_w = open(argv[2],O_WRONLY|O_CREAT,0666);
    if (fd_w < 0)
    {
        perror("文件[b.txt]打开失败");
        return 1;
    }
    char buf[128] = {0};
    int bytes = 0;
    while (1)
    {
        bytes = read(fd_r,buf,127);
        if(bytes<=0)
			break;
        printf("%s",buf);
		fflush(stdout);//清除缓存

        write(fd_w,buf,bytes);
        memset(buf,0,128);

    }
    close(fd_r);
    close(fd_w);
    return 0;
}