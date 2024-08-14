#include<iostream>
#include<string>
using namespace std;

template<class T1,class T2> class Person;

template<class T1,class T2>
void showPerson2(Person<T1,T2> & p){
	cout<<"Person2姓名："<<p.m_Name<<"，Person2年龄："<<p.m_Age<<endl;
}

template<class T1,class T2>
class Person{

friend void showPerson(Person<T1,T2> & p){
		cout<<"姓名："<<p.m_Name<<"，年龄："<<p.m_Age<<endl;
	}

friend void showPerson2<>(Person<T1,T2> & p);
//在 friend void showPerson2<>(Person<T1, T2>& p); 中使用 <> 
//是为了明确指出 showPerson2 是一个模板函数。这种写法的好处如下：

private:
	T1 m_Name;
	T2 m_Age;
public :
	Person(T1 name,T2 age){
		this->m_Name = name;
		this->m_Age = age;
	}


};



void test01(){
	Person<string,int> p("唐僧",30);
	showPerson(p);
}

void test02(){
	Person<string,int> p("沙和尚",999);
	showPerson2(p);
}

int main() {

	test02();

	return 0;
}