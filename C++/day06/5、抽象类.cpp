#include<iostream>

using namespace std;

class Base{

public:
    //纯虚函数,此类是抽象类，不能实例化
    virtual void func()=0;
};

//子类
class Son :public Base{
public:
    //子类必须重写，否则子类也属于抽象类
    virtual void func(){
        cout<<"子类重写函数"<<endl;
    }

};

//使用引用调用多态方法
void callfunc(Base & base){
    base.func();
}

int main(){
    
	//创建Base
   // Base b;//抽象类，不能创建对象
   // new Base;

   //创建Son
   Son s1;
   s1.func();
   Son * s2 = new Son;
   s2->func();
   
   Base * s3 = new Son;//父类型指针或者引用指向子类对象
   s3->func();

   Base& s4 = s1;
   s4.func();

   //通过函数调用
   callfunc(s1);

    return 0;
}

