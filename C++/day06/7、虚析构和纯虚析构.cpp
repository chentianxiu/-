#include<iostream>
#include<string>
using namespace std;

class Animal{
public:
    virtual void Speak() = 0;

    Animal(){
        cout<<"Animal的构造函数"<<endl;
    }
    // virtual ~Animal(){
    //     cout<<"Animal的析构函数"<<endl;
    // }
    //父类的纯虚析构
    virtual ~Animal()= 0;
};
//纯虚析构函数需要在类外定义
Animal::~Animal(){
    cout<<"Animal的纯虚析构函数"<<endl;
}

class Cat : public Animal{

public:
    string * m_name;

    //有参构造：创建
    Cat(string name){
        cout<<"Cat的有参构造"<<endl;
        m_name = new string(name);
    }
    //析构函数：删除
    ~Cat(){
        cout<<"Cat的析构函数"<<endl;
        if(m_name!=NULL){
            delete m_name;
            m_name = NULL;
        }
    }

    virtual void Speak(){
        cout<<*m_name<<"猫在喵喵叫"<<endl;
    }

};

int main(){

    Animal * animal = new Cat("Tom");

    animal->Speak();

    //删除
    delete animal;
 
    
	
    return 0;
}

