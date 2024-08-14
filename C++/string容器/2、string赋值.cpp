#include<iostream>

using namespace std;
#include <string>

void test01(){

    string str1;
    str1 = "hello world";
    cout<<"str1:"<<str1<<endl;

    string str2;
    str2 = str1;
    cout<<"str2:"<<str2<<endl;

    string str3;
    str3 = 'a';
    cout<<"str3:"<<str3<<endl;

    string str4;
    str4.assign("hello C++");
    cout<<"str4:"<<str4<<endl;

    string str5;
    str5.assign("hello C++",5);//前五个字符赋值
    cout<<"str5:"<<str5<<endl;//hello

    string str6;
    str6.assign(str5);
    cout<<"str6:"<<str6<<endl;//hello

    string str7;
    str7.assign(10,'a');
    cout<<"str7:"<<str7<<endl;//aaaaaaaaaa


}


int main (){

   test01();
    return 0;
}