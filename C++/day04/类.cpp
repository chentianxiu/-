#include<iostream>
using namespace std;//命名空间，标准库

class girlfriend
{

private:

    int age;//年龄


public:
    //成员变量
    string name;    //姓名
    string addr;       //住址
    double height;      //身高
    string phonenum;    //电话

    //函数(行为)
    void makecall()
    {
        cout<<"和女朋友打电话使用这个电话"<<phonenum<<endl;
    }
    void printfmsg()
    {
        cout<<"姓名:"<<name<<"\t";
        cout<<"住址:"<<addr<<"\t";
        cout<<"身高:"<<height<<"\t";
        cout<<"电话:"<<phonenum<<endl;;
    }

    //访问私有成员需要在类里面用公有部分的函数实现，类之外无法直接访问
    //获取年龄
    void getAge(int age)
    {
        if (age>=18&&age<50)
        {
            //this指向当前对象的指针
            this->age = age;
        }else{
            cout<<"年龄不符合要求"<<endl;
        }
        
    }
    //打印年龄
    void printAge()
    {
        cout<<"年龄是:"<<this->age<<endl;
    }
};

int main()
{
    girlfriend g1;
    g1.name="007";
    g1.addr = "上海";
    g1.height = 1.71;
    g1.phonenum = "12312312311";
    //访问私有成员需要在类里面用共有部分的函数实现，类之外无法直接访问
    g1.getAge(10);
    g1.printAge();

    g1.makecall();
    g1.printfmsg();
    return 0;

}