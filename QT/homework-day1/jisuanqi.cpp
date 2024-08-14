#include "jisuanqi.h"
#include "ui_jisuanqi.h"

jisuanqi::jisuanqi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::jisuanqi)
{
    ui->setupUi(this);
}

jisuanqi::~jisuanqi()
{
    delete ui;
}
