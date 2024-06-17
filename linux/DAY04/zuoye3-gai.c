#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

pid_t pid1, pid2;
volatile sig_atomic_t flag1 = 1;
volatile sig_atomic_t flag2 = 1;

void handle_signal_from_parent(int sig) {
    if (sig == SIGUSR1) {
        printf("第一个子进程收到父进程的信号\n");
        kill(pid2, SIGUSR2); // 向第二个子进程发送信号
        flag1 = 0;
    }
}

void handle_signal_from_sibling(int sig) {
    if (sig == SIGUSR2) {
        printf("第二个子进程收到第一个子进程的信号\n");
        flag2 = 0;
    }
}

int main() {
    pid1 = fork();
    if (pid1 < 0) {
        perror("fork error");
        exit(EXIT_FAILURE);
    }
    
    if (pid1 == 0) { // 第一个子进程
        struct sigaction sa1;
        sa1.sa_handler = handle_signal_from_parent;
        sa1.sa_flags = 0;
        sigemptyset(&sa1.sa_mask);
        if (sigaction(SIGUSR1, &sa1, NULL) == -1) {
            perror("sigaction error");
            _exit(1);
        }
        while (flag1);
        _exit(0);
    } else {
        pid2 = fork();
        if (pid2 < 0) {
            perror("fork error");
            exit(EXIT_FAILURE);
        }
        
        if (pid2 == 0) { // 第二个子进程
            struct sigaction sa2;
            sa2.sa_handler = handle_signal_from_sibling;
            sa2.sa_flags = 0;
            sigemptyset(&sa2.sa_mask);
            if (sigaction(SIGUSR2, &sa2, NULL) == -1) {
                perror("sigaction error");
                _exit(1);
            }
            while (flag2);
            _exit(0);
        } else { // 父进程
            sleep(2); // 等待子进程准备好
            printf("父进程向第一个子进程发送信号\n");
            kill(pid1, SIGUSR1); // 向第一个子进程发送信号
            
            // 等待两个子进程结束
            wait(NULL);
            wait(NULL);
            printf("父进程: 所有子进程已结束\n");
        }
    }
    
    return 0;
}
