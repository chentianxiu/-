#include <stdio.h>

int main()
{
    int a=0;
    int b=0;

    printf("请按照大小输入两个数\n");

    scanf("%d%d",&a,&b);//scanf里面不需要\n
    
    for(int i=a;i<=b;i++)
    {
        if((i%3==0)&&(i%5==0))
        {
            printf("能被3和5整除的数是%d\n",i);
            
        }
        
    }

    return 0;
    
}