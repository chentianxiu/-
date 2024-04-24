#include <stdio.h>

int main()
{
    int money = 6000;
    int skirt = 600;
    int bag = 5000;
    money = money-skirt;
    printf("购买了裙子%d元,还剩下:%d\n",skirt,money);
    money = money - bag;
    printf("购买了包包%d元,还剩下:%d\n",bag,money);


    return 0;
    
}