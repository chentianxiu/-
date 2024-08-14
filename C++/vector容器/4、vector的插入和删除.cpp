#include<iostream>
using namespace std;
#include<vector>

void printVector(vector<int>& v) {

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//插入和删除
void test01()
{
	vector<int> v1;
	//尾部插入
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	printVector(v1);
	//尾删
	v1.pop_back();
	v1.pop_back();
	printVector(v1);

	//插入
	v1.insert(v1.begin(),100);
	printVector(v1);// 100 10 20 30   

	v1.insert(v1.begin(),3,1);
	printVector(v1);//1 1 1 100 10 20 30 

	//删除
	v1.erase(v1.begin());
	printVector(v1);

	//v1.erase(v1.begin()+1,v1.end()-1);
	v1.erase(v1.end()-1,v1.end());
	printVector(v1);

	//清空
	v1.clear();
	printVector(v1);
	
}



int main(){

    test01();
    return 0;
}