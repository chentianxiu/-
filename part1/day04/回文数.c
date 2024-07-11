//思路:比如输入一个数123454321，倒过来，也是123454321
//所以，要判断一个数是否是回文数得先将这个数倒过来，再来和原本的数字比较，我用的倒过来方法是while循环
//while循环可以在知道循环范围的情况下使用

#include <stdio.h>

int main()
{
    int num=0;
    int onum=0;//表示原数字
    int rnum=0;//表示反转数字
    int temp=0;//临时储存的一个变量
    printf("请输入一个数\n");
    scanf("%d",&num);
    onum=num;//将输入的值赋值给原数字
    do
    {
        temp=num%10;
        rnum=rnum*10+temp;
        num/=10;/* code */
    } while (num!=0/* condition */);
    if(onum==rnum){
        printf("这个数是回文数\n");
    }
    else{
        printf("这个数不是回文数\n");
    }


    return 0;
    
}