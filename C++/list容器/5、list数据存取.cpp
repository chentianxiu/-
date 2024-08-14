#include<iostream>
using namespace std;
#include <list>



void test01() {

	list<int> l;

    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);

    cout<<"头元素："<<l.front()<<endl;
    cout<<"尾元素："<<l.back()<<endl;

    //遍历，，
    list<int>::iterator it = l.begin();
     //it = it+1;

     for(list<int>::iterator it = l.begin();it!=l.end();it++){
        cout<<*it<<endl;
     }

   

	
}




int main(){

    test01();
    return 0;
}