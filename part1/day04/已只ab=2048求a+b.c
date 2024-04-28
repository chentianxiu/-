//有两个正整数a和b，已知a*b=2048，求a、b各为何值时，a+b的值最小
#include <stdio.h>

int main()
{
    //定义变量
    int num = 2048;
    int a = 0;
    int b  = 0;
    int ma = 0;
    int mb = 0;
    int minsum = 2049;
    int sum1 = 0;
    //循环遍历找到最小的sum
    for( a = 1;a<=2048;a++){
        if(2048%a == 0){
            b = 2048/a;
            sum1= a + b;
        //minsum = (minsum<sum1?minsum:sum1);
        if(minsum>sum1){
            minsum = sum1;
             ma = a;
             mb = b;
        }
    }
    //sum = (sum<sum1?sum:sum1);
    }


    printf("%d+%d的最小值是%d",ma,mb,minsum);


    return 0;
    
}