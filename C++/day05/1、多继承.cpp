#include <iostream>

using namespace std;


//定义父类
class Base1{
public:
    int m_A;
    Base1(){
        m_A = 100;
    }
};
class Base2{
public:
    int m_B;
    Base2(){
        m_B = 200;
    }
};

//子类多继承
class Son :public Base1,public Base2{

public:
    int m_C;
    int m_D;
    Son(){
        m_C = 300;
        m_D = 400;
    }
};

int main(){

    //创建子类对象
    Son son;

    cout<<"son的大小:"<<sizeof(Son)<<endl;//16

    cout<<son.m_A<<endl;
    cout<<son.m_B<<endl;
    cout<<son.m_C<<endl;
    cout<<son.m_D<<endl;

   
    return 0;
}


