//功能，查询余额、存款、取款、退出。
//先定义查询，存款，取款的三个功能函数，然后用whlie来无限循环，用swith语句来选择条件
#include <stdio.h>

int money=0;

void selectMoney(){
    printf("您的余额是%d\n",money);
    return;
}//查询

void saveMoney(int save){
    money+=save;
    printf("存款后您的余额是%d\n",money);
    return;
}//存钱

void getMoney(int get){
    money-=get;
    printf("取款后您的余额是%d\n",money);
    return;
}//取钱


int main()
{
    int flag=1;
    int choose=0;
    int get=0;
    int save=0;
    while (flag)
    {
        printf("--------主菜单--------\n");
        printf("欢迎来到梦里才有银行\n");
        printf("\t1.查询余额\t[请输入1]\n");
        printf("\t2.存款\t[请输入2]\n");
        printf("\t3.取款\t[请输入3]\n");
        printf("\t4.退出\t[请输入4]\n");
        printf("请输入您的选择:\n");

        scanf("%d",&choose);

        switch (choose)
        {
        case 1://查询钱
            selectMoney();
            break;
        case 2://存钱
            printf("请输入您要存的数目:\n");
            scanf("%d",&save);
            saveMoney(save);
            break;
        case 3://取钱
            printf("请输入您要取出的数目:\n");
            scanf("%d",&get);
            if((money-get)>=0){
                getMoney(get);
            }else
            {
                printf("取钱的数量不能超过本金\n");
                continue;
            }            
            break;
        case 4://退出
               printf ("欢迎下次使用\n");
               flag=0;
               break;
        default:
            printf("请输入规定的数字\n");
            continue;
        }
    }
    

    return 0;
    
}