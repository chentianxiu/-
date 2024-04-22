#include <stdio.h>

int main()
{
    printf("helloworld\n");

    printf("***********\n");
//作业一
    printf("不要让未知的恐惧，影响你前进的步伐\n");
//作业二
    printf("学物联网,助您高薪就业,创造年薪30W\n");
//作业三
    printf("*********\n* Hello *\n*********\n");
//作业四
    char name[] = "Lisi";
    char gender[] = "男";
    int age = 25;
    int salary = 3600;
    double shebao = 314.59;

    printf("姓名:%s\n性别:%s\n年龄%d\n工资%d\n社保%.2f\n",name,gender,age,salary,shebao);
    printf("姓名\t性别\t年龄\t工资\t社保\n%s\t%s\t%d\t%d\t%.2f",name,gender,age,salary,shebao);

    return 0;

}