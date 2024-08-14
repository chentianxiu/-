#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <servermananger.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    ServerMananger * server;
    QString address;
    quint16 port;

    void loadConfigure();
};
#endif // WIDGET_H
