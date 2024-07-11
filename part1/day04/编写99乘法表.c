#include <stdio.h>

int main()
{

    printf("九九乘法表是：\n");
    //定义一个变量表示行
    for(int i=1;i<=9;i++)
    {
        //定义一个变量表示列
        for(int j=1;j<=i;j++)
        {
            //打印格式
            printf("%d*%d=%d\t",j,i,i*j);
        }
        //每打印一行后换行
        printf("\n");
    }

    return 0;
    
}