#include <iostream>

using namespace std;

//定义一个函数，返回 地址
int * func(){
    int * a = new int(10);//堆区开辟的空间
    cout<<"函数中地址："<<a<<endl;
    return a;//a:指针变量，里面存放的是 堆中的地址
                //a：依然还是局部变量
}

int main() {

	int * p = func();
    cout<<"main函数中地址："<<p<<endl;

    cout<<*p<<endl;
    cout<<"main函数中地址："<<p<<endl;

    cout<<*p<<endl;

    return 0;
}

