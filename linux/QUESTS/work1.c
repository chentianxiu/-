#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

typedef struct shm
{
    int arr[5];
    int wflag;
    int rflag;
} Shm;

int main()
{
    key_t mykey = ftok("work1.c", 1);
    int shmid = shmget(mykey, sizeof(struct shm), IPC_CREAT | 0666);
    if (shmid < 0)
    {
        perror("shm error");
        return 1;
    }
    Shm *shm_buf = shmat(shmid, NULL, 0);
    memset(shm_buf, 0, sizeof(Shm));
    if (shm_buf == NULL)
    {
        perror("link error\n");
        return 1;
    }
    pid_t pid;
    int i;
    for (i = 0; i < 2; i++)
    {
        pid = fork();
        if (pid < 0)
        {
            perror("fork error\n");
            return 1;
        }
        if (pid == 0)
        {
            break;
        }
    }
    if (pid == 0 && i == 0)
    {
        // 子进程接受并且累加

        
        shm_buf->rflag = 1;
        while (shm_buf->rflag == 1)
            ;
        //usleep(100);
        int num = 0;
        for (int i = 0; i < 5; i++)
        {
            printf("%d ", shm_buf->arr[i]);
            // read(STDOUT_FILENO,&shm_buf->arr[i],sizeof(int));
            fflush(stdout);
            num += shm_buf->arr[i];
        }
        printf("\n");
        int fd = open("fifo", O_WRONLY);
        if (fd < 0)
        {
            perror("open fifo error\n");
            return 1;
        }
        write(fd, &num, sizeof(int));
        close(fd);
        shmdt(shm_buf);
        shmctl(shmid, IPC_RMID, NULL);
    }
    else if (pid == 0 && i == 1)
    {
        // 打印累加的结果
        int num = 0;
        int fd = open("fifo", O_RDONLY);
        if (fd < 0)
        {
            perror("open fifo error\n");
            return 1;
        }
        read(fd, &num, sizeof(int));
        printf("累加为：%d\n", num);
        close(fd);
    }
    else
    {
        // 随机生成数字
        // Shm *shm_buf = shmat(shmid, NULL, 0);
        // if (shm_buf == NULL)
        // {
        //     perror("link error\n");
        //     return 1;
        // }
        // memset(shm_buf, 0, sizeof(Shm));
        // shm_buf->rflag == 1;
        srand((unsigned)time(0));
        // while(shm_buf->rflag == 1);
        for (int i = 0; i < 5; i++)
        {
            shm_buf->arr[i] = rand() % 20;
            printf("%d ", shm_buf->arr[i]);
        }
        printf("\n");
        // printf("%d\n",shm_buf->arr[0]);
        shm_buf->rflag = 0;
        wait(NULL);
        wait(NULL);
        shmdt(shm_buf);
        shmctl(shmid, IPC_RMID, NULL);
    }
    return 0;
}
