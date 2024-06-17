#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

double calculate_average(const char* str) {
    int sum = 0;
    int count = 0;

    // 复制字符串以免改变原来的字符值
    char* str_copy = strdup(str);
    if (str_copy == NULL) {
        perror("strdup failed");
        exit(EXIT_FAILURE);
    }

    char* token = strtok(str_copy, "-");
    while (token != NULL) {
        sum += atoi(token);
        count++;
        token = strtok(NULL, "-");
    }

    free(str_copy);

    if (count == 0) {
        return 0.0; // Avoid division by zero
    }

    return (double)sum / count;
}

int main(){

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
        // 打开管道读取端
        int fd;
        fd = open("namepipe", O_RDONLY);
        if (fd < 0) {
            perror("open fifo for read error");
            return 1;
        }
        while (1)
        {
            char str[128]={0};
            if (read(fd,str,128)>0)//从管道中读取
            {
                double avg = calculate_average(str);
                printf("平均值是%.2lf\n",avg);
            }else{
                break;//第一轮没有数据就退出
            }
        }
        close(fd);

    }else{//父进程
        // 打开管道写入端
        int fd;
        fd = open("namepipe", O_WRONLY);
        if (fd < 0) {
            perror("open fifo for write error");
            return 1;
        }
        char str[128]={0};
        printf("请输入一串数,中间用-隔开\n");
        fgets(str,128,stdin);

        write(fd,str,strlen(str)+1);

        close(fd);
        wait(NULL);
    }
    return 0;
}