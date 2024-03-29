#include <stdio.h>

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;

    printf("请依次输入三个和尚的身高\n");
    scanf("%d%d%d",&a,&b,&c);
    int num1 = a>b?a:b;
    int num2 = num1>c?num1:c;

    printf("三个和尚中身高最高的是%d\n",num2);

    return 0;

}