//用代码求阶乘，定义0的阶乘是1
#include <stdio.h>

long long fac(int a){
    if (a==0||a==1){
        return 1;
    }else
    {
        return a*fac(a-1);
    } 
}


int main()
{
    int a=0;
    printf("请输入一个数:\n");
    scanf("%d",&a);
    printf("这个数的阶乘是:%lld\n",fac(a));

    return 0;
    
}