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

	list<int> l2;
	l2 = l1;
	printList(l2);

	list<int> l3;
	l3.assign(l2.begin(),l2.end());
	printList(l3);

	list<int> l4(10,1000);
	printList(l4);

	//交换
	cout<<"交换后："<<endl;
	l1.swap(l4);
	printList(l1);
	printList(l4);




	
}




int main(){

    test01();
    return 0;
}