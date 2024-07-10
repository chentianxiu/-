#include<iostream>
using namespace std;//命名空间，标准库

class girlfriend
{
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
};

int main()
{
    girlfriend g1;
    g1.name="007";
    g1.addr = "上海";
    g1.height = 1.71;
    g1.phonenum = "12312312311";

    g1.makecall();
    g1.printfmsg();
    return 0;

}