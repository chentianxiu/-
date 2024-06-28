#include "data_type.h"
#include "deal.h"
#include "server.h"

//用户文件的加载
void load_user()
{
	if(NULL == userhead)	//判断头节点是否为空
	{
		printf("头节点为空\n");
		return;
	}

	FILE* fp_user = fopen("用户账户.txt","r");	//打开文件
	if(fp_user == NULL)
	{
		system("touch 用户账户.txt");	//文件不存在就创建
		return;
	}

	while(1)
	{
		User user;
		int flag = fscanf(fp_user,"用户名：%s	密码：%s\n",user.username,user.passwd);
		if((flag<0) || (flag == EOF))
		{
			return;
		}
		insert_user(user);	//插入链表
	}
	fclose(fp_user);
	fp_user = NULL;
}

//插入链表
void insert_user(User data)
{
	User_link* p_userhead = userhead;
	while(p_userhead->next != NULL)
	{
		p_userhead = p_userhead->next;	//循环遍历到最后一个节点;
	}
	User_link* newnode = calloc(1,sizeof(User_link));
	newnode->data = data;
	newnode->next = NULL;
	p_userhead->next = newnode;
}

//保存user链表数据
void save_user()
{
	if(NULL == userhead)
	{
		printf("头节点为空");
		return;
	}
	FILE* fp_user = fopen("用户账户.txt","w");
	if(NULL == fp_user)
	{
		printf("保存失败\n");
		return;
	}
	User_link* p_userhead = userhead;
	p_userhead = p_userhead->next;
	while(NULL != p_userhead)
	{
		fprintf(fp_user,"用户名：%s	密码：%s\n",p_userhead->data.username,p_userhead->data.passwd);
		p_userhead = p_userhead->next;
	}
	fclose(fp_user);
	fp_user = NULL;
}
