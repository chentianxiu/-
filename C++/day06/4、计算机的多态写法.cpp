#include<iostream>

using namespace std;

//计算器类：类里只有一个函数
class AbstractCalculator{
public:
    int m_Num1;
	int m_Num2;

//定义一个函数，规定了计算器运算的结果，不知道什么运算
//虚函数
    virtual int getResult(){
        return 0;
    }
};

//加号
class AddCalculator:public AbstractCalculator{
public:
    //重写计算的函数
    virtual int getResult(){
        return m_Num1+m_Num2;
    }
};

//减法计算器
class MulCalculator:public AbstractCalculator{
public:
    //重写计算的函数
    virtual int getResult(){
        return m_Num1-m_Num2;
    }
};

//乘法计算器
class SubCalculator:public AbstractCalculator{
public:
    //重写计算的函数
    virtual int getResult(){
        return m_Num1*m_Num2;
    }
};

//除的操作，功能



//定义函数，指向具体的操作
void test02(int num1,int num2){

    //加号操作
    //创建加号的对象
    // AddCalculator add;
    // add.m_Num1 = num1;
    // add.m_Num2 = num2;
    // cout<<num1<<"+"<<num2<<"="<<add.getResult()<<endl;

    // MulCalculator mul;
    // mul.m_Num1 = num1;
    // mul.m_Num2 = num2;
    // cout<<num1<<"-"<<num2<<"="<<mul.getResult()<<endl;

    // SubCalculator sub;
    // sub.m_Num1 = num1;
    // sub.m_Num2 = num2;
    // cout<<num1<<"*"<<num2<<"="<<sub.getResult()<<endl;

    //new，堆内存创建
     // Dog * dog  = new Dog;
    //  Animal & animal = dog;


    //创建 加法计算器
    AbstractCalculator * abs = new AddCalculator;
    abs->m_Num1 = num1;
    abs->m_Num2 = num2;
    cout<<num1<<"+"<<num2<<"="<<abs->getResult()<<endl;
    //删除
    delete abs;
    //创建 减法计算器
    abs = new MulCalculator;
    abs->m_Num1 = num1;
    abs->m_Num2 = num2;
    cout<<num1<<"-"<<num2<<"="<<abs->getResult()<<endl;
    delete abs;
    //创建 乘法计算器
    abs = new SubCalculator;
    abs->m_Num1 = num1;
    abs->m_Num2 = num2;
    cout<<num1<<"*"<<num2<<"="<<abs->getResult()<<endl;

}

int main(){
    
    test02(10,5);
    
    return 0;
}

