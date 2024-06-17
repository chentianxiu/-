#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;

    // 创建第一个子进程
    pid1 = fork();
    if (pid1 < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid1 == 0) {
        // 子进程1
        printf("Child 1 (PID: %d) is running\n", getpid());
        sleep(2); // 模拟工作
        exit(42); // 以状态码42退出
    }

    // 创建第二个子进程
    pid2 = fork();
    if (pid2 < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid2 == 0) {
        // 子进程2
        printf("Child 2 (PID: %d) is running\n", getpid());
        sleep(4); // 模拟工作
        exit(43); // 以状态码43退出
    }

    // 父进程等待子进程1结束
    int status;
    pid_t wpid = wait(&status);
    if (wpid == -1) {
        perror("wait failed");
        exit(EXIT_FAILURE);
    }
    if (WIFEXITED(status)) {
        printf("Child 1 (PID: %d) exited with status %d\n", wpid, WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        printf("Child 1 (PID: %d) was killed by signal %d\n", wpid, WTERMSIG(status));
    }

    // 父进程等待子进程2结束
    wpid = wait(&status);
    if (wpid == -1) {
        perror("wait failed");
        exit(EXIT_FAILURE);
    }
    if (WIFEXITED(status)) {
        printf("Child 2 (PID: %d) exited with status %d\n", wpid, WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        printf("Child 2 (PID: %d) was killed by signal %d\n", wpid, WTERMSIG(status));
    }

    printf("All child processes have exited.\n");

    return 0;
}
