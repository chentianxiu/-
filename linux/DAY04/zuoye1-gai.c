#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include<sys/wait.h>

// 子进程处理 SIGUSR2 信号的处理函数
void handle_sigusr2(int sig) {
    printf("子进程: 收到 SIGUSR2 信号\n");
}

// 子进程处理 SIGUSR1 信号的处理函数
void handle_sigusr1(int sig) {
    printf("子进程: 收到 SIGUSR1 信号\n");

    // 设置处理 SIGUSR2 信号的处理函数
    signal(SIGUSR2, handle_sigusr2);
    printf("子进程: 已设置 SIGUSR2 的处理程序\n");
}

int main() {
    pid_t pid;

    // 创建子进程
    pid = fork();

    if (pid < 0) {
        // 创建子进程失败
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // 子进程
        printf("子进程: PID = %d\n", getpid());

        // 设置处理 SIGUSR1 信号的处理函数
        signal(SIGUSR1, handle_sigusr1);

        // 无限循环等待信号
        while (1) {
            pause(); // 等待信号
        }
    } else {
        // 父进程
        printf("父进程: PID = %d, 子进程 PID = %d\n", getpid(), pid);

        // 发送 SIGUSR1 信号给子进程
        sleep(1); // 等待子进程设置信号处理程序
        kill(pid, SIGUSR1);
        printf("父进程: 已发送 SIGUSR1 信号给子进程\n");

        // 发送 SIGUSR2 信号给子进程
        sleep(1); // 等待子进程设置新的信号处理程序
        kill(pid, SIGUSR2);
        printf("父进程: 已发送 SIGUSR2 信号给子进程\n");

        // 等待子进程结束
        wait(NULL);
    }

    return 0;
}
