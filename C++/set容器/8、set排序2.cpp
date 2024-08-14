#include<iostream>
using namespace std;
#include <set>


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

class comparePerson{
public:
    bool operator()(const Person & p1,const Person & p2){
        //年龄从大到小排序  降序
        if(p1.m_Age == p2.m_Age){
            return p1.m_Name > p2.m_Name;
        }else{
            return p1.m_Age > p2.m_Age;
        }   
    }
};

void test01() {
	
    set<Person,comparePerson> s;

    //插入数据
    Person p1("刘备", 27);
	Person p2("关羽", 27);
	Person p3("张飞", 25);
	Person p4("赵云", 21);
    Person p5("刘备", 27);

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);
    s.insert(p5);

    //遍历
    for(set<Person,comparePerson>::iterator it = s.begin();it!=s.end();it++){
        cout<<"姓名："<<it->m_Name<<"，年龄："<<it->m_Age<<endl;
    }
}




int main(){

    test01();
    return 0;
}