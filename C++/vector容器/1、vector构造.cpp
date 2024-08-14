#include<iostream>
using namespace std;
#include<vector>

void printVector(vector<int> & v){

    for(vector<int>::iterator it = v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

}

//构造
void test01()
{
	
    vector<int> v1;
    //赋值
    for(int i=0;i<10;i++){
        v1.push_back(i);
    }

    //打印
    printVector(v1);

    vector<int> v2(v1.begin()+1,v1.end()-1);////将v[begin(), end())区间中的元素拷⻉给本身。
     printVector(v2);

    vector<int> v3;
    v3 = v2;
    printVector(v3);

    vector<int> v4(10,1000);//放10个1000 //构造函数将n个elem拷⻉给本身。
    printVector(v4);

    vector<int> v5(v4);//拷贝构造函数
    printVector(v5);
    
    

}



int main(){

    test01();
    return 0;
}