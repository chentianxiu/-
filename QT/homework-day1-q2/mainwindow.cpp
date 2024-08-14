#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cw_p = new childWindow;//生成第二个窗口

    //接收到信号
    connect(cw_p,&childWindow::logout,this,&MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete cw_p;
}


void MainWindow::on_pushButton_2_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_clicked()
{
    cw_p->show();
    this->hide();
}
