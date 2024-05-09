#include<stdio.h>
#include "student.h"

Student input(){
    Student student;
    printf("请输入学生的学号:\n");
    scanf("%d",&(student.num));
    printf("请输入学生的姓名:\n");
    scanf("%s",student.name);
    student.date = inputDateValue();
    for (int i = 0; i < 3; i++)
    {
        printf("第%d科成绩:\n",i+1);
        scanf("%f",&(student.score[i]));
    }
    return student;
}

Date inputDateValue(){
    Date date;
    printf("请输入年:\n");
    scanf("%d",&date.year);
    printf("请输入月:\n");
    scanf("%d",&date.month);
    printf("请输入日:\n");
    scanf("%d",&date.day);
    return date;
}

void output(Student student){
    printf("学号:%d 姓名:%d 日期:%d-%d-%d\n",student.num,student.name,student.date.year,student.date.month,student.date.day);
    printf("成绩:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%.2f",student.score[i]);
    
    }
    printf("\n");
}

//指针类型输入学生信息
/*
void inputStu(Student* stu){
    printf("请输入学生学号：\n");
    scanf("%d",&stu->num);
    printf("请输入学生的姓名:\n");
    scanf("%s",stu->name);
    Date date = inputDateValue();
    stu->date = date;
    for(int i=0;i<3;i++){
        printf("第%d科成绩:\n",i+1);
    scanf("%f",&stu->score[i]);
    }
}
*/