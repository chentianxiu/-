#include<iostream>
using namespace std;//命名空间，标准库

//创建父类
class Base
{
public:
    int m_A;

    Base(){
        m_A = 100;
    }
    void fun()
    {
        cout<<"Base--fun()调用"<<endl;
    }
    void fun(int a){
        cout<<"Base--fun(itn a)调用"<<endl;
    }
};

//子类
class Son :public Base{

public:
    int m_A;

    Son(){
        m_A = 200;
    }
    void fun(){
        cout<<"Son--fun(调用)"<<endl;
    }
    void fun(int a){
        cout<<"Son--fun(int a)(调用)"<<endl;
    }
};


int main()
{
    //创建对象
    Son son;

    //访问子类成员：直接访问
    cout<<son.m_A<<endl;
    son.fun();
    son.fun(10);

    //访问父类成员：添加父类作用域
    cout<<son.Base::m_A<<endl;
    son.Base::fun();
    son.Base::fun(10);

    return 0;

}