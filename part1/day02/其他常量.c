#include<stdio.h>

#define PI 3.141592
enum Season{Spring,Summer,Autumn,Winter};



int main(){
    printf("�궨�峣��%f\n",PI);//������
    const int a=20;
    //a=10;���bug��a�����޸�
    printf("ö�ټ���%d\n",Spring);
    printf("ö�ټ���%d\n",Summer);
    printf("ö�ټ���%d\n",Autumn);
    printf("ö�ټ���%d\n",Winter);
    return 0;
}