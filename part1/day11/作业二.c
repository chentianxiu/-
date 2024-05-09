//求平面直角坐标系中两点之间的距离，使用结构体和函数。
//提示：C语言中开根号使用<math.h>中的sqrt()函数，例如 sqrt(4)的值是2
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct point
{
    double x;//x坐标
    double y;//y坐标

}Point;

double Trangle(Point p1,Point p2){
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    double distance = sqrt(dx*dx+dy*dy);

    return distance;

}


int main()
{
    Point p1,p2;

    printf("请输入p1的x,y坐标\n");
    scanf("%lf%lf",&p1.x,&p1.y);


    printf("请输入p2的x,y坐标\n");
    scanf("%lf%lf",&p2.x,&p2.y);

    double distance  = 0;

    distance = Trangle(p1,p2);

    printf("两点之间的距离是:%.2f\n",distance);

    return 0;
    
}
