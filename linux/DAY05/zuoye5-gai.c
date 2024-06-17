#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NUM_CHILDREN 3
#define BUF_SIZE 256

void child_process(int fd) {
    char buffer[BUF_SIZE];

    // 关闭写端
    close(fd + 1);

    // 从管道中读取消息
    int nbytes = read(fd, buffer, sizeof(buffer) - 1);
    if (nbytes > 0) {
        buffer[nbytes] = '\0'; // 确保字符串以null结尾
        printf("Child %d received: %s\n", getpid(), buffer);
    }

    // 关闭读端
    close(fd);
    exit(0);
}

int main() {
    int pipefds[NUM_CHILDREN][2];
    pid_t pids[NUM_CHILDREN];

    // 创建多个管道
    for (int i = 0; i < NUM_CHILDREN; i++) {
        if (pipe(pipefds[i]) == -1) {
            perror("pipe error");
            exit(EXIT_FAILURE);
        }
    }

    // 创建子进程
    for (int i = 0; i < NUM_CHILDREN; i++) {
        pids[i] = fork();
        if (pids[i] < 0) {
            perror("fork error");
            exit(EXIT_FAILURE);
        }
        if (pids[i] == 0) {
            // 子进程
            close(pipefds[i][1]); // 关闭写端
            child_process(pipefds[i][0]);
        }
    }

    // 父进程
    for (int i = 0; i < NUM_CHILDREN; i++) {
        close(pipefds[i][0]); // 关闭读端
    }

    // 发送消息给所有子进程
    const char *message = "Hello, child processes!";
    for (int i = 0; i < NUM_CHILDREN; i++) {
        write(pipefds[i][1], message, strlen(message));
        close(pipefds[i][1]); // 关闭写端
    }

    // 等待所有子进程结束
    for (int i = 0; i < NUM_CHILDREN; i++) {
        wait(NULL);
    }

    printf("Parent process: All child processes have exited.\n");

    return 0;
}
