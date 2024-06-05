#include "viewcontrol.h"
// #include "userLink.h"
// #include "userLottery.h"
#include "issueLink.h"
#include <stdio.h>

int currentId = 0; // 定义变量



int main(int argc, char ** argv)
{
	//创建用户链表节点
	UserLink* userHead = createUserLink();
	if(NULL == userHead){
		printf("用户链表创建失败！\n");
		return -1;
	}
	
	//创建个人彩票链表节点
	UserLottery* lotteryHead = createUserLottery();
	if(NULL == lotteryHead){
		printf("个人彩票链表创建失败！\n");
		return -1;
	}	

	//创建每期彩票链表节点
	IssueLink* issueHead = createIssueLink();
	if(NULL == issueHead){
		printf("每期彩票链表创建失败！\n");
		return -1;
	}
	
	
	//从文件中载入用户链表数据
	loadUsers(userHead);
	//从文件中载入个人彩票链表数据	
	
	loadUserLottery(lotteryHead);
	//从文件中载入每期彩票链表数据
	loadIssueLink(issueHead);
	initializeId();

	
	//主控制函数
	mainViewControl(userHead,lotteryHead,issueHead);


	//保存用户文件信息
	saveUsers(userHead);
	//保存个人彩票文件信息
	saveUserLottery(lotteryHead);
	//保存每期彩票文件信息
	saveIssueLink(issueHead); 
	saveCurrentId();

	//释放用户链表内存
	freeUserLink(userHead);
	//释放个人彩票链表内存
	freeUserLottery(lotteryHead);
	//释放每期彩票链表内存
	freeIssueLink(issueHead);
	
	return 0;
}




