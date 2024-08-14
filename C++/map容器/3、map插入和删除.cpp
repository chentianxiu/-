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
	
	//四种方式插入
	map<int,int> m;

	//第一种插入
	m.insert(pair<int,int>(1,10));

	//第二种
	m.insert(make_pair(2,20));

	//第三种
	m.insert(map<int,int>::value_type(3,30));

	//第四种
	m[4] = 40;

	printMap(m);

	//删除
	m.erase(m.begin());
	printMap(m);

	m.erase(3);//key
	printMap(m);

	// m.erase(m.begin(),m.end());
	// printMap(m);

	m.clear();
	printMap(m);


	
}



int main(){

    test01();
    return 0;
}