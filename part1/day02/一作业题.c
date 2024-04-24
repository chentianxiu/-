#include <stdio.h>

int main()
{
    int a = 0;
    printf("请输入一个四位数：");
    scanf("%d",&a);
    int ge = 0;
    ge = a%10;
    int shi = 0;
    a= a/10;
    shi = a%10;
    int bai = 0;
    a= a/10;
    bai = a%10;
    int qian = 0;
    a = a/10;
    qian = a%10;
    printf("个位:%d\t十位:%d\t百位:%d\t千位:%d",ge,shi,bai,qian);
    return 0;
    
}