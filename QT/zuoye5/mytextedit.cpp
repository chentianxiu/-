#include "mytextedit.h"


myTextEdit::myTextEdit(QWidget *parent):QTextEdit(parent)
{
    this->setText("Hello,World"); //设置文本
    this->setAlignment(Qt::AlignCenter); //设置文本对齐 居中对齐
    this->setReadOnly(true); //设置为只读
    this->setFocusPolicy(Qt::NoFocus); //设置焦点策略 无焦点
}

bool myTextEdit::eventFilter(QObject *, QEvent *event)
{
    int type = event->type(); //获取事件类型

    if(type == QEvent::KeyPress) //键盘按下事件
    {
        QKeyEvent* keyEvent = dynamic_cast<QKeyEvent*>(event); //事件类型转换->键盘事件
        keyMove(keyEvent->key());
    }
    else if(type == QEvent::Wheel) //鼠标滚轮事件
    {
        QWheelEvent* wheelEvent = dynamic_cast<QWheelEvent*>(event); //事件类型转换->滚轮
        wheelFont(wheelEvent->delta());
    }
    else
    {
        return false;
    }
    return true;
}

void myTextEdit::keyMove(int key)
{
    QPoint pos(0,0);
    switch(key)
    {
    case Qt::Key_W:
        pos = QPoint(0,-10);  //上
        break;
    case Qt::Key_A:
        pos = QPoint(-10,0); //左
        break;
    case Qt::Key_S:
        pos = QPoint(0,10);  //下
        break;
    case Qt::Key_D:
        pos = QPoint(10,0);  //右
        break;
    default:
        break;
    }
    emit keyPressed(pos);//发送信号给主界面
}

void myTextEdit::wheelFont(int delta)//鼠标滚轮控制字体
{
    QFont currentFont = this->font(); //获取当前使用的字体

    //设置变化值
    int value = 1;
    if(delta<0)
    {
        value *= -1;
    }

    //设置新字体的大小
    QFont newFont(currentFont);
    newFont.setPointSize(currentFont.pointSize()+value);

    //应用新字体
    this->setFont(newFont);
}
