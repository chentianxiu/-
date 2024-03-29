#include<stdio.h>
int main(){
    //浮点型
    float num1 = 3.1415f;
    short num2 = 20 ;
    long num3 = 30l ;
    double num4 = 13.14;
    
    printf("float类型:%0.4f\n",num1);
    printf("num2: %hd\n",num2);
    printf("num3: %ld\n",num3);
    printf("double类型:%.2lf\n",num4);



    return 0;
}