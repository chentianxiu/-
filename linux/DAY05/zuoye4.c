#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    int fd_1[2]; // 用于父进程向子进程发送数据
    // 创建管道
    if (pipe(fd_1) < 0)
    {
        perror("pipe error");
        return 1;
    }

    // 创建子进程
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork error");
        return 1;
    }

    // 具体操作
    if (pid == 0) // 子进程
    {
        close(fd_1[1]); // 关闭第一轮的写
        while (1)
        {
            char str[128] = {0};
            if (read(fd_1[0], str, 128) > 0) // 从管道中读取
            {
                FILE *fp = popen(str, "r");
                char buf[128] = {0};
                while (1)
                {
                    int res = fread(buf, 1, 1, fp);
                    if (res <= 0)
                    {
                        break;
                    }
                    printf("%s", buf);
                    memset(buf, 0, sizeof(buf));
                }
                printf("\n");
                pclose(fp);
            }
            else
            {
                break; // 第一轮没有数据就退出
            }
        }
        close(fd_1[0]);
    }
    else
    { // 父进程

        close(fd_1[0]); // 关闭第一轮的读
        char str[128] = {0};
        printf("请输入指令\n");
        fgets(str, 128, stdin);
        //str[strlen(str)]='\0';
        write(fd_1[1], str, strlen(str) + 1);

        close(fd_1[1]);
        wait(NULL);
    }
    return 0;
}