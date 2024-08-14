/*
定义一个人员类 Person，包含数据成员:姓名、ID、性别和用于输入输出的虚函数
在此基础上派生出学生类 Student(增加成绩属性)和老师类 Teacher(增加教龄)，
并实现对学生和老师信息的输入输出。测试创建人员对象数组(两个人员，一个学生，一个老师)，
实现多态。
*/

#include<iostream>
using namespace std;

class Person
{
public:
    string m_name;
    int m_id;
    string gender;
    
    virtual void getmsg(){};

    virtual void printmsg(){};
};

//学生类
class Student :public Person
{
    public:
        double score;

        void getmsg(){
            cout << "输入学生信息：姓名, ID, 性别, 成绩" << endl;
            cin >> m_name >> m_id >> gender >> score;
        }

        void printmsg(){
            cout<<this->m_name<<" "<<this->m_id<<" "<<this->gender<<" "<<this->score<<endl;
        }
};

//老师类
class Teacher :public Person
{
    public:
        int age;

        void getmsg(){
            cout << "输入老师信息：姓名, ID, 性别, 教龄" << endl;
            cin >> m_name >> m_id >> gender >> age;
        }

        void printmsg(){
            cout<<this->m_name<<" "<<this->m_id<<" "<<this->gender<<" "<<this->age<<endl;
        }
};


int main()
{
    Person *p = new Student;
    p->getmsg();
    p->printmsg();

    Person *p1 = new Teacher;
    p1->getmsg();
    p1->printmsg();

    delete p;
    delete p1;
    
    return 0;
}