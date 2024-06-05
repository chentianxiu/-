/*************************************************************************
	> File Name: zhongdun.c
	> Author: chenliang
	> Mail: 2779783956@qq.com 
	> Created Time: Tue 04 Jun 2024 01:08:28 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	//从终端输入，获取终端输入再输出到终端
	write(STDOUT_FILENO,"please input:",strlen("please input:"));

	char buf[128]={};
	
	int bytes = read( STDIN_FILENO,buf,127);

	write(STDOUT_FILENO,buf,bytes);
	return 0;

}

