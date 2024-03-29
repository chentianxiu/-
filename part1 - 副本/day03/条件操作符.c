#include <stdio.h>

int main()
{   
    int a = 0;
    int b = 0;
    printf("请输入a的值\n");

    scanf("%d",&a);

    printf("请输入b的值\n");

    scanf("%d",&b);

    int max = a>b?a:b;

    printf("a,b中最大的数是:%d",max);

    return 0;

}