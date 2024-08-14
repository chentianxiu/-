#include<iostream>
using namespace std;
#include <list>

void printList(const list<int>& L) {

	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

bool myCompare(int val1,int val2){
	//从大到小
	return val1 > val2;
}

void test01() {

	list<int> l;

    l.push_back(10);
    l.push_back(40);
    l.push_back(20);
    l.push_back(30);
	printList(l);

	//反转
	l.reverse();
	printList(l);

	//排序
	l.sort();//从小到大
	printList(l);//10 20 30 40 

	//一个函数实现从大到小：制定一个排序规则的函数
	l.sort(myCompare);
	printList(l);//40 30 20 10 






	
}




int main(){

    test01();
    return 0;
}