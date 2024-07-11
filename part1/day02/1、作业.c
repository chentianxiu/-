#include <stdio.h>

int main()
{
    char name[100]="";
    int age = 0;
    char gender[10]="";
    float high = 0;

    printf("请输入学生姓名:");
    scanf("%s",name);
    printf("请输入学生年龄:");
    scanf("%d",&age);
    printf("请输入学生性别:");
    scanf("%s",gender);
    printf("请输入学生身高:");
    scanf("%f",&high);

    printf("姓名\t年龄\t性别\t身高\n%s\t%d\t%s\t%.2f\n",name,age,gender,high);


    return 0;
    
}