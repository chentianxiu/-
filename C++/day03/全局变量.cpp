#include<iostream>
using namespace std;//命名空间，标准库

//全局变量
int a = 10;
int b = 20;

//全局常量
const int c_a = 10;
const int c_b = 10;





int main()
{
    //静态变量
    static int s_a = 10;
    static int s_b = 10;

    cout <<&a<<endl;//0x4030开头
    cout <<&b<<endl;

    cout <<&c_a<<endl;//0x4040开头
    cout <<&c_b<<endl;

    cout <<&s_a<<endl;//0x4030开头
    cout <<&s_b<<endl;
    //上面开头一样，可见都是全局区的

    //字符常量
    const char * str = "hello";
    const char * str1 = "world";

    cout<<(void *)str<<endl;
    cout<<&"hello"<<endl;

    //非全局区
    int j_a = 10;
    int j_b = 10;

    cout <<&j_a<<endl;//0x61开头
    cout <<&j_b<<endl;

    return 0;

}