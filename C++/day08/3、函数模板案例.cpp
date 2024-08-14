#include<iostream>

using namespace std;


//函数模版    
template<class T>  //把数据类型当成一个参数进行传递
void mySwap(T & a,T & b){
    T temp = a;
    a = b;
    b = temp;
}


//排序
template<class T>
void mySort(T arr[],int len){

    //选择排序
    for(int i =0;i<len;i++){
        //选中一个认为是最大值的索引
        int max = i;
        //arr[i]与后面的数据进行比较
        for(int j = i+1;j<len;j++){
            //从小到大 
            if(arr[max] < arr[j]){
                //max索引重新赋值为j
                max = j;
            }
        }

        //内层循环结束，看看最大数据的索引i是否改变
        if(max !=i){//交换
            mySwap(arr[max],arr[i]);
        }
    }
}

//打印出来
template<class T>
void print(T arr[],int len){
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main(){

   //char类型
   char charArr[] = "abcdefg";//ASCLL表进行排序

   int len1 = sizeof(charArr);

   mySort(charArr,len1);

   print(charArr,len1);

   //int 数组
   int intArr[] = {2,3,5,6,2,3,6,4,2,54,7,5};
   int len2 = sizeof(intArr)/sizeof(intArr[0]);

   mySort(intArr,len2);

   print(intArr,len2);

    return 0;
}



