#include<iostream>
using namespace std;
#include<deque>

void printDeque(const deque<int> & d){
   // d[0] = 20;
    for(deque<int>::const_iterator it= d.begin();it!=d.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

//deque构造
void test01() {

	deque<int> d1;

    for(int i=0;i<10;i++){
        d1.push_back(i);
    }

    printDeque(d1);

    deque<int> d2(d1.begin()+1,d1.end()-1) ;
    printDeque(d2);

    deque<int> d3(10,1000);
    printDeque(d3);

    deque<int> d4(d3);
     printDeque(d4);

	
}



int main(){

    test01();
    return 0;
}