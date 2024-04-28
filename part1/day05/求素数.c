/*编写判断素数的函数，再调用该函数求出 1000 以内的所有素数？
素数是指只能被 1 和自身整除的正整数，也就是只有两个正因数的数。
比如 2 、 3 、 5 、 7 、 11 等都是素数，而 4 、 6 、 8 、 9 等则不是素数。*/

#include <stdio.h>
#include<stdbool.h>

//定义判断素数的函数，用bool类型来定义
bool is_prime(int num){
    if (num <= 1){
        return 0;
    }else{
        //如果n有一个大于sqrt(n)的因子a，那么它必然也有一个小于sqrt(n)的因子b，使得a * b = n。
        //反之，如果n在小于等于sqrt(n)的范围内没有因子，那么它在大于sqrt(n)的范围内也不会有因子，因此它是素数。
        //这个原理是基于数的基本性质的。通过只检查到sqrt(n)，我们可以显著减少需要检查的数的数量，从而提高算法的效率。
       for(int i = 2;i*i<=num;i++){
        if (num%i == 0){
            return 0;
        }
       }
    }
    return 1;
}

int main()
{
    //判断是否为素数，用for循环
    int a = 1000;
    for (int i = 0;i<a;i++){
        if (is_prime(i)==1){
            printf("%d\t",i);
        }
    }

    return 0;
    
}