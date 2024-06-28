/*************************************************************************
	> File Name: 1-socket.c
	> Author: chenliang
	> Mail: 2779783956@qq.com 
	> Created Time: Wed 19 Jun 2024 09:45:01 AM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main()
{
	int socketfd = socket(AF_INET,SOCK_DGRAM,0);
	if (socketfd<0)
	{
		perror("socket error");
	}
	else{
		printf("socket %d is created!\n",socketfd);
	}
	return 0;
}

//得到的socketed 是3，这是因为0，1，2都被用掉了
//文件描述符0：标准输入，读取用户输入。
//文件描述符1：标准输出，显示正常输出。
//文件描述符2：标准错误，显示错误信息。

