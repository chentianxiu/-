#include<iostream>
#include<fstream>
using namespace std;//命名空间，标准库

class Student
{
public:
    string name;
    int age;
};


int main()
{   
    //数组
    const int numStudent = 3;
    Student students[numStudent];
    //遍历数组，进行赋值
    for (int i = 0; i < numStudent; i++)
    {
        cout<<"请输入第"<<i+1<<"个学生的姓名和年龄"<<endl;
        cin>>students[i].name>>students[i].age;
    }
    //文件写入功能
    ofstream file("student.ext",ios::out);

    //写入功能
    for (int i = 0; i < numStudent; i++)
    {
        file<<students[i].name<<" "<<students[i].age<<endl;
    }
    
    file.close();

    return 0;

}