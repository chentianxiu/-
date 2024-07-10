#include <iostream>

using namespace std;


int main() {

    int a = 10;
    int c = 20;

    cout<<"a的地址："<<&a<<endl;
    //必须初始化一下
    //int & b;//不知道指向哪里
    //引用:地址不能改变，值可以改变
    int & b = a;
    cout<<"b的地址："<<&b<<endl;

    b = c;//重新赋值

    cout<<"a:"<<a<<endl;
    cout<<"a的地址："<<&a<<endl;
    cout<<"b的地址："<<&b<<endl;

    b = 100;//重新赋值

    cout<<"a:"<<a<<endl;
    cout<<"a的地址："<<&a<<endl;
    cout<<"b的地址："<<&b<<endl;
    
	
    return 0;
}



