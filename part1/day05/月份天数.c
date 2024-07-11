//思路：求某年某月共几天函数声明：int getDay(int year,int month);
//每年的特殊情况，闰年的二月为29天，普通年份为28天，然后4，6，9，11为30天，其他为31天
#include <stdio.h>

int ruiYear(int year){
    if((year%4==0&&year%100!=0)||(year%400==0)){
        return 1;
    }
}
//获取年份函数
int getYear(int year,int month){
    if((month==2)&&(ruiYear(year)==1)){
        return 29;//闰年2月
    }else if ((month==2)&&(ruiYear(year)!=1))
    {
        return 28;//非闰2年
    }else if (month==4||month==6||month==9||month==11)
    {
        return 30;//30天的月份
    }else{
        return 31;//31天的月份
    }   
}
int main()
{
    int year,month;
    printf("请输入年月\n");
    scanf("%d%d",&year,&month);
    printf("这个月的天数有%d天",getYear(year,month));
    return 0;
    
}