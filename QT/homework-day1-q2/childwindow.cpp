#include "childwindow.h"
#include "ui_childwindow.h"

childWindow::childWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::childWindow)
{
    ui->setupUi(this);
}

childWindow::~childWindow()
{
    delete ui;
}

void childWindow::on_pushButton_2_clicked()
{
    QApplication::quit();
}

void childWindow::on_pushButton_clicked()
{
    this->hide();
    emit this->logout();
}
