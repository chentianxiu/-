#include "dairy4.h"
#include "ui_dairy4.h"

dairy4::dairy4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dairy4)
{
    ui->setupUi(this);
}

dairy4::~dairy4()
{
    delete ui;
}

void dairy4::on_pushButton_2_clicked()
{
    QApplication::quit();
}

void dairy4::on_pushButton_clicked()
{
    ui->calendarWidget->showToday();
}
