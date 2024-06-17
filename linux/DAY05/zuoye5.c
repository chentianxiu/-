#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void childProcess(int fd)
 {
    char buff[128];
    // 从管道中读取消息
    if (read(fd, buff, sizeof(buff)) > 0)
    {
        printf("child %d received:%s\n", getpid(), buff);
    }
    close(fd);
    //exit(0);
 }

int main()
{
    int fd[3][2];
    pid_t pids[3];
     // 创建多个管道
    for (int i = 0; i < 3; i++) {
        if (pipe(fd[i]) < 0) {
            perror("pipe error");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        pids[i] = fork();
        if (pids[i] < 0)
        {
            perror("fork error");
            return 1;
        }
        if (pids[i] == 0)
        {
            close(fd[i][1]);//关闭写端口
            childProcess(fd[i][0]);
            break;
        }
    }
    if(pids[0]>0||pids[1]>0||pids[2]>0){
    // 父进程操作
    for (int i = 0; i < 3; i++) {
        close(fd[i][0]); // 关闭读端
    }

    const char *msg = "hello ,i am parent!";

    for (int i = 0; i < 3; i++) {
        write(fd[i][1], msg, strlen(msg));
        close(fd[i][1]);
    }

    // 等待子进程结束
    for (int i = 0; i < 3; i++)
    {
        if (wait(NULL) < 0) {
            perror("wait error");
        }
    }

    printf("所有的子进程都结束了\n");
    }

    return 0;
}