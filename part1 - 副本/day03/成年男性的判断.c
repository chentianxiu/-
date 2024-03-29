#include <stdio.h>

int main()
{
    //两个变量性别和年龄
    char gender = 'M';

    int age = 0;

    printf("请输入性别和年龄(年龄填写M和W)\n");

    scanf("%c%d",&gender,&age);


    int flag =  (age>=18) && (gender == 'M');

    printf("%s\n",flag==1?"是成年男性":"不是成年男性");



    return 0;

}