#ifndef PAINTMETHOD_H
#define PAINTMETHOD_H

#include <QPainter>
#include <QPoint>
#include <QPainterPath>
#include <QPen>

//绘图方式的抽象类
class paintMethod
{
public:
    paintMethod(QPen pen,QPoint start):start(start),pen(pen){}
    virtual ~paintMethod(){}

    QPoint start; // 起点(左上角)
    QPoint end; //终点(右下角)
    QPen pen; //画笔
    virtual void draw(QPainter* painter) = 0;
    virtual void addPoint(QPoint pos);
};


//直线绘图类
class paintLine : public paintMethod
{
public:
    paintLine(QPen pen,QPoint start):paintMethod(pen,start){}
    virtual ~paintLine(){}
    virtual void draw(QPainter* painter) override;
};


//矩形绘图类
class paintRect : public paintMethod
{
public:
    paintRect(QPen pen,QPoint start):paintMethod(pen,start){}
    virtual ~paintRect(){}
    virtual void draw(QPainter* painter) override;
};


//椭圆形绘图类
class paintEllipse : public paintMethod
{
public:
    paintEllipse(QPen pen,QPoint start):paintMethod(pen,start){}
    virtual ~paintEllipse(){}
    virtual void draw(QPainter* painter) override;
};


//铅笔绘图类
class pencilPaint : public paintMethod
{
public:
    pencilPaint(QPen pen,QPoint start):paintMethod(pen,start){ways.moveTo(start);}
    virtual ~pencilPaint(){}
    QPainterPath ways; //绘图路径
    virtual void addPoint(QPoint pos) override;
    virtual void draw(QPainter* painter) override;
};

#endif // PAINTMETHOD_H
