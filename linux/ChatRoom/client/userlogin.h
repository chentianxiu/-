#ifndef _USERLOGIN_H_
#define _USERLOGIN_H_

#include <netdb.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <fcntl.h>
#include <pthread.h>
#include "data_type.h"

void sig_handler2(int signo);

//读取聊天的线程函数
void fun(int arg);


//界面函数
void function2(int client_sockfd,Data data);

//shell命令函数
void shellsym(int client_sockfd,Data data);

//聊天函数-单聊
void single_chat(int client_sockfd,Data data);

//聊天函数-群聊
void group_chat(int client_sockfd,Data data);

// 管理群聊用户
void root_online(int client_sockfd,Data data);

//猜拳
void user_mora(int client_sockfd,Data data);

// 接受猜拳
void user_moraback(int client_sockfd, Data data);

//查看在线用户
void user_online(int client_sockfd,Data data);

//退出登录
void user_updown(int client_sockfd,Data data);

#endif