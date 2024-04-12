/*方法二：两数相乘法
先将两个数相乘。
再找出这两个数的最大公约数（GCD，Greatest Common Divisor）。
将两数相乘的结果除以它们的最大公约数，得到的结果就是最小公倍数。
公式表示为：LCM(a, b) = (a × b) / GCD(a, b)
*/
#include <stdio.h>

int GCD(int a, int b){
    int temp;
    while (b!=0)
    {
        temp=b;
        b=a%b;
        a=temp;
    } 
    return a;
}

int  LCM(int a ,int b){
    int m = 0;
    m=a*b/GCD(a,b);
    return m;
}

int main()
{
    int a=0;
    int b=0;
    printf("请输入两个数：\n");
    scanf("%d%d",&a,&b);
    printf("两个数的最小公倍数是:%d\n",LCM(a,b));


    return 0;
    
}