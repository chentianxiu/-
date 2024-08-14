#include<iostream>

using namespace std;
#include <string>

//string构造
void test01(){

    //创建一个空字符串
    string s1;//调用strng类的无参构造
    cout<<"str1："<<s1<<endl;//NULL 报错  什么都没有

    const char * str = "hello world";
    string s2(str);
    cout<<"str2："<<s2<<endl;

     string s3(s2);
    cout<<"str3："<<s3<<endl;

    string s4(10,'a');//10个a
    cout<<"str4："<<s4<<endl;//aaaaaaaaaa

    string s5 = "hello world";
    cout<<"str5："<<s5<<endl;

    string s6 = s5;
    cout<<"str6："<<s6<<endl;



}


int main (){

    test01();
    
    return 0;
}