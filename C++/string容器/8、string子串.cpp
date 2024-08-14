#include<iostream>

using namespace std;
#include <string>

void test01(){

    string str = "abcdefghijk";

    string subStr = str.substr(1,3);

    cout<<"subStr:::"<<subStr<<endl;//bcd
    cout<<"str:::"<<str<<endl;//

    string email = "lisi@163.com";
    //获取用户名

    //先找到用户名之前的索引
    int pos = email.find("@");
    string username = email.substr(0,pos);
    cout<<"用户名:"<<username<<endl;


}

int main (){

    test01();
    return 0;
}