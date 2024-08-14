#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->calendarWidget->setVisible(false);  // 初始时隐藏
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_2_clicked()
{
    //QApplication::quit();
    this->close();
}

void Widget::on_pushButton_clicked()
{
    //ui->calendarWidget->setVisible(!ui->calendarWidget->isVisible());
    ui->calendarWidget->show();

}
