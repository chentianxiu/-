#ifndef _DEAL_H_
#define _DEAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <netdb.h>
#include <memory.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <pthread.h>
#include <time.h>
#include <errno.h>

#include "../data_type/data_type.h"

FILE* fp_log;//日志文件指针

pthread_mutex_t mutex;//互斥锁

//信号捕捉函数
void sig_handler(int signo);

//用户结构体链表
typedef struct user{
    int type;
    char name[20];
    char pwd[20];
}User;
typedef struct user_link{
    User data;
    struct user_link* next;
}User_link;
User_link* userhead;

//用户在线链表
typedef struct conv{
    char username[20];//用户名
    char client_ip[20];//用户ip
    char login_time[30];//登录时间
    int client_sockfd;//用户套接字
    int flag;//用户状态
}Conv;
typedef struct conv_link{
    Conv data;
    struct conv_link* next;
}Conv_link;
Conv_link* convhead;

//用户心跳结构体
typedef struct heart{
    int client_sockfd;
    int count;
}Heart;

//心跳异常处理
void* heart_fun(void* arg);

//线程调用
void read_fun(int arg);

//输出客户端地址信息
void out_addr(struct sockaddr_in* clientaddr);

//登录数据包处理
void login_type(Data data,int client_sockfd);
void login_case1(Data data,int client_sockfd,User_link* userhead,Conv_link* convhead);
void login_case2(Data data,int client_sockfd,User_link* userhead,Conv_link* convhead);
//会话链表插入函数
void insert_conv(Data data,int client);

//注册数据包处理
void regist_type(Data data,int client_sockfd);

//命令数据包处理
void command_type(Data data,int client_sockfd);

//在线用户数据包处理
void online_type(Data data,int client_sockfd);

//用户聊天
void chat_singal_type();
void chat_group_type();

//删除在线节点
void delete_node(Data data);

//用户信息载入保存
void load_user();
void save_user();
void insert_user(User data);

//获取当前时间
char* time_record();

//注销链表处理
void destroy_User_link();
void destroy_Conv_link();

#endif
