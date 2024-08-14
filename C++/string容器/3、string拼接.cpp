#include<iostream>

using namespace std;
#include <string>

void test01(){

    string str1 = "我";

    str1 += "爱玩游戏";

    cout<<"str1:"<<str1<<endl;

    str1 +=':';
    cout<<"str1:"<<str1<<endl;//str1 我爱玩游戏:

    string str2 = "LOL DNF"; 

    str1 += str2;
    cout<<"str1:"<<str1<<endl;//str1 我爱玩游戏:LOL DNF

    string str3 = "I";
    str3.append(" Love ");
    cout<<"str3:"<<str3<<endl;

    str3.append("game abdcdsd",4);
    cout<<"str3:"<<str3<<endl;

    str3.append(str2);
    cout<<"str3:"<<str3<<endl;

    str3.append("helloworld",2,3);//I Love gameLOL DNFllo
    cout<<"str3:"<<str3<<endl;

}


int main (){

test01();
    return 0;
}