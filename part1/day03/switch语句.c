#include <stdio.h>

int main()
{   int a=1;
    printf("请输入菜单对应的数\n1是兰州拉面\n2是热干面\n3是炸酱面\n4是油泼面\n其他是泡面\n");
    scanf("%d",&a);
    switch (a)
    {
    case 1:
        printf("吃兰州拉面\n");
        break;
    case 2:
        printf("吃武汉热干面\n");
        break;
    case 3:
        printf("吃炸酱面\n");
        break;
    case 4:
        printf("吃油泼面\n");
        break;   
    default:
        printf("吃泡面\n");
        break;
    }

    return 0;
    
}