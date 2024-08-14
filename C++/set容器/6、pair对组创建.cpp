#include<iostream>
using namespace std;
#include<string>


void test01() {
	
    pair<string,int> p(string("Tom"),18);

    cout<<"姓名："<<p.first<<"，年龄:"<<p.second<<endl;

    pair<string,int> p2 = make_pair("tony",21);
     cout<<"姓名："<<p2.first<<"，年龄:"<<p2.second<<endl;
	
}

int main(){

    test01();
    return 0;
}