#include<iostream>

using namespace std;

class Animal{
public :
    //虚函数
    virtual void speak(){
        cout<<"动物在叫"<<endl;
    }
};

class Dog:public Animal{ };

int main(){
    
   
    cout<<"Animal的大小："<<sizeof(Animal)<<endl;//什么是1？空类：1
                                                //8
    
    cout<<"Dog:"<<sizeof(Dog)<<endl;

    return 0;
}

