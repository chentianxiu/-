#ifndef REGIST_H
#define REGIST_H

#include <QWidget>

namespace Ui {
class regist;
}

class regist : public QWidget
{
    Q_OBJECT

public:
    explicit regist(QWidget *parent = nullptr);
    ~regist();

signals:
    void userRegist(QString name,QString pswd);

private slots:
    void on_regist_PB_clicked();

private:
    Ui::regist *ui;
};

#endif // REGIST_H
