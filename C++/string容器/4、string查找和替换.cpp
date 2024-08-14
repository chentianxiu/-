#include<iostream>

using namespace std;
#include <string>

//查找
void test01(){

    string str1 = "abcdefghiabcdeabc";

    int pos = str1.find("de");//从左往右查找第一次出现的位置

    if(pos>=0){
        cout<<"pos:"<<pos<<endl;
    }else if(pos == -1){
        cout<<"pos:"<<pos<<endl;
    }

    pos = str1.rfind("de");//从右往左查找第一次出现的位置
    cout<<"pos:"<<pos<<endl;

}

//替换
void test02(){

    string str1 = "abcdefghijkl";

    str1.replace(2,3,"HELLO");
    cout<<"str1:"<<str1<<endl;//abHELLOfghijkl
}


int main (){

    test01();
    //test02();

    return 0;
}