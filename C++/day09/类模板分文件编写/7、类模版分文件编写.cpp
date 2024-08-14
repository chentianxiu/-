#include<iostream>
#include<string>
using namespace std;
//#include"person.h"
//#include"person.cpp"
#include"person.hpp"//类模板中成员函数创建时机是在调⽤阶段，导致分⽂件编写时链接不到



void test01(){
	Person<string,int> p("猪八戒",888);
	p.showPerson();
}

int main() {

	test01();

	return 0;
}