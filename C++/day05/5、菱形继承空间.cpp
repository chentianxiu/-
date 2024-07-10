#include <iostream>

using namespace std;

class Animal{
public:
    int m_Age;
};

class Sheep :public Animal{};

class Tuo :public Animal{};

class SheepTuo :public Sheep,public Tuo{};


int main(){
    
    cout<<"Animal内存大小:"<<sizeof(Tuo)<<endl;
    cout<<"羊内存大小:"<<sizeof(Sheep)<<endl;
    cout<<"坨内存大小:"<<sizeof(Tuo)<<endl;
    cout<<"羊驼内存大小:"<<sizeof(SheepTuo)<<endl;

    return 0;
}


