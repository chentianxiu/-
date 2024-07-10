#include <iostream>
using namespace std;

class Buliding{

//类做友元
friend class goodFriend;

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

//类做友元
class goodFriend{
public:
    void visit(Buliding * buliding){
       cout<<"好基友访问："<<buliding->m_SittingRoom<<endl;
        cout<<"好基友访问："<<buliding->m_BedRoom<<endl;
    }

};


int main() {
   
    goodFriend gf;

    Buliding b;

    gf.visit(&b);
   
    return 0;
}



