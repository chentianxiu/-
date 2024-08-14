#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket> //tcp套接字
#include <QTcpServer> //tcp服务器
#include <QHostAddress>

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
    void onNewConnection();
    void onReadyRead();
    void onDisconnect();

private:
    Ui::Widget *ui;
    QTcpServer * server;
    QTcpSocket * socket;
};
#endif // WIDGET_H
