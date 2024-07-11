#include<stdio.h>
#include"trangle.h"

int main(){

    Triangle triangle;
    Triangle *ptr ;
    ptr = &triangle;

    tinput(ptr);
    toutput(ptr);
    return 0 ;
}