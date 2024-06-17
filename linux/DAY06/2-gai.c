#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/wait.h>

struct buf {
    char buf[128];
    int wflag[4];
    int rflag[4];
};

int main() {
    key_t mykey = ftok("2-gai.c", 1); // 获取 key
    // 创建共享内存
    int shmid = shmget(mykey, sizeof(struct buf), IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shm error");
        return 1;
    }

    // 连接共享内存
    struct buf *shm_buf = shmat(shmid, NULL, 0);
    if (shm_buf == NULL) {
        perror("link error");
        return 1;
    }

    // 初始化共享内存
    memset(shm_buf, 0, sizeof(struct buf));
    for (int i = 0; i < 4; i++) {
        shm_buf->wflag[i] = 0;
        shm_buf->rflag[i] = 1;
    }

    // 创建子进程
    pid_t pid[4];
    for (int i = 0; i < 4; i++) {
        pid[i] = fork();
        if (pid[i] < 0) {
            perror("fork error");
            return 1;
        }
        if (pid[i] == 0) {
            // 子进程处理
            while (1) {
                while (shm_buf->rflag[i] == 1); // 等待父进程写入数据
                if (strcmp(shm_buf->buf, "/exit") == 0) {
                    break;
                }
                printf("child:%d received:%s\n", getpid(), shm_buf->buf);
                shm_buf->rflag[i] = 1;
                shm_buf->wflag[i] = 0;
                usleep(100); // 防止忙等待
            }
            shmdt(shm_buf); // 断开连接
            exit(0);
        }
    }

    if (pid[0] > 0) {
        // 父进程处理
        char str[128] = {0};
        while (1) {
            printf("please input: ");
            fgets(str, 128, stdin);
            str[strcspn(str, "\n")] = '\0'; // 去除换行符
            if (strcmp(str, "/exit") == 0) {
                for (int i = 0; i < 4; i++) {
                    strcpy(shm_buf->buf, str);
                    shm_buf->wflag[i] = 1;
                    shm_buf->rflag[i] = 0;
                }
                break;
            }
            for (int i = 0; i < 4; i++) {
                while (shm_buf->wflag[i] == 1); // 等待子进程读取数据
                strcpy(shm_buf->buf, str);
                shm_buf->wflag[i] = 1;
                shm_buf->rflag[i] = 0;
            }
            sleep(2);
            memset(str, 0, 128);
        }

        // 等待所有子进程结束
        for (int i = 0; i < 4; i++) {
            wait(NULL);
        }

        shmdt(shm_buf); // 断开连接
        shmctl(shmid, IPC_RMID, NULL); // 删除共享内存
    }

    return 0;
}
