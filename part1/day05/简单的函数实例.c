#include <stdio.h>


float add(int num1, float num2) {  
   float sum;  
   sum = (float)num1 + num2;  
   return sum;  
}

int main()
{
    int a = 0;
    float b = 0;
    printf("请输入两个数\n");
    scanf("%d%f",&a,&b);
    float sum2;
    sum2=add(a,b);
    
    printf("%d加%.2f的结果是:%.2f",a,b,sum2);
    //printf("结果是:%.2f",sum2);
    return 0;
    
}