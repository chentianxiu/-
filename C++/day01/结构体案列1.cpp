/*
学校正在做毕设项目，每名老师带领5个学生，总共有3名老师，需求如下
设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员
学生的成员有姓名、考试分数，创建数组存放3名老师，通过函数给每个老师及所带的学生赋值
最终打印出老师数据以及老师所带的学生数据。
*/

#include<iostream>
#include<ctime>
#include<sstream> // 引入stringstream
using namespace std;//命名空间，标准库

struct student
{
    string name;
    int score;
};

struct teacher
{
    string name;
    student stu[5]; 
};

void Write(teacher *t)//写入数据
{
    for (int i = 0; i <3; i++)
    {
        // cout<<"请输入第"<<i+1<<"个老师的姓名"<<endl;
        // cin>>t[i].name;
        t[i].name = 'a'+i;
        for (int j = 0; j < 5; j++)
        {
            // cout<<"请输入第"<<j+1<<"个学生的姓名"<<endl;
            // cin>>t[i].stu[j].name;
            // cout<<"请输入这个学生的成绩"<<endl;
            // cin>>t[i].stu[j].score;
            stringstream ss;
            ss << t[i].name << j;
            t[i].stu[j].name = ss.str();
            t[i].stu[j].score = rand()%60+40;
        }
    }
    
}

void Print(teacher *t)
{
    for (int i = 0; i < 3; i++)
    {
        cout<<"第"<<i+1<<"个老师名字是"<<t[i].name<<endl;
        for (int j = 0; j < 5; j++)
        {
            cout<<"第"<<j+1<<"个学生姓名是:"<<t[i].stu[j].name<<"成绩是:"<<t[i].stu[j].score<<endl;
        }
        
    }
}



int main()
{
    teacher t[3];
    srand(time(NULL));
    
    Write(t);//录入数据
    Print(t);//打印数据
    return 0;
}