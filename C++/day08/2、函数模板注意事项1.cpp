#include<iostream>

using namespace std;

//必须推到出一致的数据类型

template<class T> //告诉编译器，有个T，至于是什么类型，你不用管
void mySwap(T &a,T & b){
    T temp = a;
    a = b;
    b = temp;
}

template<class T>
void func(){
    cout<<"函数"<<endl;
}

int main(){

    int a = 10;
    int b = 20;
    char c = 'c';

    mySwap(a,b);//可以的
    //mySwap(a,c);不行，自动类型推导类型必须一致

    //func();没有确定T的类型，会报错

    func<double>();//使用显示指定类型

   
    return 0;
}



