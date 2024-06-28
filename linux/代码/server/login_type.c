#include "data_type.h"
#include "deal.h"
#include "server.h"

//注意传参

void login_type(Data data,int client_sockfd,User_link* userhead,Conv_link* convhead) //登录数据包处理函数
{
	Conv_link* p_convhead = convhead;
	p_convhead = p_convhead->next;	//判断会话链表是否为空
	if(NULL == p_convhead)	//此时链表为空，字节插入节点;
	{
		login_case1(data,client_sockfd,userhead,convhead);	//case1处理
		return;
	}
	else	//链表不为空，要遍历，避免重复登陆
	{
		login_case2(data,client_sockfd,userhead,convhead);	//case2处理
		return;
	}
}

void login_case1(Data data,int client_sockfd,User_link* userhead,Conv_link* convhead)//会话链表为空
{
	User_link* p_userhead = userhead;
	p_userhead = p_userhead->next;
	while(NULL != p_userhead)	//遍历
	{
		if((0 == strcmp(data.username,p_userhead->data.username)) && (0 == strcmp(data.passwd,p_userhead->data.passwd)))
		{
			data.retval = 0;	//成功返回客户端0;
			write(client_sockfd,&data,sizeof(data));
			insert_conv(data,convhead,client_sockfd);	//插入会话链表
			return;
		}
		p_userhead = p_userhead->next;
	}
	data.retval = 1;	//登陆失败返回1;
	write(client_sockfd,&data,sizeof(data));
}

void login_case2(Data data,int client_sockfd,User_link* userhead,Conv_link* convhead)//会话链表不为空
{
	Conv_link* p_convhead = convhead;
	p_convhead = p_convhead->next;
	
	while(NULL != p_convhead)	//先判断用户是否登陆，没有登陆再判断用户名和密码
	{
		if(0 == strcmp(data.username,p_convhead->data.username))
		{
			data.retval = 2;	//客户已登陆，返回2;
			write(client_sockfd,&data,sizeof(data));
			return;
		}
		p_convhead = p_convhead->next;
	}	//没有查到客户在线，再检测用户名和密码是否错误;

	User_link* p_userhead = userhead;
	p_userhead = p_userhead->next;

	while(NULL != p_userhead)	//遍历
	{
		if((0 == strcmp(data.username,p_userhead->data.username)) && (0 == strcmp(data.passwd,p_userhead->data.passwd)))
		{
			data.retval = 0;	//成功返回客户端0;
			write(client_sockfd,&data,sizeof(data));
			insert_conv(data,convhead,client_sockfd);	//插入会话链表
			return;
		}
		p_userhead = p_userhead->next;
	}
	data.retval = 1;	//帐号密码不匹配，失败返回1;
	write(client_sockfd,&data,sizeof(data));
}

void insert_conv(Data data,Conv_link* convhead,int client_sockfd)//会话链表插入函数
{
	Conv_link* p_convhead = convhead;
	while(NULL != p_convhead->next)		//遍历到链表最后
	{
		p_convhead = p_convhead->next;
	}

	Conv_link* newnode = calloc(1,sizeof(Conv_link));		//创建新节点

	strcpy(newnode->data.username,data.username);	//写入用户名
	newnode->data.client_sockfd = client_sockfd;	//写入用户套接字

	time_t now_time;
	now_time = time(NULL);
	strcpy(newnode->data.login_time,ctime(&now_time));	//写入登陆时间

	p_convhead->next = newnode;	
	newnode->next = NULL;	//插入链表完成

	//打印信息，写入日志
	fprintf(fp_log,"时间：%s>用户：%s    登陆成功...\n\n",time_record(),data.username);
	printf("用户名：%s\t登陆了客户端(%d)\t时间：%s\n",data.username,client_sockfd,newnode->data.login_time);

}
