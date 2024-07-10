#include <iostream>

using namespace std;


int main() {

    //new开辟数组
    int * arr = new int[10];

    //赋值
    for(int i=0;i<10;i++){
        arr[i] = i+100;
    }
    //打印
    for(int i=0;i<10;i++){
        cout<<arr[i]<<endl;
    }

    //释放
    delete[]  arr;
    //手动置空
    arr = nullptr;
    arr = NULL;

    /*
    NULL 是一个旧式的宏，通常定义为 0，容易引起类型不匹配的问题。
    nullptr 是 C++11 引入的关键字，类型为 std::nullptr_t，
    避免了类型不匹配的问题，并且在现代 C++ 编程中推荐使用。
    */
	
    return 0;
}



