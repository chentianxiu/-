#include<iostream>
#include<set>
using namespace std;

class Person{

public:
    string name;
    int age;

    Person(string name,int age){
        this->name = name;
        this->age = age;
    }
};

class compare{
    public:
        bool operator()(const Person &s1,const Person s2){
            if (s1.age==s2.age)
            {
                return s1.name > s2.name;
            }else
            {
                return s1.age > s2.age;
            }
        }

};

void print(set<Person,compare> & s){
    for (set<Person,compare>::iterator it = s.begin();it!=s.end();++it)
    {
        cout<<(*it).name<<" "<<(*it).age<<endl;
    }
    
}


int main()
{
    set<Person,compare> s1;
    
    //插入数据
    Person p1("刘备", 27);
	Person p2("关羽", 27);
	Person p3("张飞", 25);
	Person p4("赵云", 21);
    Person p5("刘备", 27);

    s1.insert(p1);
    s1.insert(p2);
    s1.insert(p3);
    s1.insert(p4);
    s1.insert(p5);

    print(s1);
}