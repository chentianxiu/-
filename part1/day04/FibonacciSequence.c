//思路：斐波拉契数列是前两位数相加得出第三位数 1 1 2 3 ....
//我们要得到第n，位数，需要前面的相加
#include <stdio.h>

int main()
{
    int a=1,b=1;
    int temp=0;
    int n=0;
    printf("a的值%d",a);

    printf("请输入斐波拉契数列的位数\n");
    scanf("%d",&n);

    for(int i=3;i<=n;i++){
        temp=a+b;
        a=b;
        b=temp;
    }
    printf("第%d位数的值是%d\n",n,b);

    return 0;
    
}