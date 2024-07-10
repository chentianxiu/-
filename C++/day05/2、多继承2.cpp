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
    int m_A;
    Base2(){
        m_A = 200;
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

    //定义子类
    Son son;
    cout<<sizeof(Son)<<endl;

    //cout<<son.m_A<<endl;//不明确,二异性
    //作用
    //多继承中如果父类出现同名，则调用要加作用域
    cout<<son.Base1::m_A<<endl;
    cout<<son.Base2::m_A<<endl;

    cout<<son.m_C<<endl;
    cout<<son.m_D<<endl;

   
    return 0;
}


