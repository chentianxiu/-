#include<iostream>
using namespace std;
#include <list>


void printList(const list<int>& L) {

	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//插入和删除
void test01()
{
		list<int> l;

		//尾插
		l.push_back(10);
		l.push_back(20);
		l.push_back(30);
		//头插
		l.push_front(100);
		l.push_front(200);
		l.push_front(300);

		printList(l);// 300 200 100  10 20 30 

		//尾删
		l.pop_back();
		l.pop_back();
		printList(l);// 300 200 100  10 

		//头删
		l.pop_front();
		printList(l);//  200 100  10 

		//插入
		l.insert(l.begin(),1000);
		printList(l);// 1000 200 100 10  

		list<int>::iterator it = l.begin();
		l.insert(++it,500);
		printList(l);// 1000 500 200 100 10

		//删除
		it = l.begin();
		l.erase(++it);
		printList(l);//  500 200 100 10

		l.push_back(100);
		l.push_back(100);
		printList(l);//  500 200 100 10 100  100

		l.remove(100);
		printList(l);

		l.clear();
		printList(l);




	

}


int main(){

    test01();
    return 0;
}