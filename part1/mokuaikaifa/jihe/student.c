#include<stdio.h>
#include "student.h"

//键盘录入单个学生
void inputStudent(Student *stu){
    //输入学生信息
    printf("请输入学生学号\n");
    scanf("%d",&stu->stuId);
    printf("请输入学生的姓名\n");
    scanf("%s",stu->stuName);
    printf("请输入学生的语文、数学、英语成绩:\n");
    scanf("%d%d%d",&stu->score[0],&stu->score[1],&stu->score[2]);
    return;
}

//录入所有学生
void inputAllStudent(Student *stuArr,int num){
    
    for (int i = 0; i < num; i++)
    {
        printf("请输入第%d个学生的信息:\n",i+1);
        inputStudent(stuArr+i);
    }

}

//输出单个学生
void outputStudent(Student *stu){
    printf("%d\t%s\t",stu->stuId,stu->stuName);
    printf("%d\t%d\t%d\n",stu->score[0],stu->score[1],stu->score[2]);
}

//输出所有学生
void outputAllStudent(Student *stuArr,int num){
    printf("展示学生信息\n");
    printf("姓名\t学号\t语文\t数学\t英语\n");
    for(int i = 0;i<num;i++){
        outputStudent(stuArr+i);
    }
}

//求单门成绩的平均值
float AvgStudent(Student *stuArr,int num,int course){
    int sum = 0;
    for(int i=0;i<num;i++){
        sum+=(stuArr+i)->score[course];
    }
    float avg =0;
    avg= ((float)sum/num);
    return avg;
}

//求三门课程的平均值
void avgAllscore(Student *stuArr,int num,float *avgScoreArr){
    int course = 0;
    for (course = 0; course < 3; course++)
    {
        *(avgScoreArr+course) = AvgStudent(stuArr,num,course);
    }
    
}

//求某个学生的总成绩
int sumAllscore(Student *stu){
    int sum = 0;

    for(int i=0;i<3;i++){
        
        //printf("测试i的值%d",stu->score[i]);
        sum += stu->score[i];

    }
    //printf("\n");

    return sum;

}
