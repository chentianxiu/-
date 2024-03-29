#include <stdio.h>

int main() {
    int number = 0;
    float num2 = 0.00;
    printf("请输入一个整数：\n");
    scanf("%d", &number);
    printf("请输入一个小数：\n");
    scanf("%f",&num2);

    printf("您输入的整数是：%d\n", number);
    printf("您输入的小数是：%0.2f\n", num2);

    return 0;
}