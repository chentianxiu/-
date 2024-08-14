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
    vector<int> v2;
   for(int i=5;i>0;i--){
        v2.push_back(i);
   }
   printVector(v2);

   //交换
   v1.swap(v2);

  cout<<"交换后："<<endl;
   printVector(v1);
   printVector(v2);
}

void test02(){

	vector<int> v;
	for(int i=0;i<10000;i++){
		v.push_back(i);
	}

	cout<<"v的容量："<<v.capacity()<<endl;//16384
	cout<<"v的元素个数："<<v.size()<<endl;//10000

	//重新指定元素个数
	v.resize(3);
	cout<<"v的容量："<<v.capacity()<<endl;//16384
	cout<<"v的元素个数："<<v.size()<<endl;//3

	//收缩内存  交换

	vector<int>(v).swap(v);  //vector<int>(v):匿名对象(重新创建一个新的v,将原来的v赋值过来,大小就改变了)

	cout<<"v的容量："<<v.capacity()<<endl;//
	cout<<"v的元素个数："<<v.size()<<endl;//3


}




int main(){

   //test01();
   test02();

   
    return 0;
}