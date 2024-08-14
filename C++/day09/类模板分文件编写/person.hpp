#pragma once
#include<iostream>
using namespace std;
#include<string>

//类模版
template<class T1,class T2>
class Person{

public:
	T1 m_Name;
	T2 m_Age;
	//构造函数声明
	Person(T1 name,T2 age);
	//定义另一个函数声明
	void showPerson();

};

//类外实现
template<class T1,class T2>
Person<T1,T2>::Person(T1 name,T2 age){
	this->m_Name = name;
	this->m_Age = age;
}
template<class T1,class T2>
void Person<T1,T2>::showPerson(){
	cout<<this->m_Name<<this->m_Age<<endl;
}