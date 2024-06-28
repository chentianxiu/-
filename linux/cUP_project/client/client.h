#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include <conio.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <netdb.h>
#include <memory.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "../data_type/data_type.h"

// 中断处理
void handler(int signo);

// 用户界面
void func();

// 用户注册
void regist();

// 用户登录
void login();

// 登录验证码
void login_captcha(char *arr);

/*// 密码保护
void password_preserve(char *password, int num);
*/
//用户选择界面
void choose();

//客戶端命令
void shellSercer();

//聊天读取线程
void* funCommun();

#endif
