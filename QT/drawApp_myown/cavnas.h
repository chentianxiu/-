#ifndef CAVNAS_H
#define CAVNAS_H

#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPixmap>
#include "paintmethod.h"

namespace Ui {
class Cavnas;
}

class Cavnas : public QWidget
{
    Q_OBJECT

public:
    explicit Cavnas(QWidget *parent = nullptr);
    ~Cavnas();
protected:
    //设置各种事件，都是有用到的
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;

private:
    Ui::Cavnas *ui;
    QPainter painter; //画家
    QPixmap history;  //历史记录
    //paintMethod* paintmethod = nullptr; //绘图方法
    //enum paintType currentType = PencilType; //工具类型 默认=铅笔
    QPen currentPen; //画笔

};

#endif // CAVNAS_H
