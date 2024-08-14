#include<iostream>

using namespace std;
#include <string>

void test01(){


    string str = "hello";
    str.insert(1,"111");
    cout<<"str:"<<str<<endl;//   h111ello

    str.insert(1,2,'2');
    cout<<"str:"<<str<<endl;// h22111ello

    //删除
    str.erase(1,5);
    cout<<"str:"<<str<<endl;


}

int main (){

    test01();
    return 0;
}