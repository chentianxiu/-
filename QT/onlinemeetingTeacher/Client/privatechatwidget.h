#ifndef PRIVATECHATWIDGET_H
#define PRIVATECHATWIDGET_H

#include <QWidget>

namespace Ui {
class privateChatWidget;
}

class privateChatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit privateChatWidget(QString friendName,QWidget *parent = nullptr);
    ~privateChatWidget();

    void addNewMsg(QString message);

signals:
    void sendMsg(QString recver,QString msg);
    void uploadFile(QString recver,QString filepath,QString filename);

private slots:
    void on_send_PB_clicked();

    void on_uploadFile_PB_clicked();

private:
    Ui::privateChatWidget *ui;
    QString friendName;
};

#endif // PRIVATECHATWIDGET_H
