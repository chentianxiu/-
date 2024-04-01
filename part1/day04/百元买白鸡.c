//思路：公鸡5钱一只，母鸡3钱一只，小鸡3钱一只，100钱买白鸡，定义g,m,x，for/if来使用这个条件
//g的值在0到20之间，m的值在0到33之间,g的值在0到300之间
#include <stdio.h>

int main()
{
    int g,m,x;
    int d=100;
    for(g=0;g<=20;g++){
        for ( m = 0; m<=33; m++)
        {
            for (x = 0; x<=300; x++)
            {
               if((g+m+x==d)&&(5*g+3*m+x/3==100)&&(x%3==0)){
                printf("可能的结果是%d只公鸡%d只母鸡和%d只小鸡\n",g,m,x);
               }
               else continue;
               }
            }
            
        }
    return 0;
    
}