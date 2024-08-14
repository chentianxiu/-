#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>

void printDeque(const deque<int>& d) 
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";

	}
	cout << endl;
}

void test01()
{
    deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(200);
	d.push_front(300);
	d.push_front(250);
	d.push_front(100);
	d.push_front(200);

	printDeque(d);

	//排序

	sort(d.begin()+1,d.end()-1);//默认从小打到排序

	// 怎么从大到小排序？

	printDeque(d);

	sort(d.rbegin(), d.rend());//从大到小排序
	printDeque(d);

	
}



int main(){

    test01();
    return 0;
}