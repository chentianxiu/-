#include<iostream>
using namespace std;
#include <set>


//仿函数：其实就是一个类
//规则：从大到小
class MyCompare{

public:
    bool operator()(int v1,int v2){
        return v1>v2;//从大到小
    }

};

void printset(set<int,MyCompare> & s){
    for(set<int>::iterator it = s.begin();it!=s.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}


void test01() {
	
    set<int> s1;

	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
    s1.insert(50);

    //默认是从小到大
    for(set<int>::iterator it = s1.begin();it!=s1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    //指定从大到小的规则
    set<int,MyCompare> s2;

    s2.insert(10);
	s2.insert(40);
	s2.insert(20);
	s2.insert(30);
    s2.insert(50);

    for(set<int>::iterator it = s2.begin();it!=s2.end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    printset(s2);
}




int main(){

    test01();
    return 0;
}