#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>


int main(){
    
    //创建通道
    int fd[2];
    if (pipe(fd) < 0)
    {
        perror("Failed to create pipe");
        return 1;
    }

    //创建子进程
    pid_t pid = fork();
    if (pid<0)
    {
        perror("fork error");
        return 1;
    }

    //具体操作
    if (pid==0)//子进程
    {
        close(fd[1]);//关闭写入端口
        // 打开文件读取
        int fd_w;
        fd_w = open("b.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
        if (fd_w < 0) {
            perror("文件[b.txt]打开失败");
            return 1;
        }
        char str[128]={0};
        int bytes;
        while (1)
        {
            bytes = read(fd[0],str,sizeof(str));
            if (bytes>0)//从管道中读取
            {
                write(fd_w, str, bytes);
            }else{
                break;//第一轮没有数据就退出
            }
        }
        close(fd[0]);
        close(fd_w);
        exit(0);
    }else{//父进程
        // 打开文件写入端
        close(fd[0]);
        int fd_r;
        fd_r = open("a.txt", O_RDONLY);
        if (fd_r < 0) {
            perror("文件[a.txt]打开失败");
            return 1;
        }
        char str[128]={0};
        int bytes;
        while ((bytes = read(fd_r,str,sizeof(str)))>0)
        {
            usleep(100);
            write(fd[1],str,bytes);
        }

        close(fd_r);
        close(fd[1]);
        wait(NULL);
    }
    return 0;
}