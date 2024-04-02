#include <stdio.h>


int add(int num1, int num2) {  
   int sum;  
   sum = num1 + num2;  
   return sum;  
}

int main()
{
    int a = 0;
    int b = 0;
    printf("请输入两个数\n");
    scanf("%d%d",&a,&b);
    int sum2=add(a,b);
    
    printf("%d加%d的结果是:%d",a,b,sum2);
    return 0;
    
}