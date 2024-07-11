#include "view.h"
#include <stdio.h>
/*
	功能：注界面显示
	参数：无
	返回值：无
*/
void mainView(void)
{
	printf("欢迎进入中国福利彩票中心\n");
	printf("1、注	册\n");
	printf("2、登	录\n");
	printf("0、退	出\n");
	printf("请输入你的选择: ");	
}


/*
	功能：普通用户二级界面显示
	参数：无
	返回值：无
*/
void userSecondView(void)
{
	printf("欢迎进入用户界面\n");
	printf("1、查看个人信息\n");
	printf("2、修改个人信息\n");
	printf("3、注销个人信息\n");
	printf("4、充       值\n");
	printf("5、查询中奖记录\n");
	printf("6、购 买 彩 票\n");
	printf("7、查询购买记录\n");
	printf("8、猜 数 游 戏\n");
	printf("0、返回上一级\n");
	printf("请输入你的选择: ");
}

/*
	功能：管理员二级界面显示
	参数：无
	返回值：无
*/
void adminSecondView(void)
{
	printf("欢迎进入管理员界面\n");
	printf("1、发行彩票\n");
	printf("2、按用户账户查询\n");
	printf("3、按用户余额排序\n");
	printf("4、用户购买信息查询\n");
	printf("5、彩票选中号码信息查询\n");
	printf("0、返回上一级菜单\n");
	printf("请输入你的选择：");
}


/*
	功能：公证员二级界面显示
	参数：无
	返回值：无
*/
void notarySecondView(void)
{
	printf("欢迎进入公证员界面\n");
	printf("1、开奖\n");
	printf("2、查看历史发行\n");
	printf("0、返回上一级菜单\n");
	printf("请输入你的选择：");
}



