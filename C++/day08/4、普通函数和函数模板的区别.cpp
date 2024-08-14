#include<iostream>

using namespace std;

//普通函数
int myAdd01(int a,int b){
    return a+b;
}

//函数模版
template<class T>
T myAdd02(T a,T b){
    return a + b;
}


int main(){

    int a = 10;
    int b = 20;
    char c = 'a';//97

    // 普通函数调用，可以发生隐式转换
    cout<<myAdd01(a,c)<<endl;

    //函数模版,不能使用隐式转换
    //myAdd02(a,c);

    //使用显示指定类型
    cout<<myAdd02<int>(a,c)<<endl;

	
    return 0;
}



