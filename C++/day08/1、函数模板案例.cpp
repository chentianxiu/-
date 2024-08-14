#include<iostream>
using namespace std;//命名空间，标准库

template<typename T>//typename可以用class代替
void mySwap(T & a,T & b){//传过来的参数类型不确定，用T表示
    //交换
    T temp = a;
        a  = b;
        b = temp;
}



int main()
{
    //1、自动类型推导
    int a = 10;
    int b = 20;

    mySwap(a,b);

    cout<<a<<"\t"<<b<<endl;

    //2、显示指定类型

    double c = 1.1;
    double d = 2.2;

    mySwap<double>(c,d);
    cout<<c<<"\t"<<d<<endl;

    return 0;

}