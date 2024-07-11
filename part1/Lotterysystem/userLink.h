#ifndef USERLINK_H_
#define USERLINK_H_
#define ADMIN "admin"
#define PWD "12345"
#define WORKER "worker"
#define PWD2 "12345"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>

//用户结构体
typedef struct userdata
{
    char username[20];  //账号
    char password[20];  //密码
    double money;          //账户金额
}Userdata;


//用户链表
typedef struct userLink{
	Userdata		data;
	struct userLink *next;  //指向下一个用户的指针
}UserLink,*UserLinklsit; 

//创建用户链表
UserLinklsit createUserLink(void);

//添加用户(链表操作)
void InserUserNode(UserLinklsit head,UserLinklsit newNode);

//打印节点信息
void printUserLink(UserLinklsit head);
//打印当前节点信息
void printUserLinkone(UserLinklsit head, char * username);

// //用户修改自己信息
// void Changemassge(UserLinklsit head, char * username);
//充值
void Addmoney(UserLinklsit head,  char *username);

// // 修改用户名
// void Changname(UserLinklsit head,  char *username);
//用户修改密码
int ChangPwd(UserLinklsit head,  char *username);

//释放所有节点
void freeUserLink(UserLinklsit head);

//删除节点(用户注销用)
int removeUserNode(UserLinklsit head, char *username);

//从文件中加载用户信息
void loadUsers(UserLinklsit  head);

//将信息保存入链表之中
void saveUsers( UserLinklsit  head);

//注册用户
void registerUser(UserLinklsit userHead);






#endif