#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
    //delete textBox;
}

//按下鼠标
void Widget::mousePressEvent(QMouseEvent *)
{

        ui->textBrowser->setText("B");

}

//松开鼠标
void Widget::mouseReleaseEvent(QMouseEvent *)
{

        ui->textBrowser->setText("C");

}

