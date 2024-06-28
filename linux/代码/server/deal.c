#include "server.h"
#include "deal.h"
#include "data_type.h"


//服务器处理客户端请求函数
void deal(int server_sockfd)
{
	signal(SIGINT,sig_handler);

	printf("服务器开始运行......");

	fp_log = fopen("日志文件.txt","a");	//以追加的方式打开日志文件

	userhead = calloc(1,sizeof(User_link));	//用户头节点的创建
	userhead->next = NULL;
	convhead = calloc(1,sizeof(Conv_link));	//会话头节点的创建
	convhead->next = NULL;

	load_user();	//载入用户文件

	struct sockaddr_in clientaddr;
	socklen_t len = sizeof(clientaddr);

	int client_sockfd;


	while(1)		//不断accept接受客户端请求，没有请求会阻塞
	{
		pthread_attr_t attr;	//创建线程属性
		pthread_attr_init(&attr);	//初始化线程属性
		pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);	//设置线程的分离属性
		
		client_sockfd = accept(server_sockfd,(struct sockaddr*)&clientaddr,&len);
		fprintf(fp_log,"时间: %s>客户端: %d 连接了服务器\n\n",time_record(),client_sockfd);
		if(client_sockfd<0)
		{
			perror("accept error");
			continue;
		}
		
		out_addr(&clientaddr);	//输出连接的客户端的地址信息
		
		pthread_t client_id;	
		pthread_create(&client_id,&attr,readfun,(void*)client_sockfd);	//创建线程
		pthread_attr_destroy(&attr);	//销毁线程属性
	}

	return;
}

//信号处理函数
void sig_handler(int signo)
{
	if(signo == SIGINT)
	{
		printf("服务器正在退出...\n");
		sleep(1);

		close(server_sockfd);	//关闭套接字
		fclose(fp_log);			//关闭日志文件
		fp_log = NULL;
		destroy_Conv_link();	//销毁会话链表
		destroy_User_link();	//销毁用户链表
		exit(0);
	}
}

//线程处理函数
void* readfun(void* arg)
{
	pthread_mutex_init(&mutex,NULL);	//初始化互斥锁
	int client_sockfd = (int)arg;

	Data data;	//用来接受客户端的结构体;
	Heart heart_data;	//用来统计心跳包;
	heart_data.count = 0;
	heart_data.client_sockfd = client_sockfd;

	while(1)		//循环接受客户端发送的请求
	{
		pthread_t pthread_id;
		pthread_create(&pthread_id, NULL,heart_fun,(void*)&heart_data);	//心跳线程

		memset(&data,0,sizeof(data));
		int retval = read(client_sockfd,&data,sizeof(Data));
		pthread_cancel(pthread_id);		//在处理本线程数据的时候，把心跳线程停掉
		
		if(retval == -1)
		{
			printf("读取失败！\n");
			break;
		}
		if(retval == 0)
		{
			printf("用户已关闭！\n");
			break;
		}

		pthread_mutex_lock(&mutex);	//对所有共享操作上锁

		switch(data.type)	//判断数据类型，进行数据包的处理
		{
			case TYPE_LOG:	login_type(data,client_sockfd,userhead,convhead);
							break;
			case TYPE_REG:	regist_type(data,client_sockfd);
							break;
			case TYPE_HRT:	//心跳包
				{
					heart_data.count = 0;	//心跳清零
					Conv_link* p_convhead = convhead;
					p_convhead = p_convhead->next;
					while(p_convhead != NULL)
					{
						if(heart_data.client_sockfd == p_convhead->data.client_sockfd)
						{
							printf("客户端：%d \t 用户:%s is alive!\n",heart_data.client_sockfd,p_convhead->data.username);	//打印用户信息
							break;
						}
						p_convhead = p_convhead->next;
					}
					break;
				}
			case TYPE_CMD:	command_type(data,client_sockfd);
							break;
			case TYPE_ONL:	//online_type(data,client_sockfd);
							break;
			case TYPE_CHT_SIG:	//chat_single_type(data,client_sockfd);
								break;
			case TYPE_CHT_GRP:	//chat_group_type(data,client_sockfd);
								break;
			case TYPE_QUT:	//delete_node(data);
								fprintf(fp_log,"时间: %s>用户: %s 退出\n\n",time_record(),data.username);
								printf("用户 %s 已经退出！\n",data.username);
								break;	//用户关闭处理函数，删除节点
			case TYPE_EXIT:	printf("客户端： %d 已关闭\n",client_sockfd);
								break;	//用户关闭处理函数;
			default:		printf("无此数据类型\n");
								break;
		}
		pthread_mutex_unlock(&mutex);
		if(TYPE_EXIT == data.type)
		{
			break;	//线程结束，退出;
		}
	}
	//日志
	fprintf(fp_log,"时间: %s >客户端: %d 断开了连接\n\n",time_record(),client_sockfd);

	close(client_sockfd);
	pthread_mutex_destroy(&mutex);	

	return (void*)0;
}

void* heart_fun(void* arg)
{
	Heart* heart_data = (Heart*)arg;	//处理心跳包数据的结构体
	Conv_link* p_convhead = convhead;
	Conv_link* pre_convhead = p_convhead;
	p_convhead = p_convhead->next;

	while(p_convhead != NULL)
	{
		if(heart_data->client_sockfd == p_convhead->data.client_sockfd)
		{
			break;
		}
		pre_convhead = p_convhead;
		p_convhead = p_convhead->next;
	}
	
	while(1)
	{
		sleep(3);
		heart_data->count++;
		if((heart_data->count) == 15)		//找到对应在线客户，删除节点和套接字
		{
			if(p_convhead != NULL)
			{
				fprintf(fp_log,"时间：%s>用户:%s  异常退出\n\n",time_record(),p_convhead->data.username);
				printf("客户端%d\t 用户:%s 已经退出！\n",heart_data->client_sockfd,p_convhead->data.username);
				pre_convhead->next = p_convhead->next;
				free(p_convhead);
				p_convhead = NULL;
				close(heart_data->client_sockfd);
			}
			else
			{
				printf("客户端：%d\t 用户（无）异常退出！\n",heart_data->client_sockfd);
				fprintf(fp_log,"时间：%s>客户端: %d 异常退出!\n",time_record(),heart_data->client_sockfd);
			}
			return NULL;
		}
	}
	return NULL;
}

//输出客户端地址
void out_addr(struct sockaddr_in* clientaddr)
{
	int port = ntohs(clientaddr->sin_port);
	char client_ip[16];
	memset(client_ip,0,sizeof(client_ip));

	inet_ntop(AF_INET,&clientaddr->sin_addr.s_addr,client_ip,sizeof(client_ip));

	printf("客户端：%s\t端口：%d\t链接到服务器......\n",client_ip,port);
}

//获取当前的时间函数
char* time_record()
{
	time_t now_time;	//记录当前时间
	now_time = time(NULL);
	return ctime(&now_time);
}

//注销用户链表
void destroy_User_link()
{
	User_link* p_userhead = userhead;
	User_link* pre_userhead = userhead;
	p_userhead = p_userhead->next;
	while(NULL != p_userhead)
	{
		pre_userhead = p_userhead->next;
		free(p_userhead);
		p_userhead = pre_userhead;
	}
	free(userhead);
	userhead = NULL;

	return;
}


//注销会话链表
void destroy_Conv_link()
{
	Conv_link* p_convhead = convhead;
	Conv_link* pre_convhead = convhead;
	p_convhead = p_convhead->next;
	while(NULL != p_convhead)
	{
		pre_convhead = p_convhead->next;
		free(p_convhead);
		p_convhead = pre_convhead;
	}
	free(convhead);
	convhead = NULL;

	return;
}

//注册数据包处理函数
void regist_type(Data data,int client_sockfd)
{
	User_link* p_userhead = userhead;
	User_link* pre_userhead = p_userhead;
	p_userhead = p_userhead->next;

	while(NULL != p_userhead)	//遍历
	{
		pre_userhead = p_userhead;
		if(strcmp(data.username,p_userhead->data.username) != 0)
		{
			p_userhead = p_userhead->next;
		}
		else
		{
			data.retval = 1;	//1表示用户已存在，注册失败
			write(client_sockfd,&data,sizeof(Data));
			return;
		}
	}
	//此时该用户可以注册;
	fprintf(fp_log,"时间：%s>用户：%s注册成功\n\n",time_record(),data.username);

	data.retval = 0;	//0表示注册成功
	write(client_sockfd,&data,sizeof(Data));

	User user;	//把注册的用户插入链表并保存
	strcpy(user.username,data.username);
	strcpy(user.passwd,data.passwd);
	
	User_link* newnode = calloc(1,sizeof(User_link));
	pre_userhead->next  = newnode;
	newnode->data = user;
	newnode->next = NULL;

	save_user();	//保存数据
}

//删除在线节点函数
void delete_node(Data data)
{
	Conv_link* p_convhead = convhead;
	Conv_link* pre_convhead = p_convhead;
	p_convhead = p_convhead->next;

	while(p_convhead != NULL)	//遍历到最后
	{
		if(strcmp(data.username,p_convhead->data.username) == 0)
		{
			pre_convhead->next = p_convhead->next;
			free(p_convhead);
			p_convhead = NULL;
			break;
		}
		pre_convhead = p_convhead;
		p_convhead = p_convhead->next;
	}
}

//命令数据包的处理函数
void command_type(Data data,int client_sockfd)
{
	fprintf(fp_log,"时间：%s>用户：%s	发送了shell命令：%s\n",time_record(),data.username,data.shell_send);
	system("touch shell.db");	//创建一个缓存文件
	int fd = open("shell.db",O_RDWR,0777);
	int save_fd = dup(1);
	dup2(fd,1);

	int retval = system(data.shell_send);	//执行客户端传来的指令，写进fd
	dup2(save_fd,1);

	if(retval != 0)		//system命令错误,返回2;
	{
		data.retval = 2;
		write(client_sockfd,&data,sizeof(data));
		return;
	}
	
	lseek(fd,0,SEEK_SET);	//移动文件光标到头部
	read(fd,data.shell_rec,sizeof(data.shell_rec));	//将执行结果从fd读取到data.shell_rec;
	close(fd);

	system("rm shell.db");	//删除缓存文件
	write(client_sockfd,&data,sizeof(data));

	return;
}
