#ifndef ISSUELINK_H_
#define ISSUELINK_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
#include <time.h>
#include "userLottery.h"
#include "currentID.h"



//每期彩票链表的数据区
typedef struct issue{
	int		issue; //发布期号
	double	saleprice;//彩票单价
	int winningStatus; //开奖状态
	char winNumber[10];//中奖号码
	int  salenum;//售出总数
	double	pool;//奖池总额
}Issue;

//每期彩票链表
typedef struct issueLink{
	Issue				data;
	struct issueLink* 	next;

}IssueLink,*IssueLinklist;


/*
	功能：创建每期彩票链表
	参数：无
	返回值：头节点的地址 NULL 失败
*/
IssueLink* createIssueLink(void);

/*
	功能：添加节点
	参数：head: 头节点 newNode:要添加的节点
	返回值：	1 成功 0 失败
*/
void insertIssueNode(IssueLinklist head, IssueLinklist newNode);


/*
	功能：打印所有信息
	参数：head: 头节点
	返回值：无
*/
void printIssueLink(IssueLinklist head);


/*
	功能：释放所有节点
	参数：head: 头节点
	返回值：无
*/
void freeIssueLink(IssueLink* head);


/*
	功能：通过期号删除节点
	参数：head:头节点 stage： 期号
	返回值：0 失败 1 成功
*/
int removeIssueNode(IssueLink* head, const int stage);


/*
	功能：保存所有信息到文件中
	参数：head 头节点
	返回值：无
*/
void saveIssueLink(IssueLink* head);


/*
	功能：从文件中加载所有的信息到内存中
	参数：head: 头节点
	返回值：无
*/
void loadIssueLink(IssueLink* head);


//随机生成一串期号(根据当前时间生成)
int generateTimeBasedNumber();

//查找是否有未开奖的彩票
int FindissueStatus(IssueLink* head);

//管理员功能
// 发行彩票函数
void Issuelotterytickets(UserLink *userHead, UserLottery *lotteryHead, IssueLink *issueHead);

//找到上一期奖池
double Getoldpool(IssueLink *issueHead);

// 按用户账户查询
void userNamesort(UserLink *userHead, UserLottery *lotteryHead, IssueLink *issueHead);

//按照用户名字打印用户信息
void Printonemassge(const char * username,UserLink *userHead, UserLottery *lotteryHead);

//按照用户余额排序用户信息
void userMoneysort(UserLink *userHead);

//用户购买彩票
void Buytickets(UserLink *userHead, UserLottery *lotteryHead, IssueLink *issueHead,char * username);

// 判断余额是否足够
int checkmoney(UserLink *userHead,UserLottery *newnode,IssueLink *current,char *username,int numbet);


//开奖
void LotteryDraw(UserLink *userHead, UserLottery *lotteryHead, IssueLink *issueHead);


//找到当前期号的彩票,对比彩票号码,判断中奖等级
int CompareWinNum(char * selcetedNumber,char * winnum);

//更新中奖用户的奖金,奖金池暂时不更新,最后统一更新
void UpdateUserLotMsg(UserLottery *lotteryHead,IssueLink *current);

//计算用户结算后的余额
void AddwinPrice(UserLink *userHead,UserLottery *lotteryHead,IssueLink *current);

//打印现在中奖的彩票信息
void PrintNow(UserLottery *lotteryHead,IssueLink *current);

// 修改用户名
void Changname(UserLinklsit head,UserLottery *lotteryHead, char *username);

// 用户修改自己信息
int Changemassge(UserLinklsit userhead,UserLottery *lotteryHead,char *username);


// 隐藏密码
void get_password(char *password);

//生成四位数验证码
void generateCaptcha(char *captcha, int length);

//随机生成9位数
void generateRandom9DigitString(char *str);

//猜数小游戏
void guessNumberGame();



#endif
