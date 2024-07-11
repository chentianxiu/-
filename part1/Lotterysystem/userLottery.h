#ifndef USERLOTTERY_H_
#define USERLOTTERY_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
#include "userLink.h"

typedef struct lottery
{
    int issue;              //发布期号
    int id;                 //单张彩票唯一标识id
    char selcetedNumber[10];  //彩票上选中的号码
    char username[20];     //购买者账号 
    int numBets;            //已购买某一彩票号的注数(最多5注)
    int winningStatus;      //中奖状态
    double winprice;   //中奖金额

}Lottery;

//彩票结构体
typedef struct userlottery
{
    Lottery      lottery;
    struct userlottery *next;   //指向下一张彩票的指针

}UserLottery,*UserLotteryLink;

/*
	功能：创建个人彩票链表
	参数：无
	返回值：头节点的地址 NULL 失败
*/
UserLottery* createUserLottery(void);



/*
	功能：添加节点
	参数：head: 头节点 newNode:要添加的节点
	返回值：	1 成功 0 失败
*/
void insertLotteryNode(UserLotteryLink head, UserLotteryLink newNode);



/*
	功能：打印所有信息
	参数：head: 头节点
	返回值：无
*/
void printUserLottery(UserLotteryLink head);


/*
	功能：释放所有节点
	参数：head: 头节点
	返回值：无
*/
void freeUserLottery(UserLotteryLink head);

/*
	功能：通过名字删除节点
	参数：head:头节点 name： 名字
	返回值：0 失败 1 成功
*/
int removeLotteryNode(UserLotteryLink head, const int stage);


/*
	功能：保存所有信息到文件中
	参数：head 头节点
	返回值：无
*/
void saveUserLottery(UserLotteryLink head);


/*
	功能：从文件中加载所有的信息到内存中
	参数：head: 头节点
	返回值：无
*/
void loadUserLottery(UserLotteryLink head);




//输入选中号码只取9位数
void processInput(char *input, char *output);


//查询购买彩票记录
void CheckRecords(UserLottery* lotteryHead,char * username);

//查询中奖记录
void CheckWinRrecords(UserLottery * lotteryHead,char *username);

// 彩票号码购买信息查询
void CheckSelectNum(UserLottery *lotteryHead);


#endif
