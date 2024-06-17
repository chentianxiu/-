#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int fd_1[2];//用于父进程向子进程发送数据
    int fd_2[2];//用于子进程向父进程发送数据


    //创建管道
    if (pipe(fd_1)<0||pipe(fd_2)<0)
    {
        perror("pipe error");
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
        close(fd_1[1]);//关闭第一轮的写和第二轮的读
        close(fd_2[0]);

        while (1)
        {
            int num;
            if (read(fd_1[0],&num,sizeof(num))>0)//从管道中读取
            {
                num *= 2;
                write(fd_2[1],&num,sizeof(num));
            }else{
                break;//第一轮没有数据就退出
            }
        }
        close(fd_1[0]);
        close(fd_2[1]);
    }else{//父进程
        close(fd_1[0]);//关闭第一轮的读和第二轮的写端
        close(fd_2[1]);
        srand(time(NULL));//初始化随机数生成器

        for (int i = 0; i < 5; i++)
        {
            int num = rand()%100;
            write(fd_1[1],&num,sizeof(num));
            printf("父进程发送:%d\n",num);

            if (read(fd_2[0],&num,sizeof(num))>0)
            {
                printf("父进程接受:%d\n",num);
            }
            
        }
        close(fd_1[1]);
        close(fd_2[0]);
        wait(NULL);
    }
    return 0;
}