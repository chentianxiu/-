#include <stdio.h>
#include<string.h>


struct DATA//日期结构体
{
    int year;
    int month;
    int day;
};

struct Teacher//老师结构体
{
    char name[20];
    char id[20];
};

struct Student//学生结构体
{
    char name[20];
    int age;
    char gender[5];
    char id[20];
    int score[3];//储存数组
    struct DATA date;//成员变量是结构体
    struct Teacher teacher;//成员变量是结构体

};


int main()
{
    //定义一个结构体变量并且初始化
    //struct Student stu3 = {};
    //struct Student stu1={ "张三",18,"男","s001"};
    struct Student stu1={ "张三",18,"男","s001",{52,55,93},{2001,5,10}};
    struct Student stu2={ "李四",19,"女","s002"};

    struct Teacher t ;

    strcpy(t.name,"余老师");
    strcpy(t.id,"t001");
    stu1.teacher = t;
    
    



    //stu1.score[0]=80;
    //stu1.score[1]=55;
    //stu1.score[2]=99;

    //strcpy(stu1.name,"张三");
    //stu1.age = 18;
    //strcpy(stu1.gender,"男");
    //strcpy(stu1.id,"s001");

    //成员访问
    printf("姓名:%s\n",stu1.name);
    printf("年龄:%d\n",stu1.age);
    printf("性别:%s\n",stu1.gender);
    printf("学号:%s\n",stu1.id);
    printf("语文：%d  数学：%d  英语:%d\n",stu1.score[0],stu1.score[1],stu1.score[2]);
    printf("年：%d  月：%d  日:%d\n",stu1.date.year,stu1.date.month,stu1.date.day);
    printf("老师姓名：%s\n",stu1.teacher.name);
    printf("老师编号：%s\n",stu1.teacher.id);

    printf("姓名:%s\n",stu2.name);
    printf("年龄:%d\n",stu2.age);
    printf("性别:%s\n",stu2.gender);
    printf("学号:%s\n",stu2.id);
    //printf("老师姓名：%d\n",stu2.teacher.t_name);
    //printf("老师编号：%d\n",stu2.teacher.t_id);

    return 0;
    
}