#include <iostream>

using namespace std;

//定义一个函数，返回 地址
int * func(){
    int a = 10;

    return &a;
}

int main(){

    int * p = func();

    cout<<*p<<endl;
    cout<<*p<<endl;
    /*
    int a = 10; 是一个局部变量，其生命周期仅限于 func 函数的执行期间。
    函数返回后，这个变量就不再存在，指向它的指针也变得无效。
    */

    return 0;
}
