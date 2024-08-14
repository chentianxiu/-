#include<iostream>
using namespace std;

class MyAdd{

public:
    int operator()(int v1,int v2){
        return v1+v2;
    }
};



void test01() {

    //创建一个对象  MyAdd
    MyAdd myAdd;
    cout<<myAdd(10,15)<<endl;//25
	
}

class MyPrint{

public:
    int count ;
    //构造函数
    MyPrint(){
        count = 0;
    }
     void operator()(string test){
        cout<<test<<endl;
        count++;
     }
};

void test02(){
    //创建对象
    MyPrint myPrint;
    myPrint("Hello World");
    myPrint("Hello World");
    myPrint("Hello World");
    cout<<"myPrint调用的次数："<<myPrint.count<<endl;

}

void doPrint(MyPrint & mp,string test){
    mp(test);
};

void test03(){
    MyPrint myPrint;
    doPrint(myPrint,"Hello C++");
}



int main(){

   // test01();
    // test02();
    test03();
    return 0;
}