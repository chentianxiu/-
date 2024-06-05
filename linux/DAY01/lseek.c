#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>

int main()
{
    int fd = open("fcntl.c",O_RDONLY);
    if (fd<=0)
    {
        perror("open error!");
        return 1;
    }
    //获取文件大小
    int size = lseek(fd,0,SEEK_END);
    printf("%d\n",size);
    //off_t lseek(int fd, off_t offset, int whence);
    // fd: 文件描述符，标识要操作的文件。
    // offset: 相对于 whence 的偏移量。
    // whence: 基准位置，有以下几种取值：
    // SEEK_SET: 从文件的起始位置开始移动。
    // SEEK_CUR: 从文件指针的当前位置开始移动。
    // SEEK_END: 从文件的末尾开始移动。

    //文件一半大小
    lseek(fd,size/2,SEEK_SET);

    char buff[11] = {0};
    //读取一半的文件
    while (read(fd,buff,10)>0)
    {
        printf("%s",buff);
        fflush(stdout);
        memset(buff,0,11);
    }
    close(fd);


    return 0;
}