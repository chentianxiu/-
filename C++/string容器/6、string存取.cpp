#include<iostream>

using namespace std;
#include <string>

void test01(){

    string str = "hello world";

    //第一种方式  []
    for(int i=0;i<str.length();i++){
        cout<<str[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<str.size();i++){
        cout<<str[i]<<" ";
    }

    cout<<endl;

    //第二种
    for(int i=0;i<str.size();i++){
        cout<<str.at(i)<<" ";//索引为i的字符是什么
    }
     cout<<endl;

    //修改？
    str[0] ='H';
    cout<<"修改之后:"<<str<<endl;
    str.at(1) = 'E';
    cout<<"修改之后:"<<str<<endl;


}

int main (){

    test01();
    return 0;
}