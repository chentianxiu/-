#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QWidget>

namespace Ui {
class UserWidget;
}

class UserWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UserWidget(QWidget *parent = nullptr);
    ~UserWidget();

signals:
    void logout();

private slots:
    void on_pushButton_clicked();

private:
    Ui::UserWidget *ui;
};

#endif // USERWIDGET_H
