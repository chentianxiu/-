#include<iostream>
#include<string>
using namespace std;

//定义父类模板
template<class T>
class Base{
	T m;
};

//普通子类
class Son:public Base<int>{

};

void test01(){
	Son s;
}

//子类也为模版类
template<class T1,class T2>
class Son2:public Base<T2>{
public:
	Son2(){
		cout<<typeid(T1).name()<<endl;
		cout<<typeid(T2).name()<<endl;
	}
};

void test02(){
	Son2<int,char> son2;
}

int main(){

	test02();

	return 0;
}