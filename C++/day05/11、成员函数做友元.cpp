#include <iostream>
using namespace std;

//声明
class Buliding;


class goodFriend{
public:
    void visit1(Buliding * buliding);//访问
    void visit2(Buliding * buliding);//不能访问
};

class Buliding{

//让  goodFriend中的visit1可以友元
friend void goodFriend:: visit1(Buliding * buliding);

public :
    string m_SittingRoom;//客厅
private :
    string m_BedRoom;//卧室
public:
    Buliding(){
        this->m_SittingRoom= "客厅";
        this->m_BedRoom = "卧室";
    }

};

 void goodFriend:: visit1(Buliding * buliding){
    cout<<"好基友访问："<<buliding->m_SittingRoom<<endl;
    cout<<"好基友访问："<<buliding->m_BedRoom<<endl;
 }

  void goodFriend:: visit2(Buliding * buliding){
    cout<<"好基友访问："<<buliding->m_SittingRoom<<endl;
    //cout<<"好基友访问："<<buliding->m_BedRoom<<endl;
 }


int main() {
   
    Buliding b;

    goodFriend gf;

    gf.visit1(&b);
    gf.visit2(&b);

   
    return 0;
}



