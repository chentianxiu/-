#include <stdio.h>

int main()
{
    int a=0;
    int b=0;

    int count = 0;

    printf("请输入两个数\n");

    scanf("%d%d",&a,&b);//scanf里面不需要\n

    if (a>b)
    {
        a = a^b;
        b = a^b;
        a = a^b;
    }
    
    
    for(int i=a;i<=b;i++)
    {
        if((i%3==0)&&(i%5==0))
        {
            printf("能被3和5整除的数是%d\n",i);
            count++;
            
        }
        
    }
    printf("能被整除的个数是%d",count);

    return 0;
    
}