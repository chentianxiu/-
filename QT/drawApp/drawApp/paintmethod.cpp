#include "paintmethod.h"


//绘画方式

void paintLine::draw(QPainter *painter) //直线
{
    painter->setPen(pen);
    painter->drawLine(start,end);
}

void paintRect::draw(QPainter *painter) //矩形
{
    painter->setPen(pen);
    QRect rect(start,end);
    painter->drawRect(rect);
}

void paintEllipse::draw(QPainter *painter) //椭圆形
{
    painter->setPen(pen);
    QRect rect(start,end);
    painter->drawEllipse(rect);
}

void pencilPaint::addPoint(QPoint pos) //铅笔添加新节点
{
    ways.lineTo(pos); //添加直线节点
}

void pencilPaint::draw(QPainter *painter) //铅笔
{
    painter->setPen(pen);
    painter->drawPath(ways);
}

void paintMethod::addPoint(QPoint pos) //添加终点
{
    end = pos;
}
