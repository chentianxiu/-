#include<iostream>

using namespace std;

//第一:父类：纯虚函数(抽象类)，规定四个制作步骤
class AbstractDrinking{

public:
    //1、煮水
    virtual void Boil()= 0;
    //2、冲泡
    virtual void Brew()= 0;
    //3、倒入杯中
    virtual void PourInCup()= 0;
    //4、加辅料
    virtual void PutSomeThing()= 0;

    //整合流程
    void MakeDrinking(){
        Boil();
        Brew();
        PourInCup();
        PutSomeThing();
    }
};


//第二：子类：实现（重写）四个步骤，n个子类
class Coffer:public AbstractDrinking{
public:
    //1、煮水
    virtual void Boil(){
        cout<<"煮农夫山泉"<<endl;
    }
    //2、冲泡
    virtual void Brew(){
        cout<<"冲雀巢咖啡"<<endl;
    }
    //3、倒入杯中
    virtual void PourInCup(){
        cout<<"倒入咖啡杯中"<<endl;
    }
    //4、加辅料
    virtual void PutSomeThing(){
        cout<<"加糖、加奶"<<endl;
    }
};

//第二：子类：实现（重写）四个步骤，n个子类
class Tea:public AbstractDrinking{
public:
    //1、煮水
    virtual void Boil(){
        cout<<"煮哇哈哈纯净水"<<endl;
    }
    //2、冲泡
    virtual void Brew(){
        cout<<"冲菊花茶"<<endl;
    }
    //3、倒入杯中
    virtual void PourInCup(){
        cout<<"倒入茶杯中"<<endl;
    }
    //4、加辅料
    virtual void PutSomeThing(){
        cout<<"加枸杞"<<endl;
    }
};

//第三：定义一个函数，实现制作饮品的功能
void DoWork(AbstractDrinking * drink){
    //调用制作饮品的流程
    drink->MakeDrinking();
    delete drink;
}

//第三：定义一个函数，实现制作饮品的功能
void DoWork(AbstractDrinking & drink){
    //调用制作饮品的流程
    drink.MakeDrinking();
    //delete drink;
}

//第四：调用制作饮品的功能（main中）
int main(){

	//咖啡,使用匿名，只使用一次
    DoWork(new Coffer);

    cout<<"========"<<endl;

    Coffer c;
    DoWork(c);

    cout<<"========"<<endl;

    //菊花茶
    DoWork(new Tea);
	
    return 0;
}

