#include<iostream>
using namespace std;
#include<deque>

void printDeque(const deque<int>& d) 
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";

	}
	cout << endl;
}
//两端操作
void test01()
{

	deque<int> d;
	//尾插
	d.push_back(10);
	d.push_back(20);
	//头插
	d.push_front(100);
	d.push_front(200);
	printDeque(d); //200 100 10 20

	//尾删
	d.pop_back();
	printDeque(d);
	//头删
	d.pop_front();
	printDeque(d);
}

void test02(){

	deque<int> d;
	//尾插
	d.push_back(10);
	d.push_back(20);
	//头插
	d.push_front(100);
	d.push_front(200);
	printDeque(d); //200 100 10 20

	d.insert(d.begin(),300);
	printDeque(d);//300 200 100 10 20 

	d.insert(d.begin()+1,3,500);
	printDeque(d);//300 500 500 500  200 100 10 20 

	deque<int> d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);

	d.insert(d.begin(),d2.begin(),d2.end());
	printDeque(d);//1 2 3 300 500 500 500 200 100 10 20 

	d.erase(d.begin());
	printDeque(d);

	d.erase(d.begin(),d.end()-2);
	printDeque(d);

	d.clear();
	printDeque(d);
}


int main() {

	//test01();
	test02();

    return 0;
}