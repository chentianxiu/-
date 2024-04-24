#include <stdio.h>

int main()
{
    int year = 0;
    printf("请输入一个年份：\n");
    scanf("%d",&year);
    
    if (((year%4==0)&&(year%100!=0))||(year%400==0))
    {
        printf("%d是一个闰年\n",year);

    }else{
        
        printf("%d不是一个闰年\n",year);
    }
    

    return 0;

}