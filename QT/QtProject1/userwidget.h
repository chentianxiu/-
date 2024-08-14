#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QWidget>

namespace Ui {
class userwidget;
}

class userwidget : public QWidget
{
    Q_OBJECT

public:
    explicit userwidget(QWidget *parent = nullptr);
    ~userwidget();

signals:
    void logout();

private slots:
    void on_pushButton_clicked();

private:
    Ui::userwidget *ui;
};

#endif // USERWIDGET_H
