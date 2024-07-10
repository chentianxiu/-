#ifndef _SERVER_H_
#define _SERVER_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <memory.h>
#include <signal.h>
#include <time.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <errno.h>
#include <malloc.h>
#include "data_type.h"
//服务器套接字，定义全局变量

extern int server_sockfd;

//创建套接字函数
void socket_creat();

//填充服务器地址信息函数
void set_serveraddr(struct sockaddr_in* serveraddr);

//接受处理客户端信息函数
void deal(int server_sockfd);

#endif