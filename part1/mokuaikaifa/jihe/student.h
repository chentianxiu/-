#ifndef STUDENT_H
#define STUDENT_H
//学生结构体

typedef struct student {
    int stuId;
    char stuName[20];
    int score[3];
}Student;

//typedef struct student Student;

//键盘录入单个学生
void inputStudent(Student *stu);

//录入所有学生
void inputAllStudent(Student *stuArr,int num);

//输出单个学生
void outputStudent(Student *stu);

//输出所有学生
void outputAllStudent(Student *stuArr,int num);

//求单门成绩的平均值
float AvgStudent(Student *stuArr,int num,int course);
//Student *stuArr 学生数组   int num 学生数量  course 课程编号

//求三门课程的平均值
void avgAllscore(Student *stuArr,int num,float *avgScoreArr);
//float * avgScoreArr：平均成绩汇总


//求某个学生的总成绩
int sumAllscore(Student *stu);

#endif




