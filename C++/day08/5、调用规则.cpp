#include<iostream>

using namespace std;

//普通函数与函数模板调用规则
void myPrint(int a ,int b){
    cout<<"普通函数调用"<<endl;
}

template<class T>
void myPrint(T a ,T b){
    cout<<"函数模版调用"<<endl;
}

template<class T>
void myPrint(T a ,T b,T c){
    cout<<"函数模版重载调用"<<endl;
}



int main(){

	int a = 10;
    int b = 20;

    myPrint(a,b);//调用普通函数

    myPrint<>(a,b);//空模板参数列表来强制调用函数模板

    int c = 30;
    myPrint(a,b,c);//函数模板也可以发生重载

    char c1 = 'a';
    char c2 = 'b';
    myPrint(c1,c2);//如果函数模板可以产生更好的匹配，优先调用函数模板

    return 0;
}



