#include <iostream>

using namespace std;

//定义一个函数，返回 地址
int * func(){
    int * a = new int(10);//堆区开辟的空间
   
    return a;
}

int main() {

	int * p = func();

    cout<<*p<<endl;
    cout<<*p<<endl;
    cout<<p<<endl;

    //delete释放
    delete p;

    //手动置空
    p = NULL;

    if(p == nullptr){
        cout<<"堆内存已经释放"<<endl;
    }else{
        cout<<*p<<endl;
        cout<<*p<<endl;
     cout<<p<<endl;
    }
    

    return 0;
}

