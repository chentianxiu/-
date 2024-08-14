#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QFileInfo>
#include <QDebug>
#include "loadfilethread.h"



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->progressBar->hide(); //进度条隐藏
    ui->progressBar->setValue(0);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,"选择加载的文件"); //先获取文件路径
    QFileInfo info(filePath); //获取文件信息
    if(info.isFile()) //如果是文件
    {
        ui->textBrowser->clear();
        ui->label->setText(info.baseName()); //设置文件名
        ui->progressBar->setMaximum(info.size()); //设置进度条最大值
        ui->progressBar->show(); //显示进度条


        //启动线程加载文件
        loadFileThread* thread = new loadFileThread(filePath,this);
        connect(thread,&loadFileThread::SndMsg,this,&Widget::RevMsg); //每次读取的信号
        connect(thread,&loadFileThread::finished,this,&Widget::onThreadEnd); //线程完成的信号
        thread->start(); //启动线程
    }
}

void Widget::RevMsg(QString line)
{
    int progress = ui->progressBar->value()+line.length(); //计算进度条位置
    ui->progressBar->setValue(progress); //设置进度条值
    ui->textBrowser->setText(ui->textBrowser->toPlainText() + line); //显示文本
}

void Widget::onThreadEnd()
{
    //关闭进度条显示
    ui->progressBar->hide();
    ui->progressBar->setValue(0);
}
