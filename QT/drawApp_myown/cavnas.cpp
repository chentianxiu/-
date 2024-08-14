#include "cavnas.h"
#include "ui_cavnas.h"

Cavnas::Cavnas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cavnas)
{
    ui->setupUi(this);
}

Cavnas::~Cavnas()
{
    delete ui;
}

void Cavnas::paintEvent(QPaintEvent *event)
{
    painter.begin(this);//开始绘图

    painter.fillRect(this->rect(),Qt::white);//填充画布颜色

    painter.drawPixmap(this->rect(),history);//填充历史记录图片

    //判断会话方式是否设置



    painter.end();//结束绘图

}

void Cavnas::mousePressEvent(QMouseEvent *event)
{

}

void Cavnas::mouseMoveEvent(QMouseEvent *event)
{

}

void Cavnas::mouseReleaseEvent(QMouseEvent *event)
{
    history = this->grab(this->rect()); //将画笔截图缓存为历史记录
}
