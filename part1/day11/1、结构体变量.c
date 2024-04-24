#include <stdio.h>
#include<string.h>

struct Student
{
    char name[20];
    int age;
    char gender[5];
    char id[20];
};


int main()
{
    //定义一个结构体变量并且初始化
    struct Student stu1={ "张三",18,"男","s001"};
    struct Student stu2={ "李四",19,"女","s002"};

    //strcpy(stu1.name,"张三");
    //stu1.age = 18;
    //strcpy(stu1.gender,"男");
    //strcpy(stu1.id,"s001");

    //成员访问
    printf("姓名:%s\n",stu1.name);
    printf("年龄:%d\n",stu1.age);
    printf("性别:%s\n",stu1.gender);
    printf("学号:%s\n",stu1.id);

    printf("姓名:%s\n",stu2.name);
    printf("年龄:%d\n",stu2.age);
    printf("性别:%s\n",stu2.gender);
    printf("学号:%s\n",stu2.id);

    return 0;
    
}