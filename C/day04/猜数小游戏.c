//思路：1、产生一个随机数；
//2、键盘录入数据；
//3、使用if...else if...else语句
//4、使用while死循环和break语句
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    //设置随机数
    //设置种子，使用当前时间作为种子
    int Mnum = 3;
    int min,max = 0;
    printf("请输入两个数");
    scanf("%d%d",&min,&max);
    srand(time(NULL));
    int rn = rand()%(max-min+1)+min;//1~100
    //输出随机数，%代表min~max之间的数据，包含min不包含max
    printf("上帝视角随机数是%d",rn);
    //由于不知道猜多少次，选用while死循环
    while (1)
    {
        int num;
        printf("请输入一个整数：\n");
        scanf("%d",&num);
        
        if(num>rn){
            printf("您猜大了\n");
        }else if (num<rn)
        {
            printf("您猜小了\n");
        }else{
            printf("恭喜您，猜对了\n");
            //退出循环
            break;
        }
        
        //3次机会，每一次减一
        Mnum--;
        //printf("您还有%d次机会\n",Mnum);
        if (Mnum==0){
            printf("您的次数用完了\n");
            break;
        }
        printf("您还有%d次机会\n",Mnum);
        
    }    
    return 0;
    
}