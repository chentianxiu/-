#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>

struct buf
{
    char buf[100];
    int wflag;
    int rflag;
};

int calculate_sum(const char *str)
{
    int sum = 0;
    int count = 0;

    // 复制字符串以免改变原来的字符值
    char *str_copy = strdup(str);
    if (str_copy == NULL)
    {
        perror("strdup failed");
        exit(EXIT_FAILURE);
    }

    char *token = strtok(str_copy, "-");
    while (token != NULL)
    {
        sum += atoi(token);
        count++;
        token = strtok(NULL, "-");
    }

    free(str_copy);

    if (count == 0)
    {
        return 0; // Avoid division by zero
    }

    return sum;
}

int main()
{
    // 创建共享内存
    key_t mykey = ftok("1-practise.c", 1);

    int shmid = shmget(mykey, sizeof(struct buf), IPC_CREAT | 0666);
    if (shmid < 0)
    {
        perror("shm error");
        return 1;
    }
    // 创建管道
    int fd[2];
    if (pipe(fd) < 0)
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

    if (pid == 0)
    {
        // 连接共享内存
        struct buf *shm_buf = shmat(shmid, NULL, 0);
        if (shm_buf == NULL)
        {
            perror("link error");
            return 1;
        }
        // 初始化
        memset(shm_buf, 0, sizeof(struct buf));
        int sum = 0;

        // 关闭管道读端
        close(fd[0]);

        shm_buf->rflag = 1;
        // 向共享内存中读取
        while (1)
        {
            
            while (shm_buf->rflag == 1)
                ; // 0 can read,1就卡在这
            if (strcmp(shm_buf->buf, "/exit\n") == 0)
            {
                break;
            }
            printf("recived:%s\n", shm_buf->buf);
            sum = calculate_sum(shm_buf->buf);
            //printf("数字的和为:%d", sum);
            write(fd[1], &sum, sizeof(sum));
            // fgets(shm_buf->buf,128,stdin);
            shm_buf->rflag = 1;
            shm_buf->wflag = 0;
        }
        close(fd[1]);   // 关闭管道的写入端口
        shmdt(shm_buf); // 断开共享内存连接
        exit(0);
    }
    else
    {
        struct buf *shm_buf = shmat(shmid, NULL, 0); // 连接共享内存
        if (shm_buf == NULL)
        {
            perror("link error");
            return 1;
        }
        // 初始化
        memset(shm_buf, 0, sizeof(struct buf));
        //关闭管道写入端
        close(fd[1]);
        int sum=0;
        // 向共享内存中写入
        while (1)
        {
            while (shm_buf->wflag == 1)
                ; // 0 can write
            printf("请输入一串数,中间用-隔开:");
            fgets(shm_buf->buf, 100, stdin);
            shm_buf->wflag = 1;
            shm_buf->rflag = 0;
            if (strcmp(shm_buf->buf, "/exit\n") == 0)
            {
                break;
            }
            usleep(10000);
            //从管道中读取
            read(fd[0],&sum,sizeof(sum));
            printf("父进程接收到的和是:%d",sum);
            
        }
        close(fd[0]);
        shmdt(shm_buf);
        wait(NULL);
    }
    shmctl(shmid,IPC_RMID,NULL);//删除共享内存 remove shm

    // struct buf* shm_buf = shmat(shmid,NULL,0);

    return 0;
}