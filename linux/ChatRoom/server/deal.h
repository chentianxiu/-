#ifndef _DEAL_H_
#define _DEAL_H_

//系统头文件
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<netdb.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<memory.h>
#include<signal.h>
#include<time.h>
#include<errno.h>
#include<arpa/inet.h>
#include<pthread.h>
#include "data_type.h"

extern  FILE * fp_log;//定义日志文件的文件指针(全局变量)

extern  pthread_mutex_t mutex;//互斥锁定义为全局变量

//信号捕捉函数

void sig_handler(int signo);

//用户结构体-链表
typedef struct user
{
    int type;
    char username[20];
    char passwd[20];
}User;

typedef struct userlink
{
    User data;
    struct userlink * next;
}Userlink;

extern Userlink * userhead;

//会话记录结构体链表

typedef struct chat
{
    char username[20];  //登录用户
    char client_ip[20]; //用户ip
    char login_time[30];   //登录时间
    int client_sockfd;  //登录客户端的套接字
    int flag;       //0就是普通用户，1就是管理员
}Chat;

typedef struct chatlink
{
    struct chat data;
    struct chatlink* next;
}Chatlink;

extern Chatlink * chathead;

//心跳数据结构体

typedef struct heart
{
    int client_sockfd;
    int count;
}Heart;


//心跳异常处理函数
void * heart_fun(void *arg);

//客户端线程调用函数
void  readfun(int arg);

//输出客户端地址信息
void out_addr(struct sockaddr_in* clientaddr);

//登录数据包处理
void login_type(Data data,int client_sockfd);//登录数据包处理函数

//void login_case1(Data data,int client_sockfd);//登录附属函数1

//void login_case2(Data data,int client_sockfd);//登录附属函数2

void insert_chat(Data data,int client_sockfd);//会话链表插入函数


//注册数据包处理函数
void regist_type(Data data,int client_sockfd);

//命令数据包处理函数
void command_type(Data data,int client_sockfd);

//在线用户数据包处理函数
void online_type(Data data,int client_sockfd);

//用户聊天函数
void chat_single_type(Data data,int client_sockfd);
void chat_group_type(Data data,int client_sockfd);

//管理群聊函数(添加禁言)
void chat_root_group(Data data,int client_sockfd);

//管理群聊函数(解除禁言)
void chat_uroot_group(Data data,int client_sockfd);

//发起猜拳
void users_mora(Data data,int client_sockfd);

//接受猜拳
void users_moraback(Data data,int client_sockfd);

//删除在线节点函数
void delete_node(Data data);
//用户信息载入保存函数
void load_user();
void save_user();
void insert_user(User data);

//获取当前时间函数
char *time_record();

//注销用户链表处理函数
void destroy_Userlink();
//注销会话链表
void destroy_Chatlink();

#endif