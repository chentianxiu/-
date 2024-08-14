#include<iostream>
using namespace std;
#include <set>


void test01() {
	
	set<int> s1;

	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);

   set<int>::iterator pos =  s1.find(50);
   if(pos != s1.end()){
    cout<<"找到"<<*pos<<endl;
   }else{
    cout<<"没有找到"<<endl;
   }
    int num = s1.count(50);
    cout<<"num:"<<num<<endl;
	
}




int main(){

    test01();
    return 0;
}