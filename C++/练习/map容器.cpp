/*
有 Student 定义如下
class Student{
int id;
string name;
要求:使用 Student 作为 map 的键,学生分数为map 
的值(定义如:map<Student, doulestuMap)创建 map 容器，并对学生信息进行访问。
*/

#include<iostream>
using namespace std;
#include<map>

class Student
{
    public:
        int id;
        string name;
    
    Student(int i,string n){
        this->id = i;
        this->name = n;
    }

    bool operator<(const Student & s) const{
        return id<s.id;
    }
};


int main()
{
    map<Student,double> mStudent;

    Student s1(1,"zhangsan");

    mStudent.insert(make_pair(s1,100.00));

    for (map<Student,double>::iterator it=mStudent.begin();it!=mStudent.end();++it)
    {
        cout<<"编号"<<(*it).first.id<<"姓名"<<(*it).first.name<<"成绩"<<(*it).second;
    }
    
}