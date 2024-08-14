#include "widget.h"
#include "ui_widget.h"
#include "dbcontrol.h"
#include <QDebug>
#include <QList>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList list = dbControl::getInstance()->showTables();
    ui->tableShow_LW->addItems(list);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_exec_PB_clicked()
{
    QString cmd = ui->cmdLine_LE->text();
    if(cmd.isEmpty())
    {
        return;
    }
    QString ret = dbControl::getInstance()->executeCmd(cmd);
    ui->resShow_PTE->appendPlainText(ret);
    updateTableInfo();
}

void Widget::on_tableShow_LW_itemClicked(QListWidgetItem *item)
{
    QString databaseName = item->text(); //数据库名称
    getTableInfo(databaseName);

}

void Widget::updateTableInfo()
{
    int row = ui->tableShow_LW->currentRow();
    QString currentTable;
    if(row>=0)
    {
        currentTable = ui->tableShow_LW->item(row)->text();//将之前选择的表名保存起来
    }
    ui->tableShow_LW->clear();
    QStringList list = dbControl::getInstance()->showTables();
    ui->tableShow_LW->addItems(list);
    if(!currentTable.isEmpty())
    {

        int row = ui->tableShow_LW->row(ui->tableShow_LW->findItems(currentTable,0).first());//找到与之前选中的（currentTable）表名相同的table的第一个（虽然数据库的表头不能相同）
        ui->tableShow_LW->setCurrentRow(row);
        getTableInfo(currentTable);
    }
}

void Widget::getTableInfo(QString tables)
{
    QList<QStringList> ret = dbControl::getInstance()->SelectTableAll(tables);
    qDebug()<<ret;

    ui->dataShow_TW->clear();
    ui->dataShow_TW->setColumnCount(0);
    ui->dataShow_TW->setRowCount(0);
    ui->dataShow_TW->setColumnCount(ret.first().count());
    ui->dataShow_TW->setHorizontalHeaderLabels(ret.first());//展示第一行表头
    ret.removeFirst();
    int i=0;
    for(auto it : ret)
    {
        ui->dataShow_TW->insertRow(i);
        int j = 0;
        for(auto s : it)
        {
            ui->dataShow_TW->setItem(i,j,new QTableWidgetItem(s));
            j++;
        }
        i++;
    }
}
