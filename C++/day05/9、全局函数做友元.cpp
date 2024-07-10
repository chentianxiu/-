#include <iostream>
using namespace std;

class Buliding{

//告诉编译器，googFriend函数是友元函数，可以访问私有化的内容
friend void googFriend(Buliding * buliding);
friend void googFriend(Buliding & buliding);

public:
    string m_SittingRoom;//客厅
private:
    string m_BedRoom;//卧室

public:
    Buliding(){
        this->m_SittingRoom = "客厅";
        this->m_BedRoom = "卧室";
    }

};

//全局函数做友元(类外)
//地址
void googFriend(Buliding * buliding){
    cout<<"好基友访问："<<buliding->m_SittingRoom<<endl;
    cout<<"好基友访问："<<buliding->m_BedRoom<<endl;
}
//引用
void googFriend(Buliding & buliding){
    cout<<"好基友访问："<<buliding.m_SittingRoom<<endl;
    cout<<"好基友访问："<<buliding.m_BedRoom<<endl;
}


int main() {
   
   //创建房间
   Buliding b;

   googFriend(&b);
   googFriend(b);

   
    return 0;
}



