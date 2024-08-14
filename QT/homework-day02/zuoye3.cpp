#include "zuoye3.h"
#include "ui_zuoye3.h"

zuoye3::zuoye3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zuoye3),
    positionLabel(this)
{
    ui->setupUi(this);


    positionLabel.setText("Mouse Position: (0, 0)");
    positionLabel.setAlignment(Qt::AlignLeft | Qt::AlignTop);
    positionLabel.show();
    // 启用鼠标跟踪
    this->setMouseTracking(true);
}

zuoye3::~zuoye3()
{
    delete ui;
}


void zuoye3::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    QString positionText = QString("(%1, %2)").arg(x).arg(y);

    //设置label的显示
    positionLabel.setText(positionText);

    // 自动调整 label 大小以适应内容
    positionLabel.adjustSize();
    //设置label的位置
    positionLabel.move(x-10,y-10);
}
