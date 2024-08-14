#include "quest6.h"
#include "ui_quest6.h"

quest6::quest6(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::quest6)
{
    ui->setupUi(this);
    ui->spinBox->setRange(0,100);
    ui->verticalSlider->setRange(0,100);
}

quest6::~quest6()
{
    delete ui;
}

void quest6::on_spinBox_valueChanged(int value)
{
    //ui->spinBox->setValue(value);
    ui->verticalSlider->setValue(value);
}

void quest6::on_verticalSlider_valueChanged(int value)
{
    ui->spinBox->setValue(value);
    //ui->verticalSlider->setValue(value);
}
