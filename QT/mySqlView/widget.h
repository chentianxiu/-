#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QListWidgetItem>
#include <QTableWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_exec_PB_clicked();

    void on_tableShow_LW_itemClicked(QListWidgetItem *item);

private:
    Ui::Widget *ui;
    void updateTableInfo();
    void getTableInfo(QString tables);
};
#endif // WIDGET_H
