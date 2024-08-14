#include<iostream>
using namespace std;
#include <list>

void printList(const list<int>& L) {

	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01() {

	list<int> l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);

	printList(l1);

	cout<<"元素个数："<<l1.size()<<endl;

	if(l1.empty()){
		cout<<"为空"<<endl;
	}else{
		cout<<"不为空"<<endl;
	}

	//重新定义长度
	l1.resize(10,20);
	printList(l1);

	l1.resize(15);
	printList(l1);
	
}




int main(){

    test01();
    return 0;
}