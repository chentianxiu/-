#include<stdio.h>
#include <string.h>
#include "student.h"


int main(){
    //创建学生体结构体
    Student stus[3];

    FILE * file = NULL;

    file = fopen("stu.txt","r");

    if (file == NULL)
    {
        printf("打开文件失败\n");
        return 1;
    }

    int num11 = 0;
    
    while (fscanf(file,"%d\t%s\t%d\t%d\t%d\n",
        &stus[num11].stuId,stus[num11].stuName,&stus[num11].score[0],&stus[num11].score[1],
        &stus[num11].score[2])!=EOF)
    {
        num11++;
    }

    fclose(file);
    if (num11 == 0)
    {
        inputAllStudent(stus,3);
    }
    
    
    outputAllStudent(stus,3);

    printf("查询单门学科成绩平均值\n");

    int flag1 = 1;
    while (flag1)
    {
        printf("请输入学科编号：语文0，数学1，英语2,退出3\n");
        int course;
        scanf("%d",&course);
        float avg = AvgStudent(stus,3,course);
        switch (course)
        {
        case 0:
            printf("语文成绩的平均值是%.2f\n",avg);
            break;
        case 1:
            printf("数学成绩的平均值是%.2f\n",avg);
            break;
        case 2:
            printf("英语成绩的平均值是%.2f\n",avg);
            break;
        case 3:
            flag1 = 0;
            break;
        default:
            printf("课程编号输入有误\n");
            break;
        }
    }

    //查询三门课程平均值
    //建立一个平均值数组
    printf("三门课程的平均成绩是\n");
    float avgarr[3];
    avgAllscore(stus,3,avgarr);
    //遍历获取成绩
    printf("语文\t\t数学\t\t英语\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%.2f\t\t",avgarr[i]);
    }
    printf("\n");

    //获取单个学生的总成绩
    printf("查询单个学生总成绩\n");

    int flag2 = 1;
    while (flag2)
    {
        printf("请输入学生编号：1~3，退出4\n");
        int Num = 0;
        scanf("%d",&Num);
        int sum = sumAllscore(&stus[Num-1]);
        //printf("%d\n",sumAllscore(&stus[0]));
        //printf("%d\n",sumAllscore(&stus[1]));
        //printf("%d\n",sumAllscore(&stus[2]));
        switch (Num-1)
        {
        case 0:
            printf("学生%s的总成绩是%d\n",((stus+Num-1))->stuName,sum);
            break;
        case 1:
            printf("学生%s的总成绩是%d\n",((stus+Num-1))->stuName,sum);
            break;
        case 2:
            printf("学生%s的总成绩是%d\n",((stus+Num-1))->stuName,sum);
            break;
        case 3:
            flag2 = 0;
            break;
        default:
            printf("学生编号输入有误\n");
            break;
        }
    }

    if (num11 == 0)
    {
    FILE * file1 = NULL;

    file1 = fopen("stu.txt","a");

    if (file1 == NULL)
    {
        printf("打开文件失败\n");
        return 1;
    }

    for (int i = 0; i < 3; i++)
    {
        fprintf(file1,"%d\t%s\t%d\t%d\t%d\n",stus[i].stuId,
        stus[i].stuName,stus[i].score[0],stus[i].score[1],stus[i].score[2]);
    }
    
    fclose(file1);
    }

    return 0;
}