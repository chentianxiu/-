#include<stdio.h>

#define PI 3.141592
enum Season{Spring,Summer,Autumn,Winter};



int main(){
    printf("宏定义常量%f\n",PI);//常变量
    const int a=20;
    //a=10;会出bug，a不可修改
    printf("枚举季节%d\n",Spring);
    printf("枚举季节%d\n",Summer);
    printf("枚举季节%d\n",Autumn);
    printf("枚举季节%d\n",Winter);
    return 0;
}