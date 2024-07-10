#include<iostream>
using namespace std;//命名空间，标准库

//定义学生类
class Student
{
private:
    string name;
    int age;
public:
    //构造函数--无参
    Student(/* args */)
    {

    }

    //构造函数--满参
    Student(string name,int age)
    {
        this->name = name;
        this->age = age;
    }

    //析构函数
    ~Student()
    {
        //只是一个提示作用
        cout<<this->name<<"对象已经销毁"<<endl;
    }

    //功能函数
    //提供set和get函数
    void setName(string name)
    {
        this->name = name;
    }

    string getName()
    {
        return this->name;
    }
};


int main()
{
    

    return 0;

}