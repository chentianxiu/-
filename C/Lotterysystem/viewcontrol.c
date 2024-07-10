#include "viewcontrol.h"

/*
	功能：注界面控制函数
	参数：userHead: 用户头节点
	返回值：无
*/
void mainViewControl(UserLink *userHead, UserLottery *lotteryHead, IssueLink *issueHead)
{
	if (NULL == userHead || NULL == lotteryHead || NULL == issueHead)
	{
		return;
	}
	int choice = 0;
	while (1)
	{

		mainView(); // 住界面
		scanf("%d", &choice);
		switch (choice)
		{
		case 1: // 注册
			// 注册函数
			registerUser(userHead);
			break;
		case 2: // 登录
			userLogin(userHead, lotteryHead, issueHead);
			break;
		case 0: // 退出
			return;
		default:
			break;
		}
		waitForKeyPress();
		system("cls"); // 清屏
	}
}

// 清除输入缓存
void clearInputBuffer()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF)
		;
}

// 等待用户输入任意键
void waitForKeyPress()
{
	printf("按任意键继续...");
	getchar();
	clearInputBuffer(); // 清除可能的多余输入
}

// 登录验证
void userLogin(UserLink *userHead, UserLottery *lotteryHead, IssueLink *issueHead)
{
	int num = 3;
	while (num > 0)
	{
		char username[20];
		char password[20];
		char passcard[5];
		printf("请输入账户\n");
		scanf("%s", username);
		printf("请输入密码\n");
		get_password(password);

		if (strcmp(ADMIN, username) == 0 && strcmp(PWD, password) == 0)
		{
			adminSecondViewControl(userHead, lotteryHead, issueHead); // 管理员登录
			num = 3;
			return;
		}
		else if (strcmp(WORKER, username) == 0 && strcmp(PWD2, password) == 0)
		{
			notarySecondViewControl(userHead, lotteryHead, issueHead); // 公证人登录
			num = 3;
			return;
		}
		else
		{
			// 初始化随机数生成器
			srand(time(NULL));
			// 分配验证码字符串的空间
			char captcha[5];
			// 生成验证码
			generateCaptcha(captcha, 4);
			// 输出验证码
			printf("验证码: %s\n", captcha);
			scanf("%s", passcard);
			UserLink *current = userHead->next;
			while (current != NULL)
			{
				if (strcmp(current->data.username, username) == 0 && strcmp(current->data.password, password) == 0 && strcmp(passcard, captcha) == 0)
				{
					userSecondViewControl(userHead, lotteryHead, issueHead, username); // 用户登录
					num = 3;
					return;
				}
				current = current->next;
			}
			printf("账号密码输入错误,请重新输入\n"); // 都没登录
			num--;
			printf("您还有%d次机会\n", num);
		}
	}
	return;
}

/*
	功能：普通用户二级界面显示
	参数：无
	返回值：无
*/
void userSecondViewControl(UserLink *userHead, UserLottery *lotteryHead, IssueLink *issueHead, char *username)
{
	int a = 0;
	int b = 0;
	int choice = 0;
	while (1)
	{

		userSecondView(); // 用户界面
		scanf("%d", &choice);
		switch (choice)
		{
		case 1: // 查看个人信息
			printUserLinkone(userHead, username);
			break;
		case 2: // 修改个人信息
			b = Changemassge(userHead, lotteryHead, username);
			if (b == 1)
			{
				return mainViewControl(userHead, lotteryHead, issueHead);
			}
			break;
		case 3: // 注销个人信息
			a = removeUserNode(userHead, username);
			if (a == 1)
			{
				printf("注销成功\n");
			}
			else
			{
				printf("注销失败\n");
			}
			return;
			break;
		case 4: // 充值
			Addmoney(userHead, username);
			break;
		case 5: // 查询中奖记录
			CheckWinRrecords(lotteryHead, username);
			break;
		case 6: // 买票
			Buytickets(userHead, lotteryHead, issueHead, username);
			break;
		case 7: // 查询购票记录
			CheckRecords(lotteryHead, username);
			break;
		case 8: // 猜数游戏
			guessNumberGame();
			break;
		case 0: // 返回上一级
			return;
		default:
			break;
		}
		waitForKeyPress();
		system("cls"); // 清屏
	}
	return;
}

/*
	功能：管理员二级界面显示
	参数：无
	返回值：无
*/
void adminSecondViewControl(UserLink *userHead, UserLottery *lotteryHead, IssueLink *issueHead)
{

	if (NULL == userHead || NULL == lotteryHead || NULL == issueHead)
	{
		return;
	}
	int choice = 0;
	while (1)
	{

		adminSecondView(); // 管理员界面
		scanf("%d", &choice);
		switch (choice)
		{
		case 1: // 发行彩票
			// 发行彩票函数
			Issuelotterytickets(userHead, lotteryHead, issueHead);
			break;
		case 2: // 按用户账户查询
			userNamesort(userHead, lotteryHead, issueHead);
			break;
		case 3: // 按用户余额查询
			userMoneysort(userHead);
			break;
		case 4: // 用户购买信息查询
			printUserLottery(lotteryHead);
			break;
		case 5: // 彩票号码购买信息查询
			CheckSelectNum(lotteryHead);
			break;
		case 0: // 退出
			return;
		default:
			break;
		}
		waitForKeyPress();
		system("cls"); // 清屏
	}
}

/*
	功能：公证员二级界面显示
	参数：无
	返回值：无
*/
void notarySecondViewControl(UserLink *userHead, UserLottery *lotteryHead, IssueLink *issueHead)
{

	int choice = 0;
	while (1)
	{
		notarySecondView(); // 公证员界面
		scanf("%d", &choice);
		switch (choice)
		{
		case 1: // 开奖
			LotteryDraw(userHead, lotteryHead, issueHead);
			break;
		case 2: // 查询历史发行
			printIssueLink(issueHead);
			break;
		case 0: // 返回上一级
			return;
		default:
			break;
		}
		waitForKeyPress();
		system("cls"); // 清屏
	}
}
