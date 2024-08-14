#include<iostream>
using namespace std;
#include <list>

//定义Person
class Person{
public :
	string m_Name;
	int m_age;
	int m_height;
	Person(string name,int age,int height){
		this->m_Name = name;
		this->m_age = age;
		this->m_height = height;
	}
};

//自定义函数MyCompare，年龄升序，年龄相同时身高降序
bool MyCompare(Person & p1,Person & p2){
	
	if(p1.m_age == p2.m_age){
		//身高降序
		return p1.m_height > p2.m_height;
	}else{
		//年龄升序
		return p1.m_age < p2.m_age;
	}
}


void test01() {

	//创建list容器
	list<Person> l;

	//创建对象
	Person p1("刘备", 35 , 175);
	Person p2("曹操", 45 , 180);
	Person p3("孙权", 40 , 170);
	Person p4("赵云", 25 , 190);
	Person p5("张飞", 35 , 160);
	Person p6("关羽", 35 , 200);

	//对象放入到容器中
	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);
	l.push_back(p6);

	//测试
	for(list<Person>::iterator it = l.begin();it!=l.end();it++){
		cout<<"姓名："<<it->m_Name<<",年龄:"<<it->m_age<<",身高:"<<it->m_height<<endl;
	}


	//排序：  年龄升序，，如果年龄相同，身高降序
	cout<<"==============="<<endl;

	l.sort(MyCompare);
	
	for(list<Person>::iterator it = l.begin();it!=l.end();it++){
		cout<<"姓名："<<it->m_Name<<",年龄:"<<it->m_age<<",身高:"<<it->m_height<<endl;
	}
}




int main(){

    test01();
    return 0;
}