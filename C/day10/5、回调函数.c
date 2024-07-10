#include <stdio.h>

//定义回调函数
typedef void (*CookingCallback)(int);

//松鼠桂鱼具体实现
void songshuguiyu(int time){
    printf("做松鼠桂鱼的具体步骤\n");
}

//这是一个接受回调函数作为参数的函数
void cooking(CookingCallback callback,int time){
    printf("起锅烧油\n");
    //调用回调函数
    callback(time);
    printf("大火收汁\n");
}


int main()
{
    printf("开始做饭\n");
    printf("做松鼠桂鱼\n");
    int time = 10;
    cooking(songshuguiyu,time);
    printf("开饭了\n");


    return 0;
    
}