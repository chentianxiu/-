#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
    int fd = open("zuoye1.txt",O_WRONLY);//可读可写
    if (fd<=0)
    {
        perror("open error");
        return 1;
    }//判断文件是否打开
    
    //fd现在变成了输出流，所以，下面的good moning写在了文件里
    dup2(fd,STDOUT_FILENO);

    
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d*%d=%d ",j,i,i*j);
        }
        printf("\n");
    }
    

    fflush(stdout);
    //重新定向输出流，下面打印到了终端
    freopen("/dev/tty","w",stdout);

    printf("write OK\n");

    return 0;
}