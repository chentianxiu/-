#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

/*
运行1个程序,自动分配4G的空间(虚拟),1G内核,3G用户;
1个用户同时运行两次同一程序,ps查看进程,grep过滤,会查到2个,进程号唯一;
STAT(进程状态):D(不可中断的休眠),R(正在执行),S(休眠),T(暂停/可被追踪),Z(僵尸),W(内存不够),s(父进程),+(后台);
ping:监测网络; ctrl+z:停止进程; ctrl+c:中断进程; fg %job:唤醒到前台运行; bg %job:唤醒到后台运行(&); kill pid/%job(进程号/工作号):杀死进程;
进程的3种状态:就绪||运行态(在CUP中)->阻塞态->~(就绪);多进程时,轮流执行(排队/时间片);
system("clear");快捷键:ctrl+l;
*/
/*
pid_t pid = fork();
    fork函数,用于创建子进程,pid = 0,运行子进程,pid > 0(子进程号),运行父进程;、
wait(NULL);
    wait函数,用于等待子进程结束,避免出现孤儿进程;wait(&status),if(WIFEXITED(status)),真:正常结束,假:非正常结束;
waitpid(pid,NULL,0);
    0|WNOHANG|WUNTRACED|WUNTRACED|WCONTINUED
        0:阻塞，直到一个匹配的子进程终止;
        WNOHANG:非阻塞，如果没有已终止的子进程立即返回 0;
        WUNTRACED:如果子进程进入暂停状态也返回其状态;
        WCONTINUED:如果子进程从暂停状态恢复执行也返回其状态;
        WCONTINUED:仅等待被信号中断的子进程;
execlp("ls","ls","文件夹路径",NULL);
    execlp函数,用于在一个进程内调用另一个进程的命令;
    第一个参数:查找可执行命令;
    第二个参数~NULL:命令执行内容;
    NULL:命令结束标志;
execvp(argu[0],argu);char* argu[] = ""ls","ls","文件夹路径",NULL";
    execvp函数,用于在一个进程内调用另一个进程的命令,用法与execlp用法类似;
*/
