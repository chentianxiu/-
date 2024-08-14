#include<iostream>
using namespace std;
#include <queue>
#include <string>
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

void test01() {

	
	//创建队列  queue
	queue<Person> q;

	//准备数据
	Person p1("唐僧", 30);
	Person p2("孙悟空", 1000);
	Person p3("猪八戒", 900);
	Person p4("沙僧", 800);

	//添加元素
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	cout<<"大小："<<q.size()<<endl;

	cout<<"最后元素大小："<<q.back().m_Name<<endl;

	//遍历
	while(!q.empty()){
		//输出头
		cout<< "姓名："<<q.front().m_Name<<",年龄："<<q.front().m_Age<<endl;
		//删除头
		q.pop();
	}

	cout<<"大小："<<q.size()<<endl;
}




int main(){

    test01();
    return 0;
}