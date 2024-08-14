#include<iostream>

using namespace std;
#include <string>

void test01(){

    string s1 = "aello";
    string s2 = "hzllo";

    int res = s1.compare(s2);//res的值是具体的差值
    cout<<res<<endl;
    if(res==0){
        cout<<"相等"<<endl;
    }else if(res>0){
         cout<<"s1大于s2"<<endl;
    }else{
        cout<<"s1小于s2"<<endl;
    }

}

int main (){

    test01();

    return 0;
}