#ifndef VIEWCONTROL_H_
#define VIEWCONTROL_H_


#include "issueLink.h"
#include "view.h"

/*
	功能：注界面控制函数
	参数：userHead: 用户头节点
	返回值：无
*/
void mainViewControl(UserLink* userHead,UserLottery* lotteryHead,IssueLink* issueHead);

// 清除输入缓存
void clearInputBuffer();

// 等待用户输入任意键
void waitForKeyPress();
/*
	功能：普通用户二级界面控制
	参数：无
	返回值：无
*/
void userSecondViewControl(UserLink* userHead,UserLottery* lotteryHead,IssueLink* issueHead, char * username);


//登录验证
void  userLogin(UserLink* userHead,UserLottery* lotteryHead,IssueLink* issueHead);

//管理员二级界面控制
void adminSecondViewControl(UserLink *userHead, UserLottery *lotteryHead, IssueLink *issueHead);
//公正员二级界面控制
void notarySecondViewControl(UserLink *userHead, UserLottery *lotteryHead, IssueLink *issueHead);






#endif