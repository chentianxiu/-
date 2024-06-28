#ifndef _SERVER_H_
#define _SERVER_H_

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

int server_sockfd;

//创建套接字
void socket_create();

//配置服务器地址
void set_serveraddr(struct sockaddr_in* serveraddr);

//接受客户端连接请求
void deal(int server_sockfd);


#endif
