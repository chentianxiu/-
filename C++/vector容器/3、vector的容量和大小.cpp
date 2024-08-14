#include<iostream>
using namespace std;
#include<vector>

void printVector(vector<int>& v) {

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	vector<int> v1;
	for(int i=0;i<10;i++){
		v1.push_back(i);
	}
	printVector(v1);

	if(v1.empty()){
		cout<<"V1是空的"<<endl;
	}else{
		cout<<"V1不是空的"<<endl;
		cout<<"容器的容量："<<v1.capacity()<<endl;//10个元素加6个预留空间
		cout<<"容器元素个数："<<v1.size()<<endl;
	}

	

	//重新指定容器长度为num，若容器变长，以默认值填充；如果缩短，则超出长度的被删除
	v1.resize(5);
	printVector(v1);

	//重新指定容器长度为num，若容器变长，以10填充；如果缩短，则超出长度的被删除
	v1.resize(15,10);//15个元素
	printVector(v1);

    
	
}



int main(){

    test01();
    return 0;
}