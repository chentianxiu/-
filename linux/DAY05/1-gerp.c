/*************************************************************************
	> File Name: gerp.c
	> Author: chenliang
	> Mail: 2779783956@qq.com 
	> Created Time: Fri 07 Jun 2024 11:32:05 AM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main()
{
	char cmd[]="ps -o ppid,pid,stat,command";
	FILE  *fp = popen(cmd,"r");

	char buf[128]= {0};

	while(1)
	{
		int res = fread(buf,1,1,fp);//前一个1是sizeof,后一个是数量
		if(res<=0)
		{
			break;
		}
		printf("%s",buf);
		memset(buf,0,sizeof(buf));

	}
	printf("\n");
	pclose(fp);

	return 0;
}
