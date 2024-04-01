#include <stdio.h>

int main()
{
    int sum=0;
    for(int i=0;i<=100;i+=2)
    {
        if(i%2==0){
            sum+=i;
        }
        printf("sum是%d\n",sum);
    }
    printf("1-100偶数的和是%d\n",sum);

    return 0;
    
}