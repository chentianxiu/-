#include "quest5.h"
#include "ui_quest5.h"
#include <QDateTime>

quest5::quest5(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::quest5)
{
    ui->setupUi(this);
}

quest5::~quest5()
{
    delete ui;
}

void quest5::on_pushButton_clicked()
{
    QString currentTime=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

    ui->label->setText("Current Time: " + currentTime);
}
