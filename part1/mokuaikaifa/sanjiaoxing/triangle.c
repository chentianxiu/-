#include<stdio.h>
#include "trangle.h"

Triangle tinput(Triangle triangle){
    //Triangle triangle;
    int flag = 1;
    while (flag ==1)
    {
    printf("请输入三角形的三个边\n");
    scanf("%f%f%f",&triangle.x,&triangle.y,&triangle.z);
    if (!(triangle.x+triangle.y>triangle.z)&&(triangle.x+triangle.z>triangle.y)&&(triangle.y+triangle.z>triangle.x))
    {
        printf("三角形不成立，请重新输入三边\n");

    }else{
        printf("输入成功\n");
        flag = 0;
    }
    //return triangle;
    }
    return triangle;
}


void toutput(Triangle triangle){
    printf("三角形的三边为%.2f %.2f %.2f ",triangle.x,triangle.y,triangle.z);
}

