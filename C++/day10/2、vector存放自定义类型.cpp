#include<iostream>

using namespace std;
#include<vector>
#include<algorithm>

//自定义数据类型
class Person {
public:
	Person(string name, int age) {
		mName = name;
		mAge = age;
	}
public:
	string mName;
	int mAge;
};

void test01(){

    //创建容器/对象：Person/vector
    vector<Person> v;

    Person p1("唐三藏",30);
    Person p2("熏悟空",888);
    Person p3("猪八戒",999);
    Person p4("沙悟净",1000);

    //容器添加元素
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    //打印
    for(vector<Person>::iterator it = v.begin(); it != v.end();it++){//it是指针
        cout<<"姓名："<<it->mName<<" ，年龄："<<(*it).mAge<<endl;
        
    }
}

//放指针对象
void test02(){

    //指针
    vector<Person *> v;

    Person p1("唐三藏",30);
    Person p2("熏悟空",888);
    Person p3("猪八戒",999);
    Person p4("沙悟净",1000);

    // 添加到容器中
    //容器添加元素
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);


 //打印
    for(vector<Person *>::iterator it = v.begin(); it != v.end();it++){

        //每个元素
        Person * p = (*it);
        cout<<"姓名："<<p->mName<<" ，年龄："<<p->mAge<<endl;
        
    }


}

int main(){

    test02();
    return 0;
}