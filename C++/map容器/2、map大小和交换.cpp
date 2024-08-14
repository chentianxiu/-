#include<iostream>
using namespace std;
#include <map>

void printMap(map<int,int>&m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}

void test01() {

	 map<int,int> m;

    // 1、自动排序     2、key不重复，value不管
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(3,30));
    m.insert(pair<int,int>(4,40));
    m.insert(pair<int,int>(2,20));

	printMap(m);

	if(m.empty()){
		cout<<"空"<<endl;
	}else{
		cout<<"不空"<<endl;
		cout<<"size："<<m.size()<<endl;
	}

	 map<int,int> m2;

    // 1、自动排序     2、key不重复，value不管
    m2.insert(pair<int,int>(10,1));
    m2.insert(pair<int,int>(30,3));
    m2.insert(pair<int,int>(40,4));
    m2.insert(pair<int,int>(20,2));
	m2.insert(pair<int,int>(50,5));
	printMap(m2);

	cout<<"交换"<<endl;
	m.swap(m2);
	printMap(m);
	printMap(m2);


}



int main(){

    test01();
    return 0;
}