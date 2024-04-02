//思路，完数定义是一个数它所有的因子相加等于它本身
//定义一个函数求这个数的因子之和，然后在主函数里面比较

#include <stdio.h>


int perfectnum(int num){
    int sum=0;
    for(int i=1;i<num;i++){
        if(num%i==0){
         sum+=i;
        }
    }
    return sum;
}//求因子的和

int main()
{   
    int a;
    printf("请输入一个数：\n");
    scanf("%d",&a);
    if(a==perfectnum(a)){
        printf("这是一个完数");
    }else{
        printf("这不是一个完数");
    }

    return 0;
    
}