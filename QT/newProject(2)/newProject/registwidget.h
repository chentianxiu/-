#ifndef REGISTWIDGET_H
#define REGISTWIDGET_H

#include <QWidget>

namespace Ui {
class registWidget;
}

class registWidget : public QWidget
{
    Q_OBJECT

public:
    explicit registWidget(QWidget *parent = nullptr);
    ~registWidget();

signals:
    void userRegisted(QString name,QString pswd);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::registWidget *ui;

    void clearInfo();
};

#endif // REGISTWIDGET_H
