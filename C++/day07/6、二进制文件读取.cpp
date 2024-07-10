#include<iostream>
using namespace std;

//1、引入头文件
#include<fstream>
#include<string>

class Person{
public:
	char name[20];
	int age;
};

int main(){

	//2、创建流对象
	ifstream ifs("preson.txt",ios::binary|ios::in);

	//3、判断
	if(!ifs.is_open()){
		cout<<"文件打开失败"<<endl;
		return 0;
	}

	//4、读取
	Person p;

	ifs.read((char *)&p,sizeof(p));

	cout<<"姓名："<<p.name<<"\t年龄："<<p.age<<endl;

	//5、关闭
	ifs.close();


    return 0;
}


