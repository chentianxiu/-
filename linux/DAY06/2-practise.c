#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/wait.h>

struct buf
{
    char buf[128];
    int wflag;
    int rflag;
};

int main()
{
    key_t mykey = ftok("2-practise.c", 1); // get key
    // 创建虚拟内存
    int shmid = shmget(mykey, sizeof(struct buf), IPC_CREAT | 0666);
    if (shmid < 0)
    {
        perror("shm error");
        return 1;
    }
    // 连接共享内存
    struct buf *shm_buf = shmat(shmid, NULL, 0);
    if (shm_buf == NULL)
    {
        perror("link error");
        return 1;
    }

    // 初始化
    memset(shm_buf, 0, sizeof(struct buf));
    shm_buf->rflag = 1;
    shm_buf->wflag = 0;

    // 创建子进程
    pid_t pid[4];
    // struct buf * shm_buf[4];
    for (int i = 0; i < 4; i++)
    {
        pid[i] = fork();
        if (pid[i] < 0)
        {
            perror("fork error");
            return 1;
        }
        if (pid[i] == 0)
        {
            // 向共享内存中读取
            while (1)
            {
                while (shm_buf->rflag == 1)
                    ; // 0 can read,1就卡在这
                if (strcmp(shm_buf->buf, "/exit") == 0)
                {
                    break;
                }
                printf("child:%d recived:%s\n", getpid(), shm_buf->buf);
                // fgets(shm_buf->buf,128,stdin);
                shm_buf->rflag = 1;
                shm_buf->wflag = 0;
                usleep(10000);
            }
            shmdt(shm_buf); // 断开连接
            exit(0);
        }
    }

    if (pid[0] > 0)
    {

        // struct buf *shm_buf = shmat(shmid, NULL, 0); // 连接共享内存
        // if (shm_buf == NULL)
        // {
        //     perror("link error");
        //     return 1;
        // }
        // // 初始化
        // memset(shm_buf, 0, sizeof(struct buf));

        // 向共享内存中写入
        char str[128] = {0};
        while (1)
        {
             while (shm_buf->wflag == 1)
                ; // 0 can write

            printf("please input:");
            fgets(str, 128, stdin);
            str[strcspn(str, "\n")] = '\0'; // Remove newline character
            if (strcmp(str, "/exit") == 0)
            {
                strcpy(shm_buf->buf, str);
                shm_buf->wflag = 1;
                shm_buf->rflag = 0;
                break;
            }
            strcpy(shm_buf->buf, str);
            shm_buf->wflag = 1;
            shm_buf->rflag = 0;
            sleep(1);
        }

        for (int i = 0; i < 4; i++)
        {
            wait(NULL);
        }
        shmdt(shm_buf); // 断开连接
        shmctl(shmid, IPC_RMID, NULL); // 删除共享内存 remove shm
    }

    return 0;
}