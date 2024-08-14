#ifndef REGISTWIDGET_H
#define REGISTWIDGET_H

#include <QWidget>

namespace Ui {
class registwidget;
}

class registwidget : public QWidget
{
    Q_OBJECT

public:
    explicit registwidget(QWidget *parent = nullptr);
    ~registwidget();

signals:
    void userRegisted(QString name,QString pswd);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::registwidget *ui;

    void clearInfo();
};

#endif // REGISTWIDGET_H
